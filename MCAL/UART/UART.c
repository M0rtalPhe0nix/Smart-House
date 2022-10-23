/*
 * UART.c
 *
 *  Created on: Sep 24, 2022
 *      Author: AhmedYounis
 */
#include "UART.h"

void UART_Init()
{
	CLR_PIN(DDRD,0);
	SET_PIN(DDRD,1);


	UCSRB = 0x98;
	UCSRC = 0x86;



	UBRRL = (160000/(16*96))-1;
}

void UART_SendByte(uint8 DATA)
{
	UDR = DATA;
    while(GET_PIN(UCSRA,5)==0);

}

uint8 UART_RecByte()
{

	uint8 RecData;

	while(GET_PIN(UCSRA,7)==0);


	RecData = UDR;

	return RecData;

}

void UART_WriteString(uint8* str)
{
	uint8 i = 0 ;

	while(str[i] != '\0')
	{
		UART_SendByte(str[i]);
		i++;
	}
}



