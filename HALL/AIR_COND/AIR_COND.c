/*
 * AIR_COND.c
 *
 *  Created on: Oct 8, 2022
 *      Author: AMR ELKOTT
 */

#include "AIR_COND.h"


void AIR_COND_Init()
{
	ADC_Init();
	DIO_SET_PIN_DIR(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
}

void AIR_COND_TurnON()
{
	DIO_SET_PIN_VALUE(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
}

void AIR_COND_TurnOFF()
{
	DIO_SET_PIN_VALUE(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
}

uint16 TEMP_READ()
{
	uint16 Dout = ADC_READ();
	uint16 Vin;
	Vin = (Dout*5000)/1024;
	return Vin;
}

void AIR_COND()
{
	if(TEMP_READ()>28)
	{
		AIR_COND_TurnON();
	}
	else if(TEMP_READ()<21)
	{
		AIR_COND_TurnOFF();
	}
}
