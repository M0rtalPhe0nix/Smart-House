/*
 * EEPROM.c
 *
 *  Created on: Oct 7, 2022
 *      Author: AMR ELKOTT
 */

#include "EEPROM.h"
	uint8 buffer[7];


void EEPROM_Init()
{
	I2C_Master_Init();
}

uint8 EEPROM_READ(uint8 address)
{
	uint8 DATA;
   I2C_Start_Condition();
   I2C_SendSlaveAddress_Write(0b01010000);
   I2C_Send_Data(address);
   I2C_Repeated_Start();
   I2C_SendSlaveAddress_Read(0b01010000);
   DATA=I2C_Read_Data();
   I2C_Stop_Condition();
   return DATA;
}

void EEPROM_Write(uint8 address,uint8 DATA)
{
	    I2C_Start_Condition();
		I2C_SendSlaveAddress_Write(0b01010000);
        I2C_Send_Data(address);
        I2C_Send_Data(DATA);
        I2C_Stop_Condition();
}

void E2PROM_WriteMultyByteOn(uint8 address, uint8 *data)
{
	uint8 i=0;
	I2C_Start_Condition();
	I2C_SendSlaveAddress_Write( 0b01010000);
	I2C_Send_Data((unsigned char)address);
	while(data[i] != '\0')
	{
		I2C_Send_Data(data[i]);
		i++;
	}
	I2C_Stop_Condition();
}

uint8* E2PROM_ReadMultyByteFrom(uint8 address,uint8 length)
{

	for(int i = 0; i < length; i++)
	{
		buffer[i] = EEPROM_READ(0x00 + i);

	}
	buffer[length] = '\0';
	return buffer;

//	uint8* data;
//	uint8 i =0;
//	I2C_Start_Condition();
//	I2C_SendSlaveAddress_Write( 0b01010000 );
//	I2C_Send_Data((unsigned char)address);
//
//	I2C_Repeated_Start();
//	I2C_SendSlaveAddress_Read(0b01010000);
//
//    while(data[i] != '\0')
//    {
//	 data[i] = I2C_Read_Data();
//     i++;
//    }
//
//	I2C_Stop_Condition();
//	return data;
}
