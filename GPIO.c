/**
 * @file GPIO.c
 *
 * @brief Source code for the GPIO driver.
 *
 * This file contains the function definitions for the GPIO driver.
 * It interfaces with the following:
 *  - User LED (RGB) Tiva C Series TM4C123G LaunchPad
 *	- EduBase Board LEDs (LED0 - LED3)
 *	- EduBase Board Push Buttons (SW2 - SW5)
 *
 * To verify the pinout of the user LED, refer to the Tiva C Series TM4C123G LaunchPad User's Guide
 * Link: https://www.ti.com/lit/pdf/spmu296
 *
 * @author Aaron Nanas
 */

#include "GPIO.h"

// Constant definitions for the user LED (RGB) colors
const uint8_t RGB_LED_OFF 		= 0x00;
const uint8_t RGB_LED_RED 		= 0x02;
const uint8_t RGB_LED_BLUE 		= 0x04;
const uint8_t RGB_LED_GREEN 	= 0x08;


void RGB_LED_Init(void)
{
	// Enable the clock to Port F
	SYSCTL->RCGCGPIO |= 0x20;

	// Set PF1, PF2, and PF3 as output GPIO pins
	GPIOF->DIR |= 0x0E;
	
	// Configure PF1, PF2, and PF3 to function as GPIO pins
	GPIOF->AFSEL &= ~0x0E;
	
	// Enable digital functionality for PF1, PF2, and PF3
	GPIOF->DEN |= 0x0E;
	
	// Initialize the output of the RGB LED to zero
	GPIOF->DATA &= ~0x0E;
}

void RGB_LED_Output(uint8_t led_value)
{
	// Set the output of the RGB LED
	GPIOF->DATA = (GPIOF->DATA & 0xF1) | led_value;
}

uint8_t RGB_LED_Status(void)
{
	// Assign the value of Port F to a local variable
	// and only read the values of the following bits: 3, 2, and 1
	// Then, return the local variable's value
	uint8_t RGB_LED_Status = GPIOF->DATA & 0x0E;
	return RGB_LED_Status;
}

void (*BTN_Task)(uint8_t pmod_btn_state);

void Button_Init(void (*task)(uint8_t))
{
	BTN_Task = task;
	SYSCTL -> RCGCGPIO |= 0x20;
	GPIOF -> DIR &= ~0x11;
	GPIOF ->AFSEL &= ~0x11;
	GPIOF -> PUR |= 0x11;
	GPIOF -> IS &= ~0x11;
	GPIOF -> IBE &= ~0x11;
	GPIOF -> IEV |= 0x11;
	GPIOF -> ICR |= 0x11;
	GPIOF -> IM |= 0x11;
	NVIC ->IPR[0] &= ~0xE0000000;
	NVIC->IPR[0] |= (3 << 29);
	NVIC->ISER[0] |= (1 << 30);
}

uint8_t BTN_Read(void)
{
	uint8_t btn_state = GPIOF->DATA & 0x11;
	
	return btn_state;
}

void GPIOF_Handler(void)
{
	// Check if an interrupt has been triggered by any of
	// the following pins: PA5, PA4, PA3, and PA2
	if (GPIOF->MIS & 0x11)
	{
		// Execute the user-defined function
		(*BTN_Task)(BTN_Read());
		
		// Acknowledge the interrupt from any of the following pins
		// and clear it: PA5, PA4, PA3, and PA2
		GPIOF->ICR |= 0x11;
	}
}



