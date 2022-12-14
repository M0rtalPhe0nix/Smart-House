/*
 * EXT_INTERRUPT.c
 *
 *  Created on: Sep 3, 2022
 *      Author: AMR ELKOTT
 */
#include "EXT_INTERRUPT.h"


void GLOBAL_INTERRUPT()
{
#if GLOBAL_INTERRUPT_STATUS == GLOBAL_INTERRUPT_ENABLE
	SET_PIN(SREG,7);

#elif 	GLOBAL_INTERRUPT_STATUS == GLOBAL_INTERRUPT_DISABLE
	CLR_PIN(SREG,7);
#endif
}

void EXTERNAL_INT0()
{
SET_PIN(GICR,6);

#if EXTERNAL_INTERRUPT_INT0_STATUS == INTERRUPT_INT0_LOW_LEVEL
CLR_PIN(MCUCR,0);
CLR_PIN(MCUCR,1);

#elif EXTERNAL_INTERRUPT_INT0_STATUS == INTERRUPT_INT0_LOGICAL_CHANGE
SET_PIN(MCUCR,0);
CLR_PIN(MCUCR,0);

#elif EXTERNAL_INTERRUPT_INT0_STATUS == INTERRUPT_INT0_RISING_EDGE
SET_PIN(MCUCR,0);
SET_PIN(MCUCR,1);

#elif EXTERNAL_INTERRUPT_INT0_STATUS == INTERRUPT_INT0_FALLING_EDGE
CLR_PIN(MCUCR,0);
SET_PIN(MCUCR,1);

#endif
}



void EXTERNAL_INT1()
{
SET_PIN(GICR,7);

#if EXTERNAL_INTERRUPT_INT1_STATUS == INTERRUPT_INT1_LOW_LEVEL
CLR_PIN(MCUCR,0);
CLR_PIN(MCUCR,1);

#elif EXTERNAL_INTERRUPT_INT1_STATUS == INTERRUPT_INT1_LOGICAL_CHANGE
SET_PIN(MCUCR,0);
CLR_PIN(MCUCR,0);

#elif EXTERNAL_INTERRUPT_INT1_STATUS == INTERRUPT_INT1_RISING_EDGE
SET_PIN(MCUCR,0);
SET_PIN(MCUCR,1);

#elif EXTERNAL_INTERRUPT_INT1_STATUS == INTERRUPT_INT1_FALLING_EDGE
CLR_PIN(MCUCR,0);
SET_PIN(MCUCR,1);

#endif
}


void EXTERNAL_INT2()
{
	 SET_PIN(GICR,5);

	#if EXTERNAL_INTERRUPT_INT2_STATUS == INTERRUPT_INT2_RISING_EDGE
	 SET_BIT(MCUSCR,6);


	#elif EXTERNAL_INTERRUPT_INT2_STATUS == INTERRUPT_INT2_FALLING_EDGE
	 CLR_PIN(MCUCSR,6);
	#endif

}
