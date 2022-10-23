/*
 * EEPROM.h
 *
 *  Created on: Oct 7, 2022
 *      Author: AMR ELKOTT
 */

#ifndef HALL_EEPROM_EEPROM_H_
#define HALL_EEPROM_EEPROM_H_

#include "../../STD_TYPES.h"
#include "../../MCAL/I2C/I2C.h"


void EEPROM_Init();
uint8 EEPROM_READ(uint8 address);
void EEPROM_Write(uint8 address,uint8 DATA);
uint8* E2PROM_ReadMultyByteFrom(uint8 address,uint8 length);
void E2PROM_WriteMultyByteOn(uint8 Block_addr, uint8 *data);



#endif /* HALL_EEPROM_EEPROM_H_ */
