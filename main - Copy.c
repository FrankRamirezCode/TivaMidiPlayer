#include "TM4C123GH6PM.h"
#include "string.h"
#include "GPIO.h"
#include "PMOD_BTN_Interrupt.h"
#include "SysTick_Delay.h"
#include "PWM.h"
#include "midi.h"
#include "EduBase_LCD.h"

void PMOD_BTN_Handler(uint8_t pmod_btn_status);

//static volatile uint8_t switchPressed_ = 0;
static volatile uint8_t isPlaying_ = 0;
//static uint32_t lastSwitchTime_ = 0;
//static uint8_t currentTrackIndex = 0;
//static char* PLAY_STATUS = "Playing";
//static char* PAUSE_STATUS = "Paused ";
static volatile uint8_t lcd_needs_update = 0;

extern MidiFile_t midi_tune;

void UpdateLCDStatus(void);
	
typedef struct 
	{
    PWMModule pwmModule; 
    PWMChannel pwmChannel;
    const MidiTrack_t* track;
    uint8_t isPlaying;
    uint32_t lastNoteTime;
    int noteIndex;
	} TrackParams_t;

typedef struct 
	{
    PWMModule pwmModule; 
    PWMChannel pwmChannel;
    const MidiTrack_t* track;
    uint32_t currentNoteIndex;
    uint32_t lastNoteTime;
    uint8_t isTrackPlaying;
	} TrackState_t;

static TrackState_t trackStates_[4] = 
{
    { PWMModule0, PWM0_, NULL, 0, 0, 0 },    // PWM0_0 (PB6)
    { PWMModule0, PWM3,  NULL, 0, 0, 0 },    // PWM0_3 (PC4)
    { PWMModule1, PWM0_, NULL, 0, 0, 0 },    // PWM1_0 (PD0)
    { PWMModule1, PWM3,  NULL, 0, 0, 0 }     // PWM1_3 (PF2)
};


static void PlayNote(const MidiNoteEvent_t* note, PWMModule pwmModule, PWMChannel pwmChannel) 
{
    if (note->key == 0 || note->velocity == 0) 
    {
      PWM_Disable(pwmModule, pwmChannel);
    } 
    else 
    {
        uint16_t period = Midi_NotePwmPeriods[note->key];
        uint16_t duty = period / 2;  // 50% duty cycle for square wave
        
        // Update the specific PWM channel
        switch(pwmModule) 
					{
            case PWMModule0:
                if(pwmChannel == PWM0_) 
								{
                    PWM0_0_Init(period, duty);
                }
                else if(pwmChannel == PWM3) 
								{
                    PWM0_3_Init(period, duty);
                }
                break;
            case PWMModule1:
                if(pwmChannel == PWM0_) 
								{
                    PWM1_0_Init(period, duty);
                }
                else if(pwmChannel == PWM3) 
								{
                    PWM1_3_Init(period, duty);
                }
                break;
					}
    }
}


static void ProcessTracks(void) 
	{
    uint32_t currentTime = GetTick();
    
    for (int trackIdx = 0; trackIdx < midi_tune.numTracks; trackIdx++) 
			{
						TrackState_t* state = &trackStates_[trackIdx];
						
						if (!state->isTrackPlaying || !state->track) 
							{
								continue;
							}
						
						const MidiNoteEvent_t* notes = state->track->notes;
						const MidiNoteEvent_t* currentNote = &notes[state->currentNoteIndex];
						
						// Check if we've reached the end of the track
						if (currentNote->deltaTime == -1) 
							{
								state->isTrackPlaying = 0;
								PWM_Disable(state->pwmModule, state->pwmChannel);
								continue;
							}
						
						// Check if it's time to play the next note
						if (currentTime - state->lastNoteTime >= (currentNote->deltaTime * 1000)) //to microseconds
							{
								// Process the note
								uint8_t status = 0xF0 & currentNote->status;
								switch (status) 
									{
										case NOTE_ON:
												PlayNote(currentNote, state->pwmModule, state->pwmChannel);
												break;
												
										case NOTE_OFF:
										default:
												PWM_Disable(state->pwmModule, state->pwmChannel);
												break;
									}
								
								// Move to next note
								state->currentNoteIndex++;
								state->lastNoteTime = currentTime;
							}
			}
	}



