/** 
* @file main.c
* Date: 11/7/2024
* @authors: Edgar Gutierrez & Frank Ramirez
*/

#include "TM4C123GH6PM.h"
#include "GPIO.h"
#include "SysTick_Delay.h"
#include "string.h"
#include "midi.h"
#include "PWM.h"


static volatile uint8_t switchPressed_ = 0;
static volatile uint8_t isPlaying_ = 0;
static uint32_t lastSwitchTime_ = 0;
const uint32_t DEBOUNCE_TIME_MS = 250;

extern MidiFile_t midi_tune;


typedef struct {
    PWMModule pwmModule; 
    PWMChannel pwmChannel;
    const MidiTrack_t* track;
    uint8_t isPlaying;
    uint32_t lastNoteTime;  // Track last note time for delay without FreeRTOS
    int noteIndex;
} TrackParams_t;

typedef struct {
    PWMModule pwmModule; 
    PWMChannel pwmChannel;
    const MidiTrack_t* track;
    uint32_t currentNoteIndex;
    uint32_t lastNoteTime;
    uint8_t isTrackPlaying;
} TrackState_t;

// Track states
static TrackState_t trackStates_[4] = {
    { PWMModule0, PWM0_, NULL, 0, 0, 0 },
    { PWMModule0, PWM3, NULL, 0, 0, 0 },
    { PWMModule0, PWM4, NULL, 0, 0, 0 },
    { PWMModule1, PWM3, NULL, 0, 0, 0 }
};

static void ErrHandler(void) {
    while (1) {}
}

static void PlayNote(const MidiNoteEvent_t* note, PWMModule pwmModule, PWMChannel pwmChannel) {
    if (note->key == 0 || note->velocity == 0) {
        PWM_Disable(pwmModule, pwmChannel);
    } else {
        uint16_t period = Midi_NotePwmPeriods[note->key];
        uint16_t duty = period / 2;
        
        PWM_Configure(pwmModule, pwmChannel, period, duty);
        PWM_Enable(pwmModule, pwmChannel);
    }
}

void SwitchHandler(uint32_t pinMap) {
    uint32_t currentTime = HAL_GetTick();
    
    // Simple debounce
    if (currentTime - lastSwitchTime_ >= DEBOUNCE_TIME_MS) {
        switchPressed_ = (uint8_t)pinMap;
        lastSwitchTime_ = currentTime;
        
        // Toggle playing state if SW1 (PIN4) is pressed
        if (switchPressed_ & PIN4) {
            isPlaying_ = !isPlaying_;
            
            // Initialize or reset all tracks
            for (int i = 0; i < midi_tune.numTracks; i++) {
                trackStates_[i].isTrackPlaying = isPlaying_;
                if (isPlaying_) {
                    trackStates_[i].currentNoteIndex = 0;
                    trackStates_[i].lastNoteTime = currentTime;
                } else {
                    // Stop all sounds when stopping playback
                    PWM_Disable(trackStates_[i].pwmModule, trackStates_[i].pwmChannel);
                }
            }
        }
    }
    
    // Rearm interrupts
    GPIOF_Handler();
}

static void ProcessTracks(void) {
    uint32_t currentTime = HAL_GetTick();
    
    for (int trackIdx = 0; trackIdx < midi_tune.numTracks; trackIdx++) {
        TrackState_t* state = &trackStates_[trackIdx];
        
        if (!state->isTrackPlaying || !state->track) {
            continue;
        }
        
        const MidiNoteEvent_t* notes = state->track->notes;
        const MidiNoteEvent_t* currentNote = &notes[state->currentNoteIndex];
        
        // Check if we've reached the end of the track
        if (currentNote->deltaTime == -1) {
            state->isTrackPlaying = 0;
            PWM_Disable(state->pwmModule, state->pwmChannel);
            continue;
        }
        
        // Check if it's time to play the next note
        if (currentTime - state->lastNoteTime >= currentNote->deltaTime) {
            // Process the note
            uint8_t status = 0xF0 & currentNote->status;
            switch (status) {
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


static int InitHardware(void) {
    __disable_irq();
    
    
    // Configure GPIO for buttons
	Button_Init();
    
    // Configure PWM
    PWM_SetClockDivisor(64);
    
    __enable_irq();
    
    return 0;
}

int main(void)
{
if (InitHardware() < 0) {
        ErrHandler();
    }
    
    // Initialize track states
    for (int i = 0; i < midi_tune.numTracks && i < 4; i++) {
        trackStates_[i].track = &midi_tune.tracks[i];
    }
    
    // Main loop
    while (1) {
        ProcessTracks();
        
        // Optional: Add a small delay to prevent tight-looping
        // HAL_Delay(1);
    }
}
