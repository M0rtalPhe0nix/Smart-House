/*
 * ADMIN_MODE.c
 *
 *  Created on: Oct 19, 2022
 *      Author: AMR ELKOTT
 */

#include "ADMIN_MODE.h"

uint8 C;
uint8 f;


void ADMIN_MODE()
{
	   static uint8 count =0;
	   static uint8 COUNTER=0;
	   static uint8 flag=0;
	   static uint8 username_address = 0x01;
	   static uint8 Password_address;

		C = UDR;
      UART_SendByte(C);
	f = EEPROM_READ(0x00);



	if(count == 0)
	{
		if(C == f)
		 {
	         AIR_COND();
			 UART_WriteString("\nYOU ARE LOGGED IN.\n"
					"IF YOU WANT TO ADD NEW USER PRESS F , CONTROL DOOR PRESS S, Leds control PRESS L\n");
			 count=1;
			 COUNTER=0;

		 }
		else if(C=='U')
		{
			USER_MODE();
		}
		else if (C != f && flag ==0)
		{
			UART_WriteString("\n PLEASE RENTER.\n");
		    COUNTER++;
		    flag=3;
		 }
		flag--;
	}

	else if(count == 1)
	 {
		 if(C == 'F')
		 {
			 UART_WriteString("\nENTER THE NEW USERNAME.\n");
			 count=3;
			 flag=3;

		 }
		 else if(C == 'S')
		 {
			 UART_WriteString("\nIF YOU WANT TO open PRESS O , close PRESS C, IF YOU WANT TO GO BACK PRESS D");
			 count=2;
		 }
		 else if(C == 'L')
		 {
			UART_WriteString("\nchoose number from 1 to 5\n");
			count =5;
		 }
		 flag--;
	 }
	else if(count == 2)
	{
		if(C == 'O')
			 {
				 DOOR_OPEN();

			 }
			 else if(C == 'C')
			 {
				 DOOR_CLOSE();

			 }
			 else if(C == 'D')
					 {
				 UART_WriteString("\nIF YOU WANT TO ADD NEW USER PRESS F , CONTROL DOOR PRESS S,Leds control PRESS L\n");
						     count=1;

	}
	}
	else if (count == 3)
	{
		if(flag == 0)
		{
		EEPROM_Write(username_address,C);

		UART_WriteString("\nPLEASE ENTER THE PASSWORD\n");
		count=4;
		flag=3;
		}
		flag--;

	}
	else if(count == 4)
	{
		if(flag == 0)
				{
		Password_address= username_address + 1;

		EEPROM_Write(Password_address,C);
		    UART_WriteString("the user is added succesfully\n");
			UART_WriteString("\nIF YOU WANT TO ADD NEW USER PRESS F , CONTROL DOOR PRESS S,Leds control PRESS L\n");
			username_address +=2;
			count=1;
			flag=3;
				}
		flag--;
	}
	else if(count==4)
	{
		if(C == '1')
		{
			Led_Toggle(LED0_PORT,LED0_PIN);
		}
		if(C == '2')
				{
					Led_Toggle(LED1_PORT,LED1_PIN);
				}
		if(C == '3')
				{
					Led_Toggle(LED2_PORT,LED2_PIN);
				}
		if(C == '4')
				{
					Led_Toggle(LED3_PORT,LED3_PIN);
				}
		if(C == '5')
				{
					Led_Toggle(LED4_PORT,LED4_PIN);
				}
	}

	if(COUNTER == 3 )
	{
		BUZZER_TurnOn();
		count=-1;
	}

}
