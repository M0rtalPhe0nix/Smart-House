/*
 * DOOR.c
 *
 *  Created on: Oct 8, 2022
 *      Author: AMR ELKOTT
 */

#include "DOOR.h"




void DOOR_Init()
{
    Timer1_Init(T1_FAST_PWM);
}

void DOOR_OPEN()
{
     Timer1_FastPWM(316,50);
}

void DOOR_CLOSE()
{
	Timer1_FastPWM(97,50);
}
