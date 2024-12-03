#include "PWM.h"


 // Enables the Clock to be used for the PWM 
void PWM_Clock_Init(void)
{
	

// Enable the PWM clock divisor by setting the
// USEPWMDIV bit (Bit 20) in the RCC register
SYSCTL->RCC |= 0x00100000;

// Clear the PWMDIV field (Bits 19 to 17) in the RCC register
SYSCTL->RCC &= ~0x000E0000;

// Divide the PWM clock frequency by 16 by writing 0x3
// to the PWMDIV field (Bits 19 to 17)
// Note: Only the upper 3 bits are read/write. 0110 (0x6) -> 011 (0x3)
// Refer to page 255 of the TM4C123G Microcontroller Datasheet
SYSCTL->RCC |= 0x00060000;
}


// Enables PWM0_0 on pin PB6 aka M0PWM0
void PWM0_0_Init(uint16_t period_constant, uint16_t duty_cycle)
{	
if (duty_cycle >= period_constant) return;
SYSCTL->RCGCPWM |=  0x01;
SYSCTL->RCGCGPIO |= 0x02;
GPIOB->AFSEL |= 0x40;
GPIOB->PCTL &= ~0x0F000000;
GPIOB->PCTL |= 0x04000000;
GPIOB->DEN |= 0x40;
PWM0->_0_CTL &= ~0x01;
PWM0->_0_CTL &= ~0x02;
PWM0->_0_GENA |= 0xC0;
PWM0->_0_GENA |= 0x08;
PWM0->_0_LOAD = (period_constant - 1);
PWM0->_0_CMPA = (duty_cycle - 1);
PWM0->_0_CTL |= 0x01;
PWM0->ENABLE |= 0x01;
}

// Allows change of duty cycle
void PWM0_0_Update_Duty_Cycle(uint16_t duty_cycle)
{
PWM0 -> _0_CMPA = (duty_cycle -1);
}

// Enables PWM0_3 on pin PC4 aka M0PWM6
void PWM0_3_Init(uint16_t period_constant, uint16_t duty_cycle)
{	
if (duty_cycle >= period_constant) return;
SYSCTL->RCGCPWM |=  0x01;
SYSCTL->RCGCGPIO |= 0x04;
GPIOC->AFSEL |= 0x10;
GPIOC->PCTL &= ~0x0F000000;
GPIOC->PCTL |= 0x04000000;
GPIOC->DEN |= 0x10;
PWM0->_3_CTL &= ~0x01;
PWM0->_3_CTL &= ~0x02;
PWM0->_3_GENA |= 0xC0;
PWM0->_3_GENA |= 0x08;
PWM0->_3_LOAD = (period_constant - 1);
PWM0->_3_CMPA = (duty_cycle - 1);
PWM0->_3_CTL |= 0x01;
PWM0->ENABLE |= 0x40;
}

// Allows change of duty cycle
void PWM0_3_Update_Duty_Cycle(uint16_t duty_cycle)
{
PWM0 -> _3_CMPA = (duty_cycle -1);
}

// Enables PWM1_0 on pin PD0 aka M1PWM0
void PWM1_0_Init(uint16_t period_constant, uint16_t duty_cycle)
{	
if (duty_cycle >= period_constant) return;
SYSCTL->RCGCPWM |=  0x02;
SYSCTL->RCGCGPIO |= 0x08;
GPIOD->AFSEL |= 0x01;
GPIOD->PCTL &= ~0x00000F00;
GPIOD->PCTL |= 0x00000500;
GPIOD->DEN |= 0x01;
PWM1->_0_CTL &= ~0x01;
PWM1->_0_CTL &= ~0x02;
PWM1->_0_GENA |= 0xC0;
PWM1->_0_GENA |= 0x08;
PWM1->_0_LOAD = (period_constant - 1);
PWM1->_0_CMPA = (duty_cycle - 1);
PWM1->_0_CTL |= 0x01;
PWM1->ENABLE |= 0x01;
}

// Allows change of duty cycle
void PWM1_0_Update_Duty_Cycle(uint16_t duty_cycle)
{
PWM1->_0_CMPA = (duty_cycle - 1);
}

// Enables PWM1_3 on pin PF2

void PWM1_3_Init(uint16_t period_constant, uint16_t duty_cycle)
{	
if (duty_cycle >= period_constant) return;
SYSCTL->RCGCPWM |=  0x02;
SYSCTL->RCGCGPIO |= 0x20;
GPIOF->AFSEL |= 0x04;
GPIOF->PCTL &= ~0x00000F00;
GPIOF->PCTL |= 0x00000500;
GPIOF->DEN |= 0x04;
PWM1->_3_CTL &= ~0x01;
PWM1->_3_CTL &= ~0x02;
PWM1->_3_GENA |= 0xC0;
PWM1->_3_GENA |= 0x08;
PWM1->_3_LOAD = (period_constant - 1);
PWM1->_3_CMPA = (duty_cycle - 1);
PWM1->_3_CTL |= 0x01;
PWM1->ENABLE |= 0x40;
}

// Allows change of duty cycle
void PWM1_3_Update_Duty_Cycle(uint16_t duty_cycle)
{
PWM1->_3_CMPA = (duty_cycle - 1);
}

void PWM_Disable(PWMModule pwmModule, PWMChannel pwmChannel)
{
    switch(pwmModule) 
			{
        case PWMModule0:
            if(pwmChannel == PWM0_) 
                PWM0->ENABLE &= ~0x01;  // Disable PWM0_0
            else if(pwmChannel == PWM3) 
                PWM0->ENABLE &= ~0x40;  // Disable PWM0_3
            break;
        case PWMModule1:
            if(pwmChannel == PWM0_) 
                PWM1->ENABLE &= ~0x01;  // Disable PWM1_0
            else if(pwmChannel == PWM3) 
                PWM1->ENABLE &= ~0x40;  // Disable PWM1_3
            break;
			}
}