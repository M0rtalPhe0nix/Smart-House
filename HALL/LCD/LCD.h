/*
 * LCD.h
 *
 *  Created on: Aug 27, 2022
 *      Author: AMR ELKOTT
 */

#ifndef HALL_LCD_H_
#define HALL_LCD_H_

#include "LCD_CFG.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO.h"

void LCD_Init();
void LCD_WriteCommand(uint8 cmd);
void LCD_WriteChar(uint8 chr);

void LCD_WriteString(uint8* str);
void LCD_GoTo(uint8 row,uint8 col);
void LCD_WriteInteger(sint32 intgr);

#endif /* HALL_LCD_H_ */
