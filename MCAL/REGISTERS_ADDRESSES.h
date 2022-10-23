/*
 * REGISTERS_ADDRESSES.h
 *
 *  Created on: Aug 26, 2022
 *      Author: AMR ELKOTT
 */

#ifndef MCAL_REGISTERS_ADDRESSES_H_
#define MCAL_REGISTERS_ADDRESSES_H_

#include "../STD_TYPES.h"

/*********************DIO********************/


#define DDRA *((volatile unsigned char*)0x3A)
#define PORTA *((volatile unsigned char*)0x3B)
#define PINA *((volatile unsigned char*)0x39)

#define DDRB *((volatile unsigned char*)0x37)
#define PORTB *((volatile unsigned char*)0x38)
#define PINB *((volatile unsigned char*)0x36)

#define DDRC *((volatile unsigned char*)0x34)
#define PORTC *((volatile unsigned char*)0x35)
#define PINC *((volatile unsigned char*)0x33)

#define DDRD *((volatile unsigned char*)0x31)
#define PORTD *((volatile unsigned char*)0x32)
#define PIND *((volatile unsigned char*)0x30)


/***************EXT_INTERRUPT*****************/

#define SREG  *((volatile unsigned char*)0x5F)

#define GICR  *((volatile unsigned char*)0x5B)

#define GIFR  *((volatile unsigned char*)0x5A)

#define MCUCR *((volatile unsigned char*)0x55)

#define MCUCSR *((volatile unsigned char*)0x54)

/********************TIMER0********************/
#define TCNT0  *((volatile unsigned char*)0x52)

#define TCCR0  *((volatile unsigned char*)0x53)

#define OCR0  *((volatile unsigned char*)0x5C)

#define TIFR  *((volatile unsigned char*)0x58)

#define TIMSK  *((volatile unsigned char*)0x59)

/********************TIMER1********************/
#define TCCR1A   *((volatile unsigned char*)0x4F)

#define TCCR1B   *((volatile unsigned char*)0x4E)

#define TCCR1 *((volatile uint16*)0x4E)

#define TCNT1 *((volatile uint16*)0x4C)

#define OCR1A   *((volatile uint16*)0x4A)

#define OCR1B   *((volatile uint16*)0x48)

#define ICR1    *((volatile uint16*)0x46)

/********************TIMER2*********************/

#define TCCR2  *((volatile unsigned char*)0x45)

#define OCR2  *((volatile unsigned char*)0x43)

#define TCNT2 *((volatile uint8*)0x44)

/**********************ADC**********************/

#define ADMUX  *((volatile unsigned char*)0x27)

#define ADCSRA  *((volatile unsigned char*)0x26)

#define ADCH  *((volatile unsigned char*)0x25)

#define ADCL  *((volatile unsigned char*)0x24)

#define ADC_ADJUST  *((volatile uint16*)0x24)

/**********************UART**********************/

#define UCSRA  *((volatile unsigned char*)0x2B)

#define UCSRB  *((volatile unsigned char*)0x2A)

#define UDR    *((volatile unsigned char*)0x2C)

#define UBRRL  *((volatile unsigned char*)0x29)

#define UBRRH  *((volatile unsigned char*)0x40)

#define UCSRC  *((volatile unsigned char*)0x40)

/**********************SPI**********************/

typedef struct
{
	uint8 SPR0 :1;
	uint8 SPR1 :1;
	uint8 CPHA :1;
	uint8 CPOL :1;
	uint8 MSTR :1;
	uint8 DORD :1;
	uint8 SPE  :1;
	uint8 SPIE :1;
}SPCR_Reg;

typedef struct
{
	SPCR_Reg SPCR;
	uint8 SPSR;
	uint8 SPDR;
}SPI_Reg;


#define SPI ((volatile SPI_Reg*)0x2D)

/**********************WD***********************/

#define WDTCR            (*(volatile uint8 *)(0x41))

/**********************I2C**********************/

#define TWDR            (*(volatile uint8 *)(0x23))

#define TWAR            (*(volatile uint8 *)(0x22))

#define TWSR            (*(volatile uint8 *)(0x21))

#define TWBR            (*(volatile uint8 *)(0x20))


#define TWCR            (*(volatile uint8 *)(0x56))

#endif /* MCAL_REGISTERS_ADDRESSES_H_ */
