/*
 * main.c
 *
 *  Created on: Oct 11, 2022
 *      Author: AMR ELKOTT
 */
#include <util/delay.h>
#include <string.h>



#include "../MACROS.h"
#include "../STD_TYPES.h"



#include "../MCAL/UART/UART.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INTERRUPT.h"

//#include "../HALL/AIR_COND/AIR_COND.h"
//#include "../HALL/LCD/LCD.h"
//#include "../HALL/DOOR/DOOR.h"
//#include "../HALL/LEDS/Leds.h"
//#include "../HALL/EEPROM/EEPROM.h"
//#include "../HALL/KEYPAD/KEYPAD.h"
//#include "../HALL/BUZZER/BUZZER.h"

#include <avr/interrupt.h>

#include "ADMIN_MODE/ADMIN_MODE.h"
//#include "USER_MODE/USER_MODE.h"






ISR(INT0_vect)
{
   LCD_WriteChar('C');
	USER_MODE();
}

ISR(USART_RXC_vect)
{

  ADMIN_MODE();
}

int main()
{

GLOBAL_INTERRUPT();
UART_Init();
//EXTERNAL_INT0();
EEPROM_Init();
//DOOR_Init();
LCD_Init();
AIR_COND_Init();
BUZZER_Init();
KeyPad_Init();


uint8 *data ="\nHELLO ADMIN AND WELCOME\n"
		  "PLEASE ENTER YOUR PASSWORD:\n";
UART_WriteString(data);
LCD_WriteString("data");
uint8 ADMIN_PASS = 'A';
EEPROM_Write(0x00,ADMIN_PASS);





	while(1)
	{




	}



	return 0;
}
