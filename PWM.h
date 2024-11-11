//#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include "TM4C123GH6PM.h"

// PWM Module enumeration
typedef enum {
    PWMModule0 = 0,
    PWMModule1 = 1
} PWMModule;

// PWM Channel enumeration
typedef enum {
    PWM0_ = 0,  // Module 0: PB6 (M0PWM0)
    PWM3 = 3,  // Module 0: PC4 (M0PWM6), Module 1: PF2 (M1PWM6)
    PWM4 = 4   // Additional channel if needed
} PWMChannel;

// Function prototypes
void PWM_SetClockDivisor(uint32_t divisor);
void PWM_Configure(PWMModule module, PWMChannel channel, uint16_t period, uint16_t duty);
void PWM_Enable(PWMModule module, PWMChannel channel);
void PWM_Disable(PWMModule module, PWMChannel channel);

//#endif

/**
// PWM Module 0
PB6 - M0PWM0    // PWM Module 0 Generator 0 (PWM0)
PB7 - M0PWM1    // PWM Module 0 Generator 0 (PWM1)
PB4 - M0PWM2    // PWM Module 0 Generator 1 (PWM2)
PB5 - M0PWM3    // PWM Module 0 Generator 1 (PWM3)
PE4 - M0PWM4    // PWM Module 0 Generator 2 (PWM4)
PE5 - M0PWM5    // PWM Module 0 Generator 2 (PWM5)
PC4 - M0PWM6    // PWM Module 0 Generator 3 (PWM6)
PC5 - M0PWM7    // PWM Module 0 Generator 3 (PWM7)

// PWM Module 1
PD0 - M1PWM0    // PWM Module 1 Generator 0 (PWM0)
PD1 - M1PWM1    // PWM Module 1 Generator 0 (PWM1)
PA6 - M1PWM2    // PWM Module 1 Generator 1 (PWM2)
PA7 - M1PWM3    // PWM Module 1 Generator 1 (PWM3)
PF0 - M1PWM4    // PWM Module 1 Generator 2 (PWM4)
PF1 - M1PWM5    // PWM Module 1 Generator 2 (PWM5)
PF2 - M1PWM6    // PWM Module 1 Generator 3 (PWM6)
PF3 - M1PWM7    // PWM Module 1 Generator 3 (PWM7)
*/