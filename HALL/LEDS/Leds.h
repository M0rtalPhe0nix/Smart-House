/*
 * LEDS.h
 *
 *  Created on: Sep 3, 2022
 *      Author: mortalphoenix
 */

#ifndef HALL_LEDS_LEDS_H_
#define HALL_LEDS_LEDS_H_

#include "../../MCAL/DIO/DIO.h"
#include "util/delay.h"
#include "Leds_cfg.h"
#include "../../MCAL/TIMERS/TIMERS.h"

extern uint8 brightness;

void Led_Init(uint8 port, uint8 pin);
void Led_On(uint8 port, uint8 pin);
void Led_Off(uint8 port, uint8 pin);
void Led_Blink(uint8 port,uint8 pin);
void Led_Toggle(uint8 port, uint8 pin);
uint8 Led_isOn(uint8 port, uint8 pin);
void Dimming_Init(uint8 port, uint8 pin);
void Dimming();
//void Led_On_For_A_Time(uint8 port, uint8 pin);
#endif /* HALL_LEDS_LEDS_H_ */
