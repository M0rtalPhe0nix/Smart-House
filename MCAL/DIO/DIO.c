/*
 * DIO.c
 *
 *  Created on: Aug 26, 2022
 *      Author: AMR ELKOTT
 */
#include "../../MCAL/DIO/DIO.h"

void DIO_SET_PORT_DIR(uint8 PORT,uint8 DIR)
{

	switch(PORT)
	{
	case DIO_PORTA:
		DDRA=DIR;
		break;
	case DIO_PORTB:
		DDRB=DIR;
		break;
	case DIO_PORTC:
		DDRC=DIR;
		break;
	case DIO_PORTD:
		DDRD=DIR;
		break;
	}
return ;
}



void  DIO_SET_PIN_DIR(uint8 PORT ,uint8 PIN ,uint8 DIR)
{
	switch(DIR)
	{

	case DIO_PIN_OUTPUT :

		switch(PORT)
		{
			case DIO_PORTA:
			SET_PIN(DDRA,PIN);
			break;
			case DIO_PORTB:
			SET_PIN(DDRB,PIN);
			break;
			case DIO_PORTC:
			SET_PIN(DDRC,PIN);
			break;
			case DIO_PORTD:
			SET_PIN(DDRD,PIN);
			break;
			default:
			break;

		}

	break;

	case DIO_PIN_INPUT :

		switch(PORT)
		{
			case DIO_PORTA:
			CLR_PIN(DDRA,PIN);
			break;
			case DIO_PORTB:
			CLR_PIN(DDRB,PIN);
			break;
			case DIO_PORTC:
			CLR_PIN(DDRC,PIN);
			break;
			case DIO_PORTD:
			CLR_PIN(DDRD,PIN);
			break;
			default:
			break;

		}

	break;

	default:
	break;


	}

}



void DIO_SET_PORT_VALUE(uint8 PORT,uint8 VAL)
{

		switch(PORT)
		{
		case DIO_PORTA:
			PORTA=VAL;
			break;
		case DIO_PORTB:
			PORTB=VAL;
			break;
		case DIO_PORTC:
			PORTC=VAL;
			break;
		case DIO_PORTD:
			PORTD=VAL;
			break;
		}
		return ;
}



void DIO_SET_PIN_VALUE(uint8 PORT,uint8 PIN,uint8 VAL)
{


		switch(VAL)
		{
			case DIO_PIN_HIGH :

			switch(PORT)
			{
				case DIO_PORTA:
				SET_PIN(PORTA,PIN);
				break;
				case DIO_PORTB:
				SET_PIN(PORTB,PIN);
				break;
				case DIO_PORTC:
				SET_PIN(PORTC,PIN);
				break;
				case DIO_PORTD:
				SET_PIN(PORTD,PIN);
				break;
				default:
				break;

			}


			break;

			case DIO_PIN_LOW:

				switch(PORT)
				{
					case DIO_PORTA:
					CLR_PIN(PORTA,PIN);
					break;
					case DIO_PORTB:
					CLR_PIN(PORTB,PIN);
					break;
					case DIO_PORTC:
					CLR_PIN(PORTC,PIN);
					break;
					case DIO_PORTD:
					CLR_PIN(PORTD,PIN);
					break;
					default:
					break;

				}

			break;

			default:
			break;
		}

	}


uint8  DIO_READ_PORT(uint8 PORT)
{
	uint8 val = 0;

	switch(PORT)
	{
		case DIO_PORTA :
		val = PINA;
		break;

		case DIO_PORTB :
		val = PINB;
		break;

		case DIO_PORTC :
		val = PINC;
		break;

		case DIO_PORTD :
		val = PIND;
		break;

		default:

		break;
	}

	return  val;

}

uint8 DIO_READ_PIN(uint8 PORT,uint8 PIN)
{

	uint8 val = 0;

		switch(PORT)
		{
			case DIO_PORTA :
			val = GET_PIN(PINA,PIN);
			break;

			case DIO_PORTB :
			val = GET_PIN(PINB,PIN);
			break;

			case DIO_PORTC :
			val = GET_PIN(PINC,PIN);
			break;

			case DIO_PORTD :
			val = GET_PIN(PIND,PIN);
			break;

			default:
			break;

		}

		return val;
}

void DIO_TOGGLE_PIN(uint8 PORT,uint8 PIN)
{

	switch(PORT)
			{
				case DIO_PORTA :
				TOGGLE_PIN(PORTA,PIN);
				break;

				case DIO_PORTB :
				TOGGLE_PIN(PORTB,PIN);
				break;

				case DIO_PORTC :
				TOGGLE_PIN(PORTC,PIN);
				break;

				case DIO_PORTD :
				TOGGLE_PIN(PORTD,PIN);
				break;

				default:

				break;
			}
}

void DIO_SET_PULLUP(uint8 PORT,uint8 PIN)
{
	switch(PORT)
				{
					case DIO_PORTA :
					SET_PIN(PORTA,PIN);
					break;

					case DIO_PORTB :
					SET_PIN(PORTB,PIN);
					break;

					case DIO_PORTC :
					SET_PIN(PORTC,PIN);
					break;

					case DIO_PORTD :
					SET_PIN(PORTD,PIN);
					break;

					default:

					break;
				}
}