int main ()
{
	RGB_LED_Init();
	PMOD_BTN_Interrupt_Init(&PMOD_BTN_Handler);
	SysTick_Delay_Init();
	PWM_Clock_Init();
	EduBase_LCD_Init();
	EduBase_LCD_Clear_Display();
  UpdateLCDStatus();
	uint16_t testPeriodG = 3189; // Middle G
	uint16_t testPeriodE = 3792;  // Middle E (D4)
	uint16_t testPeriodC = 4778;  // Middle C (C4)
  uint16_t testDuty = testPeriodC / 2;
	
	// Initialize the PWM channels
	PWM0_0_Init(testPeriodC, testDuty); 
	PWM0_3_Init(testPeriodE, 3792/2);
	PWM1_0_Init(testPeriodG, 3189/2);
	PWM1_3_Init(testPeriodG, 3189/2);
	
	
	
	for (int i = 0; i < midi_tune.numTracks && i < 4; i++) 
		{
        trackStates_[i].track = &midi_tune.tracks[i];
    }
	
	while(1)
	{
		ProcessTracks();
		if(lcd_needs_update)
        {
            UpdateLCDStatus();
            lcd_needs_update = 0;
        }
	}
}


void PMOD_BTN_Handler(uint8_t pmod_btn_status)
{
		uint32_t currentTime = GetTick();
	
    switch(pmod_btn_status)
    {
        // BTN0 (PE1)
        case 0x04: //Reset button
        {
					for (int i = 0; i < midi_tune.numTracks; i++) 
            {
                // Reset track position but maintain play state
                trackStates_[i].currentNoteIndex = 0;
                trackStates_[i].lastNoteTime = currentTime;
                
                if (!isPlaying_) 
                {
                    PWM_Disable(trackStates_[i].pwmModule, trackStates_[i].pwmChannel);
                }
            }
            RGB_LED_Output(RGB_LED_BLUE);
						break;
        }

        // BTN1 (PE2)
        case 0x08:
        {
					isPlaying_ = !isPlaying_;
            for (int i = 0; i < midi_tune.numTracks; i++) 
            {
                trackStates_[i].isTrackPlaying = isPlaying_;
                if (isPlaying_) 
                {
                    trackStates_[i].currentNoteIndex = 0;
                    trackStates_[i].lastNoteTime = currentTime;
                    RGB_LED_Output(RGB_LED_GREEN);
                } 
                else 
                {
                    PWM_Disable(trackStates_[i].pwmModule, trackStates_[i].pwmChannel);
                    RGB_LED_Output(RGB_LED_OFF);
                }
            }
            lcd_needs_update = 1;
            break;
        }

        // BTN2 (PE3)
        case 0x10: // Play Button
        {
//					isPlaying_ = !isPlaying_;
//            for (int i = 0; i < midi_tune.numTracks; i++) 
//            {
//                trackStates_[i].isTrackPlaying = isPlaying_;
//                if (isPlaying_) 
//                {
//                    trackStates_[i].currentNoteIndex = 0;
//                    trackStates_[i].lastNoteTime = currentTime;
//                    RGB_LED_Output(RGB_LED_GREEN);  // Green for playing
//									
//                } 
//                else 
//                {
//                    PWM_Disable(trackStates_[i].pwmModule, trackStates_[i].pwmChannel);
//                    RGB_LED_Output(RGB_LED_OFF);    // Off for stopped
//                }
//            }
//						UpdateLCDStatus();
            break;
        }

        // BTN3 (PE4)
        case 0x20:
        {
					
            break;
        }

        default:
        {
            break;
        }
    }
}


void UpdateLCDStatus(void)
{
     // First row: Play state
    EduBase_LCD_Set_Cursor(0, 0);
    EduBase_LCD_Display_String("Status: ");
    EduBase_LCD_Display_String(isPlaying_ ? "Playing" : "Paused ");
    
    // Second row: Track states
    EduBase_LCD_Set_Cursor(0, 1);
    char debug[16];
    sprintf(debug, "T:%d%d%d", 
        trackStates_[0].isTrackPlaying,
        trackStates_[1].isTrackPlaying,
        trackStates_[2].isTrackPlaying);
    EduBase_LCD_Display_String(debug);
}