/*
 * DIO.h
 *
 *  Created on: Aug 26, 2022
 *      Author: AMR ELKOTT
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

#include "../../MACROS.h"
#include "../../MCAL/REGISTERS_ADDRESSES.h"
#include "../../STD_TYPES.h"


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 4


#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1


#define DIO_PORT_INPUT 0x00
#define DIO_PORT_OUTPUT 0xFF


#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1


#define DIO_PORT_LOW  0x00
#define DIO_PORT_HIGH 0xFF




void DIO_SET_PORT_DIR(uint8 PORT,uint8 DIR);
void DIO_SET_PIN_DIR(uint8 PORT,uint8 PIN,uint8 DIR);
void DIO_SET_PORT_VALUE(uint8 PORT,uint8 VAL);
void DIO_SET_PIN_VALUE(uint8 PORT,uint8 PIN,uint8 VAL);

uint8 DIO_READ_PORT(uint8 PORT);
uint8 DIO_READ_PIN(uint8 PORT,uint8 PIN);

void DIO_TOGGLE_PIN(uint8 PORT,uint8 PIN);

void DIO_SET_PULLUP(uint8 PORT,uint8 PIN);


#endif /* MCAL_DIO_H_ */
