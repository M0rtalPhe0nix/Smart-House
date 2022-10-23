#include "Leds.h"

uint8 brightness = 0;
void Led_Init(uint8 port, uint8 pin)
{
	DIO_SET_PIN_DIR(port, pin,DIO_PORT_OUTPUT);
	DIO_SET_PIN_VALUE(port, pin,DIO_PIN_LOW);
}
void Dimming_Init(uint8 port, uint8 pin)
{
	DIO_SET_PIN_DIR(port, pin,DIO_PIN_OUTPUT);
	DIO_SET_PIN_VALUE(port, pin,DIO_PIN_LOW);
	Timer0_Init(T0_FAST_PWM);
}
void Dimming()
{
	Timer0_FastPWM(brightness);
}
void Led_On(uint8 port, uint8 pin)
{
	DIO_SET_PIN_VALUE(port, pin,DIO_PIN_HIGH);
}
void Led_Off(uint8 port, uint8 pin)
{
	DIO_SET_PIN_VALUE(port, pin, DIO_PIN_LOW);
}
void Led_Blink(uint8 port,uint8 pin)
{
	Led_On(port, pin);
	_delay_ms(500);
	Led_Off(port,pin);
}
void Led_Toggle(uint8 port, uint8 pin)
{
	DIO_TOGGLE_PIN(port, pin);
}
uint8 Led_isOn(uint8 port, uint8 pin)
{
	if(DIO_READ_PIN(port, pin))
	{
		return 'O';
	}
	return 'X';
}

