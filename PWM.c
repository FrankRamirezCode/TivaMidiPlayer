#include <stdint.h>
#include <assert.h>
#include "TM4C123GH6PM.h"
#include "PWM.h"

// Private helper functions
static void PWM_EnableClock(PWMModule module) {
    // Enable PWM module clock
    SYSCTL->RCGCPWM |= (1 << module);
    
    // Wait for clock to stabilize
    while(!(SYSCTL->PRPWM & (1 << module))) {}
}

static void PWM_ConfigureGPIO(PWMModule module, PWMChannel channel) {
    uint32_t gpioBase = 0;
    uint32_t pin = 0;
    uint32_t portClockBit = 0;
    uint32_t pinMux = 0;
    
    switch(module) {
        case PWMModule0:
            switch(channel) {
                case PWM0_:  // PB6
                    gpioBase = (uint32_t)GPIOB;
                    pin = 6;
                    portClockBit = 1;  // PORTB
                    pinMux = 4;        // PWM function
                    break;
                case PWM3:  // PC4
                    gpioBase = (uint32_t)GPIOC;
                    pin = 4;
                    portClockBit = 2;  // PORTC
                    pinMux = 4;
                    break;
                default:
                    return;
            }
            break;
            
        case PWMModule1:
            switch(channel) {
                case PWM3:  // PF2
                    gpioBase = (uint32_t)GPIOF;
                    pin = 2;
                    portClockBit = 5;  // PORTF
                    pinMux = 5;
                    break;
                default:
                    return;
            }
            break;
    }
    
    // Enable GPIO port clock
    SYSCTL->RCGCGPIO |= (1 << portClockBit);
    while(!(SYSCTL->PRGPIO & (1 << portClockBit))) {}
    
    // Configure GPIO
    volatile uint32_t *gpio = (volatile uint32_t *)gpioBase;
    gpio[0x420/4] |= (1 << pin);              // AFSEL
    gpio[0x52C/4] &= ~(0xF << (pin * 4));     // PCTL clear
    gpio[0x52C/4] |= (pinMux << (pin * 4));   // PCTL set
    gpio[0x51C/4] |= (1 << pin);              // DEN
}

void PWM_SetClockDivisor(uint32_t divisor) {
    // Enable PWM clock divisor
    SYSCTL->RCC |= (1 << 20);  // USEPWMDIV
    
    // Clear existing divisor
    SYSCTL->RCC &= ~(7 << 17);
    
    // Set new divisor (0==/1, 1==/2, 2==/4, 3==/8, 4==/16, 5==/32, 6==/64)
    uint32_t divValue = 0;
    switch(divisor) {
        case 2: divValue = 1; break;
        case 4: divValue = 2; break;
        case 8: divValue = 3; break;
        case 16: divValue = 4; break;
        case 32: divValue = 5; break;
        case 64: divValue = 6; break;
        default: divValue = 0; break;
    }
    SYSCTL->RCC |= (divValue << 17);
}

void PWM_Configure(PWMModule module, PWMChannel channel, uint16_t period, uint16_t duty) {
    if (duty >= period) return;
    
    PWM_EnableClock(module);
    PWM_ConfigureGPIO(module, channel);
    
    volatile uint32_t *pwmBase = (module == PWMModule0) ? (volatile uint32_t *)PWM0 : (volatile uint32_t *)PWM1;
    uint32_t channelOffset = channel * 0x040;
    
    // Disable generator
    pwmBase[(0x040 + channelOffset)/4] &= ~1;  // _n_CTL
    
    // Configure generator
    pwmBase[(0x040 + channelOffset)/4] &= ~2;  // Down count mode
    pwmBase[(0x060 + channelOffset)/4] = 0xC8; // _n_GENA: High on load, Low on CMPA
    pwmBase[(0x050 + channelOffset)/4] = period - 1;  // _n_LOAD
    pwmBase[(0x058 + channelOffset)/4] = duty - 1;    // _n_CMPA
    
    // Enable generator
    pwmBase[(0x040 + channelOffset)/4] |= 1;
}

void PWM_Enable(PWMModule module, PWMChannel channel) {
    volatile uint32_t *pwmBase = (module == PWMModule0) ? (volatile uint32_t *)PWM0 : (volatile uint32_t *)PWM1;
    uint32_t enableBit;
    
    // Map channel to enable bit
    switch(channel) {
        case PWM0_: enableBit = 0x01; break;
        case PWM3: enableBit = 0x40; break;
        default: return;
    }
    
    pwmBase[0x008/4] |= enableBit;  // ENABLE
}

void PWM_Disable(PWMModule module, PWMChannel channel) {
    volatile uint32_t *pwmBase = (module == PWMModule0) ? (volatile uint32_t *)PWM0 : (volatile uint32_t *)PWM1;
    uint32_t enableBit;
    
    // Map channel to enable bit
    switch(channel) {
        case PWM0_: enableBit = 0x01; break;
        case PWM3: enableBit = 0x40; break;
        default: return;
    }
    
    pwmBase[0x008/4] &= ~enableBit;  // ENABLE
}
