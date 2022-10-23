/*
 * USER_MODE.c
 *
 *  Created on: Oct 19, 2022
 *      Author: AMR ELKOTT
 */

#include "USER_MODE.h"



void USER_MODE()
{
	static uint8 username;
	static uint8 username_add=0x01;
	static uint8 password;
    static uint8 password_add;
	static uint8 goal=0;
	static uint8 ball=0;

	static uint8 counter1 = 0;
		uint8 buffer[15];
		LCD_WriteCommand(0x01);
		LCD_WriteString("Enter ID");
		LCD_GoTo(1, 0);
		uint8 i = 0;
		while(1)
		{
			buffer[i] = KeyPad_GetChar();
			if(buffer[i] != '*' && buffer[i] != 0)
			{
				LCD_WriteChar(buffer[i]);
				_delay_ms(250);
				i++;
			}
			else if(buffer[i] == '*')
			{
				i = 0;
				break;
			}

		}


		username = buffer[0];
		while(username_add<0xFF)
		{
			if(username == EEPROM_READ(username_add))
			{

				goal=1;
				username_add=0x00;
				break;
			}
			else
			{
				username_add +=2;
			}
		}

		if(goal == 0)
		{
			LCD_WriteCommand(0x01);
			LCD_WriteString("the username is wrong");
		}
		else if(goal == 1)
		{
			LCD_WriteCommand(0x01);
			LCD_WriteString("Enter Pass");
			LCD_GoTo(1, 0);
			while(1)
			{
				buffer[i] = KeyPad_GetChar();
				if(buffer[i] != '*' && buffer[i] != 0)
				{
					_delay_ms(250);
					i++;
				}
				else if(buffer[i] == '*')
				{
					i = 0;
					break;
				}

			}
			password = buffer[0];

				password_add = username_add +1;
				if(password == EEPROM_READ(password_add))
				{

					ball=1;
					username_add=0x00;

				}
				else
				{
					LCD_WriteCommand(0x01);
					LCD_WriteString("the password is wrong");
				}

			}

if(ball == 1)
{

        LCD_WriteCommand(0x01);
		LCD_WriteString("L1: L2: L3: L4: ");
		LCD_GoTo(1, 0);
		LCD_WriteString("L5: Ld: AC:");
		while(1)
		{
			if(KeyPad_GetChar() == '1')
			{
				Led_Toggle(LED0_PORT,LED0_PIN);
				_delay_ms(250);
			}
			else if(KeyPad_GetChar() == '2')
			{
				Led_Toggle(LED1_PORT,LED1_PIN);
				_delay_ms(250);
			}
			else if(KeyPad_GetChar() == '3')
			{
				Led_Toggle(LED2_PORT,LED2_PIN);
				_delay_ms(250);
			}
			else if(KeyPad_GetChar() == '4')
			{
				Led_Toggle(LED3_PORT, LED3_PIN);
				_delay_ms(250);
			}
			else if(KeyPad_GetChar() == '5')
			{
				Led_Toggle(LED4_PORT, LED4_PIN);
				_delay_ms(250);
			}
			else if(KeyPad_GetChar() == '6')
			{
				LCD_WriteCommand(0x01);
				LCD_WriteString("SET: ");
				while(1)
				{
					if(KeyPad_GetChar())
					{
						brightness = KeyPad_GetChar();
						Dimming();
						break;
					}
				}
			}

			else if(KeyPad_GetChar() == '*')
			{
				break;
			}
		}
		LCD_WriteCommand(0x01);
		LCD_WriteString("L1: L2: L3: L4: ");
		LCD_GoTo(1, 0);
		LCD_WriteString("L5: Ld: AC: Dr: ");
}
}

