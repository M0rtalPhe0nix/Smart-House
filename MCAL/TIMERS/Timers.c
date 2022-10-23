/*
 * Timers.c
 *
 *  Created on: Sep 9, 2022
 *      Author: mortalphoenix
 */

#include "Timers.h"

#if TIMER0_ENABLE == 1

volatile uint16 counter0;
volatile uint8 preset0;

#endif

#if TIMER1_ENABLE == 1

volatile uint16 counter1;
volatile uint16 preset1;

#endif

#if TIMER2_ENABLE == 1

volatile uint16 counter2;
volatile uint8 preset2;

#endif
#if ICU_ENABLE == 1

volatile uint16 First_Edge;
volatile uint16 Second_Edge;
volatile uint16 Falling_Edge;
volatile uint8 counter = 0;

#endif

void Timer0_Init(uint8 mode)
{
	SREG &= ~(1 << 7);
	TCNT0 = 0x00;
	TCCR0 = mode;

	if(mode == T0_NORMAL)
	{
		TIMSK |= 1;
		TIMSK &= ~(2);
		SREG |= (1 << 7);
	}
	else if(mode == T0_CTC)
	{
		TIMSK |= 2;
		TIMSK &= ~(1);
		SREG |= (1 << 7);
	}
	else if(mode == T0_PWM)
	{
		SET_PIN(DDRB,3);
	}
	else if(mode == T0_FAST_PWM)
	{
		SET_PIN(DDRB,3);
	}
}

void Timer0_Start()
{
	TCCR0 |= TIMER0_PRESCALER_CODE;
}

void Timer0_Stop()
{
	TCCR0 = NO_CLOCK;
	TCNT0 = 0;
}

void Timer0_NormalPeriodicTrigger(uint32 period)
{
#if TIMER0_ENABLE == 1
	period *= 1000;
	preset0 = 256 - ((uint32) (period/TIMER0_TICK_TIME) % 256);
	counter0 = ((period / TIMER0_TICK_TIME) / 256);
	TCNT0 = preset0;
#endif
}

void Timer0_CtcPeriodicTrigger(uint32 period,uint8 compare)
{
#if TIMER0_ENABLE == 1
	period *= 1000;
	preset0 = compare - ((uint32) (period / TIMER0_TICK_TIME) % compare);
	counter0 = ((period / TIMER0_TICK_TIME)/compare);
	TCNT0 = preset0;
	OCR0 = compare;
#endif
}

void Timer0_FastPWM(uint8 Duty_Cycle)
{
	OCR0 = (Duty_Cycle * (256.0/100.0)) - 1;
}

void Timer0_PWM(uint8 Duty_Cycle)
{
	OCR0 = (Duty_Cycle * 255)/100.0;
}

void Timer1_Init(uint16 mode)
{
	SREG &= ~(1 << 7);
	TCNT1 = 0;
	TCCR1 = mode;
	if(mode == T1_NORMAL)
	{
		TIMSK |= 4;
		TIMSK &= ~(8);
		TIMSK &= ~(16);
		TIMSK &= ~(32);
		SREG |= (1 << 7);
	}
	else if(mode == T1_CTC)
	{
		TIMSK |= 16;
		TIMSK &= ~(4);
		TIMSK &= ~(8);
		TIMSK &= ~(32);
		SREG |= (1 << 7);
	}
	else if(mode == T1_PWM_PHASE)
	{
		SET_PIN(DDRD,4);
		SET_PIN(DDRD,5);
	}
	else if(mode == T1_FAST_PWM)
	{
		SET_PIN(DDRD,4);
		SET_PIN(DDRD,5);
	}
	else if(mode == T1_PHASE_FREQUENCE_PWM)
	{
		SET_PIN(DDRD,4);
		SET_PIN(DDRD,5);
	}
}

void Timer1_Start()
{
	TCCR1 |= TIMER1_PRESCALER_CODE;
}

void Timer1_Stop()
{
	TCCR1 = NO_CLOCK;
	TCNT1 = 0;
}

void Timer1_NormalPeriodicTrigger(uint32 period)
{
#if TIMER1_ENABLE == 1
	period *= 1000;
	preset1 = 65536 - ((uint16)(period / TIMER1_TICK_TIME)% 65536);
	counter1 = ((period / TIMER1_TICK_TIME) /65536.0);
	TCNT1 = preset1;
#endif
}

void Timer1_CtcPeriodicTrigger(uint32 period,uint16 compare)
{
#if TIMER1_ENABLE == 1
	period *= 1000;
	preset1 = compare - ((uint32)(period / TIMER0_TICK_TIME) % compare);
	counter1 = ((period / TIMER0_TICK_TIME) / compare);
	TCNT1 = preset1;
	OCR1A = compare;
#endif
}

void Timer1_FastPWM(float Duty_Cycle,uint16 frequency)
{
	OCR1A = (16000000.0 / (frequency * TIMER1_PRESCALER)) - 1;
	OCR1B = (Duty_Cycle * (OCR1A / 100.0)) - 1;
}

void Timer1_PWM(float Duty_Cycle,uint8 frequency)
{
	OCR1A = 16000000.0 / (2 * frequency * TIMER1_PRESCALER);
	OCR1B = (Duty_Cycle * OCR1A) / 100.0;
}

void Timer1_PF_PWM(float Duty_Cycle, uint8 frequency)
{
	//phase and frequency correction
	OCR1A = 16000000.0 / (2 * frequency * TIMER1_PRESCALER);
	OCR1B = (Duty_Cycle * OCR1A)/100.0;

}

void Timer2_Init(uint8 mode)
{
	SREG &= ~(1 << 7);
	TCNT2 = 0x00;
	TCCR2 = mode;

	if(mode == T2_NORMAL)
	{
		TIMSK |= (1 << 6);
		TIMSK &= ~(1 << 7);
		SREG |= (1 << 7);
	}
	else if(mode == T2_CTC)
	{
		TIMSK |= (1 << 7);
		TIMSK &= ~(1 << 6);
		SREG |= (1 << 7);
	}
	else if(mode == T2_PWM)
	{
		SET_PIN(DDRD,7);
	}
	else if(mode == T2_FAST_PWM)
	{
		SET_PIN(DDRD,7);
	}
}

void Timer2_Start()
{
	TCCR2 |= TIMER2_PRESCALER_CODE;
}

void Timer2_Stop()
{
	TCCR2 = NO_CLOCK;
	TCNT2 = 0;
}

void Timer2_NormalPeriodicTrigger(uint32 period)
{
#if TIMER2_ENABLE == 1
	period *= 1000;
	preset2 = 256 - ((uint16)(period/TIMER2_TICK_TIME) % 256);
	counter2 = ((period / TIMER2_TICK_TIME) / 256.0);
	TCNT2 = preset2;
#endif
}

void Timer2_CtcPeriodicTrigger(uint32 period,uint8 compare)
{
#if TIMER2_ENABLE == 1
	period *= 1000;
	preset2 = compare - ((uint16)(period / TIMER2_TICK_TIME)%compare);
	counter2 = ((period / TIMER2_TICK_TIME)/compare);
	TCNT2 = preset2;
	OCR2 = compare;
#endif
}

void Timer2_FastPWM(uint8 Duty_Cycle)
{
	OCR2 = (Duty_Cycle * (256.0/100.0)) - 1;
}

void Timer2_PWM(uint8 Duty_Cycle)
{
	OCR2 = (Duty_Cycle * 255)/100.0;
}

void ICU_Init()
{
	Timer1_Init(T1_NORMAL);
	TCCR1 = 0x0041;
	TIMSK |= (1 << 5);
}
