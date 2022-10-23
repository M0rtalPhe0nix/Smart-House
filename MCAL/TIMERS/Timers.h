/*
 * Timers.h
 *
 *  Created on: Sep 9, 2022
 *      Author: mortalphoenix
 */

#ifndef MCAL_TIMERS_TIMERS_H_
#define MCAL_TIMERS_TIMERS_H_


#include "Timers_cfg.h"
#include "../../STD_TYPES.h"
#include "../../MACROS.h"
#include "../REGISTERS_ADDRESSES.h"


#define T0_NORMAL 0x00
#define T0_CTC 0x08
#define T0_PWM 0x60
#define T0_FAST_PWM 0x68

#define T1_NORMAL 0x0000
#define T1_CTC 0x0008
#define T1_PHASE_FREQUENCE_PWM 0xA110
#define T1_PWM_PHASE 0xA310
#define T1_FAST_PWM 0xA318

#define T2_NORMAL 0x00
#define T2_CTC 0x08
#define T2_PWM 0x60
#define T2_FAST_PWM 0x68



#define NO_CLOCK 0
#define CLK_NO_PRESCALER 1
#define CLK_8_PRESCALER 2
#define CLK_64_PRESCALER 3
#define CLK_256_PRESCALER 4
#define CLK_1024_PRESCALER 5
#define EXT_CLK_FALLING_EDGE 6
#define EXT_CLK_RISING_EDGE 7

#define TIMER2_NO_CLOCK 0
#define TIMER2_CLK_NO_PRESCALER 1
#define TIMER2_CLK_8_PRESCALER 2
#define TIMER2_CLK_32_PRESCALER 3
#define TIMER2_CLK_64_PRESCALER 4
#define TIMER2_CLK_128_PRESCALER 5
#define TIMER2_CLK_256_PRESCALER 6
#define TIMER2_CLK_1024_PRESCALER 7

#define CLK_TICK_TIME 0.0625
#define CLK_8_TICK_TIME 0.5
#define CLK_32_TICK_TIME 2.0 //ONLY TIMER2
#define CLK_64_TICK_TIME 4.0
#define CLK_128_TICK_TIME 8.0 //ONLY TIMER2
#define CLK_256_TICK_TIME 16.0
#define CLK_1024_TICK_TIME 64.0

void Timer0_Init(uint8 mode);
void Timer0_Start();
void Timer0_Stop();
void Timer0_NormalPeriodicTrigger(uint32 period);
void Timer0_CtcPeriodicTrigger(uint32 period,uint8 compare);
void Timer0_FastPWM(uint8 Duty_Cycle);
void Timer0_PWM(uint8 Duty_Cycle);

void Timer2_Init(uint8 mode);
void Timer2_Start();
void Timer2_Stop();
void Timer2_NormalPeriodicTrigger(uint32 period);
void Timer2_CtcPeriodicTrigger(uint32 period,uint8 compare);
void Timer2_FastPWM(uint8 Duty_Cycle);
void Timer2_PWM(uint8 Duty_Cycle);


void Timer1_Init(uint16 mode);
void Timer1_Start();
void Timer1_Stop();
void Timer1_NormalPeriodicTrigger(uint32 period);
void Timer1_CtcPeriodicTrigger(uint32 period,uint16 compare);
void Timer1_FastPWM(float Duty_Cycle, uint16 frequency);
void Timer1_PWM(float Duty_Cycle, uint8 frequency);
void Timer1_PF_PWM(float Duty_Cycle, uint8 frequency);


void ICU_Init();

#if TIMER0_ENABLE == 1
extern volatile uint16 counter0;
extern volatile uint8 preset0;
#endif
#if TIMER1_ENABLE == 1
extern volatile uint16 counter1;
extern volatile uint16 preset1;
#endif
#if TIMER2_ENABLE == 1
extern volatile uint16 counter2;
extern volatile uint8 preset2;
#endif

#if ICU_ENABLE == 1
extern volatile uint16 First_Edge;
extern volatile uint16 Second_Edge;
extern volatile uint16 Falling_Edge;

extern volatile uint16 counter;
#endif
#endif /* MCAL_TIMERS_TIMERS_H_ */
