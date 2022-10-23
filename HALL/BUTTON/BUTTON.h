/*
 * BUTTON.h
 *
 *  Created on: Aug 27, 2022
 *      Author: AMR ELKOTT
 */

#ifndef HALL_BUTTON_H_
#define HALL_BUTTON_H_

#include "../../MCAL/DIO/DIO.h"
#include "BUTTON_CFG.h"

void BUTTON0_Init();
uint8 BUTTON0_READ();

void BUTTON1_Init();
uint8 BUTTON1_READ();

void BUTTON2_Init();
uint8 BUTTON2_READ();

#endif /* HALL_BUTTON_H_ */
