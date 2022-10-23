/*
 * BUZZER.c
 *
 *  Created on: Sep 2, 2022
 *      Author: AMR ELKOTT
 */
#include "BUZZER.h"


void BUZZER_Init()
{
	DIO_SET_PIN_DIR(BUZZER_PORT,BUZZER_PIN,DIO_PIN_OUTPUT);
}

void BUZZER_TurnOn()
{
	DIO_SET_PIN_VALUE(BUZZER_PORT,BUZZER_PIN,DIO_PIN_HIGH);
}

void BUZZER_TurnOff()
{
	DIO_SET_PIN_VALUE(BUZZER_PORT,BUZZER_PIN,DIO_PIN_LOW);
}
