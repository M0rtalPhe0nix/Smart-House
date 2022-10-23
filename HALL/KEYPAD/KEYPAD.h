/*
 * KEYPAD.h
 *
 *  Created on: Sep 2, 2022
 *      Author:
 */

#ifndef HALL_KEYPAD_H_
#define HALL_KEYPAD_H_
#include "../../MCAL/DIO/DIO.h"
#include "KEYPAD_cfg.h"

void KeyPad_Init(void);

uint8 KeyPad_GetChar(void);


#endif /* HALL_KEYPAD_H_ */
