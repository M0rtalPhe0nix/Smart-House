/*
 * UART.h
 *
 *  Created on: Sep 24, 2022
 *      Author: AMR ELKOTT
 */

#ifndef MCAL_UART_H_
#define MCAL_UART_H_

#include "../../STD_TYPES.h"
#include "../../MACROS.h"
#include "../REGISTERS_ADDRESSES.h"


#define REC_Comp_INTERRUPT_DISABLE 0
#define REC_Comp_INTERRUPT_ENABLE  1

#define TRAN_Comp_INTERRUPT_DISABLE 0
#define TRAN_Comp_INTERRUPT_ENABLE  1

#define Empty_INTERRUPT_DISABLE 0
#define Empty_INTERRUPT_ENABLE  1

#define REC_DISABLE 0
#define REC_ENABLE  1

#define TRAN_DISABLE 0
#define TRAN_ENABLE  1

#define CHAR_SIZE5  0
#define CHAR_SIZE6  1
#define CHAR_SIZE7  2
#define CHAR_SIZE8  3
#define CHAR_SIZE9  4

#define USART_ASYNCH 0
#define USART_SYNCH  1

#define PARITY_DISABLE 0
#define PARITY_EVEN    1
#define PARITY_ODD     2

#define STOP_BIT1  0
#define STOP_BIT2  1




void UART_Init();
void UART_SendByte(uint8 DATA);
uint8 UART_RecByte();
void UART_WriteString(uint8* str);

#endif /* MCAL_UART_H_ */
