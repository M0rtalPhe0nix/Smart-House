/*
 * AIR_COND.h
 *
 *  Created on: Oct 8, 2022
 *      Author: AMR ELKOTT
 */

#ifndef HALL_AIR_COND_AIR_COND_H_
#define HALL_AIR_COND_AIR_COND_H_

#include "../../MCAL/ADC/ADC.h"
#include "../../MCAL/DIO/DIO.h"


void AIR_COND_Init();
void AIR_COND_TurnON();
void AIR_COND_TurnOFF();
uint16 TEMP_READ();
void AIR_COND();


#endif /* HALL_AIR_COND_AIR_COND_H_ */
