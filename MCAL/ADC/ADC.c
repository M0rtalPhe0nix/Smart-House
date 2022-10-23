/*
 * ADC.c
 *
 *  Created on: Sep 23, 2022
 *      Author: AMR ELKOTT
 */
#include "../../MCAL/ADC/ADC.h"

void ADC_Init()
{
#if ADC_VREF_SELECTED == ADC_VREF_AREF
	CLR_PIN(ADMUX,7);
	CLR_PIN(ADMUX,6);
#elif ADC_VREF_SELECTED == ADC_VREF_AVCC
	CLR_PIN(ADMUX,7);
	SET_PIN(ADMUX,6);
#elif ADC_VREF_SELECTED == ADC_VREF_INTERNAL
	SET_PIN(ADMUX,7);
	SET_PIN(ADMUX,6);
#endif

#if ADC_ADJUST_SELECTED == ADC_RIGHT_ADJUST
	CLR_PIN(ADMUX,5);
#elif ADC_ADJUST_SELECTED == ADC_RIGHT_ADJUST
	SER_PIN(ADMUX,5);
#endif

#if ADC_CHANNEL_SELECTED == ADC_CHANNEL0
	CLR_PIN(ADMUX,0);
	CLR_PIN(ADMUX,1);
	CLR_PIN(ADMUX,2);
	CLR_PIN(ADMUX,3);
	CLR_PIN(ADMUX,4);
#elif ADC_CHANNEL_SELECTED == ADC_CHANNEL1
	SET_PIN(ADMUX,0);
	CLR_PIN(ADMUX,1);
	CLR_PIN(ADMUX,2);
	CLR_PIN(ADMUX,3);
	CLR_PIN(ADMUX,4);
#elif ADC_CHANNEL_SELECTED == ADC_CHANNEL2
	CLR_PIN(ADMUX,0);
	SET_PIN(ADMUX,1);
	CLR_PIN(ADMUX,2);
	CLR_PIN(ADMUX,3);
	CLR_PIN(ADMUX,4);
#elif ADC_CHANNEL_SELECTED == ADC_CHANNEL3
	SET_PIN(ADMUX,0);
	SET_PIN(ADMUX,1);
	CLR_PIN(ADMUX,2);
	CLR_PIN(ADMUX,3);
	CLR_PIN(ADMUX,4);
#elif ADC_CHANNEL_SELECTED == ADC_CHANNEL4
	CLR_PIN(ADMUX,0);
	CLR_PIN(ADMUX,1);
	SET_PIN(ADMUX,2);
	CLR_PIN(ADMUX,3);
	CLR_PIN(ADMUX,4);
#elif ADC_CHANNEL_SELECTED == ADC_CHANNEL5
	SET_PIN(ADMUX,0);
	CLR_PIN(ADMUX,1);
	SET_PIN(ADMUX,2);
	CLR_PIN(ADMUX,3);
	CLR_PIN(ADMUX,4);
#elif ADC_CHANNEL_SELECTED == ADC_CHANNEL6
	CLR_PIN(ADMUX,0);
	SET_PIN(ADMUX,1);
	SET_PIN(ADMUX,2);
	CLR_PIN(ADMUX,3);
	CLR_PIN(ADMUX,4);
#elif ADC_CHANNEL_SELECTED == ADC_CHANNEL7
	SET_PIN(ADMUX,0);
	SET_PIN(ADMUX,1);
	SET_PIN(ADMUX,2);
	CLR_PIN(ADMUX,3);
	CLR_PIN(ADMUX,4);
#endif

#if ADC_MODE == ADC_NORMAL
	ClR_PIN(ADCSRA,5);
#elif ADC_MODE == ADC_AUTO_TRIGGER
	SET_PIN(ADCSRA,5);
#endif

#if ADC_INTERRUPT == ADC_INTERRUPT_ENABLE
	SET_PIN(ADCSRA,3);
#elif ADC_INTERRUPT == ADC_INTERRUPT_DISABLE
	CLR_PIN(ADCSRA,3);
#endif

#if ADC_PRESCALLER == ADC_PRESCALLER2
	SET_PIN(ADCSRA,0);
	CLR_PIN(ADCSRA,1);
	CLR_PIN(ADCSRA,2);
#elif ADC_PRESCALLER == ADC_PRESCALLER4
	CLR_PIN(ADCSRA,0);
	SET_PIN(ADCSRA,1);
	CLR_PIN(ADCSRA,2);
#elif ADC_PRESCALLER == ADC_PRESCALLER8
	SET_PIN(ADCSRA,0);
	SET_PIN(ADCSRA,1);
	CLR_PIN(ADCSRA,2);
#elif ADC_PRESCALLER == ADC_PRESCALLER16
	CLR_PIN(ADCSRA,0);
	CLR_PIN(ADCSRA,1);
	SET_PIN(ADCSRA,2);
#elif ADC_PRESCALLER == ADC_PRESCALLER32
	SET_PIN(ADCSRA,0);
	CLR_PIN(ADCSRA,1);
	SET_PIN(ADCSRA,2);
#elif ADC_PRESCALLER == ADC_PRESCALLER64
	CLR_PIN(ADCSRA,0);
	SET_PIN(ADCSRA,1);
	SET_PIN(ADCSRA,2);
#elif ADC_PRESCALLER == ADC_PRESCALLER128
	SET_PIN(ADCSRA,0);
	SET_PIN(ADCSRA,1);
	SET_PIN(ADCSRA,2);
#endif

SET_PIN(ADCSRA,7);

}



uint16 ADC_READ()
{
    uint16 Data;
	SET_PIN(ADCSRA,6);

  while(GET_PIN(ADCSRA,4)==0);

  Data = ADC_ADJUST;


	return Data;
}

