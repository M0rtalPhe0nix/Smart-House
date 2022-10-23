/*
 * KEYPAD.c
 *
 *  Created on: Sep 2, 2022
 *      Author:
 */

#include "KEYPAD.h"

#include <util/delay.h>

const uint8 keypad[4][4] = {{'1','2','3','A'},
				   	   	  	{'4','5','6','B'},
							{'7','8','9','C'},
							{'.','0','=','*'}};
void KeyPad_Init(void)
{
	DIO_SET_PIN_DIR(KEYPAD_PORT, KEYPAD_COLUM_0,DIO_PIN_INPUT);
	DIO_SET_PIN_DIR(KEYPAD_PORT, KEYPAD_COLUM_1,DIO_PIN_INPUT);
	DIO_SET_PIN_DIR(KEYPAD_PORT, KEYPAD_COLUM_2,DIO_PIN_INPUT);
	DIO_SET_PIN_DIR(KEYPAD_PORT, KEYPAD_COLUM_3,DIO_PIN_INPUT);

	DIO_SET_PIN_DIR(KEYPAD_PORT, KEYPAD_ROW_0,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIR(KEYPAD_PORT, KEYPAD_ROW_1,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIR(KEYPAD_PORT, KEYPAD_ROW_2,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIR(KEYPAD_PORT, KEYPAD_ROW_3,DIO_PIN_OUTPUT);

	DIO_SET_PULLUP(KEYPAD_PORT, KEYPAD_COLUM_0);
	DIO_SET_PULLUP(KEYPAD_PORT, KEYPAD_COLUM_1);
	DIO_SET_PULLUP(KEYPAD_PORT, KEYPAD_COLUM_2);
	DIO_SET_PULLUP(KEYPAD_PORT, KEYPAD_COLUM_3);

	DIO_SET_PIN_VALUE(KEYPAD_PORT, KEYPAD_ROW_0,DIO_PIN_LOW);
	DIO_SET_PIN_VALUE(KEYPAD_PORT, KEYPAD_ROW_1,DIO_PIN_LOW);
	DIO_SET_PIN_VALUE(KEYPAD_PORT, KEYPAD_ROW_2,DIO_PIN_LOW);
	DIO_SET_PIN_VALUE(KEYPAD_PORT, KEYPAD_ROW_3,DIO_PIN_LOW);

}

uint8 KeyPad_GetChar(void)
{



	for(int i = KEYPAD_ROW_0; i <= KEYPAD_ROW_3; i++)
	{
		DIO_SET_PORT_VALUE(KEYPAD_PORT, (0xff - (1<<i)));
		_delay_ms(1);

		for(int j = KEYPAD_COLUM_0; j <= KEYPAD_COLUM_3; j++)
		{
			if(!DIO_READ_PIN(KEYPAD_PORT, j))
			{
				DIO_SET_PORT_VALUE(KEYPAD_PORT, 0xF0);

				return keypad[i][j - COL_START];
			}
		}
	}}
	/*DIO_SetPortValue(KEYPAD_PORT, 0xFE);
	_delay_ms(1);

	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_0) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '1';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_1) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '2';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_2) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '3';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_3) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return 'A';}

	DIO_SetPortValue(KEYPAD_PORT, 0xFD);
	_delay_ms(1);
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_0) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '4';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_1) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '5';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_2) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '6';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_3) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return 'B';}

	DIO_SetPortValue(KEYPAD_PORT, 0xFB);
	_delay_ms(1);
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_0) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '7';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_1) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '8';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_2) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '9';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_3) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return 'C';}


	DIO_SetPortValue(KEYPAD_PORT, 0xF7);
	_delay_ms(1);
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_0) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '*';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_1) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '0';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_2) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return '#';}
	if(DIO_ReadPin(KEYPAD_PORT, KEYPAD_COLUM_3) == 0) {DIO_SetPortValue(KEYPAD_PORT, 0xF0);return 'D';}
	return 0;
}*/
