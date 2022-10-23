/*
 * BUTTON.c
 *
 *  Created on: Aug 27, 2022
 *      Author: AMR ELKOTT
 */
#include "BUTTON.h"

void BUTTON0_Init()
{
	DIO_SET_PIN_DIR(BUTTON0_PORT,BUTTON0_PIN,DIO_PIN_INPUT);
}

uint8 BUTTON0_READ()
{
    uint8 VALUE;
    VALUE=DIO_READ_PIN(BUTTON0_PORT,BUTTON0_PIN);

	return VALUE;

}

void BUTTON1_Init()
{
	DIO_SET_PIN_DIR(BUTTON1_PORT,BUTTON1_PIN,DIO_PIN_INPUT);
}

uint8 BUTTON1_READ()
{
	uint8 VALUE;
	VALUE=DIO_READ_PIN(BUTTON1_PORT,BUTTON1_PIN);

	return VALUE;

}

void BUTTON2_Init()
{
	DIO_SET_PIN_DIR(BUTTON2_PORT,BUTTON2_PIN,DIO_PIN_INPUT);
}

uint8 BUTTON2_READ()
{
	uint8 VALUE;
	VALUE=DIO_READ_PIN(BUTTON2_PORT,BUTTON2_PIN);

	return VALUE;


}
