/*
 * ADC.h
 *
 *  Created on: Sep 23, 2022
 *      Author: AMR ELKOTT
 */

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

#include "../../MACROS.h"
#include "../../MCAL/ADC/ADC_CFG.h"
#include "../../MCAL/REGISTERS_ADDRESSES.h"
#include "../../STD_TYPES.h"


#define ADC_VREF_AREF     0
#define ADC_VREF_AVCC     1
#define ADC_VREF_INTERNAL 2

#define ADC_RIGHT_ADJUST  0
#define ADC_LEFT_ADJUST   1

#define ADC_CHANNEL0 0
#define ADC_CHANNEL1 1
#define ADC_CHANNEL2 2
#define ADC_CHANNEL3 3
#define ADC_CHANNEL4 4
#define ADC_CHANNEL5 5
#define ADC_CHANNEL6 6
#define ADC_CHANNEL7 7

#define ADC_NORMAL       0
#define ADC_AUTO_TRIGGER 1

#define ADC_INTERRUPT_DISABLE 0
#define ADC_INTERRUPT_ENABLE  1

#define ADC_PRESCALLER2   0
#define ADC_PRESCALLER4   1
#define ADC_PRESCALLER8   2
#define ADC_PRESCALLER16  3
#define ADC_PRESCALLER32  4
#define ADC_PRESCALLER64  5
#define ADC_PRESCALLER128 6




void ADC_Init();
uint16 ADC_READ();


#endif /* MCAL_ADC_H_ */
