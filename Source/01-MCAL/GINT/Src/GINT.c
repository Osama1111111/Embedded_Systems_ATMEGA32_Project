/*
 * GINT.c
 *
 *  Created on: Sep 3, 2022
 *      Author: faster
 */


#include "GINT_Reg.h"
#include "GINT.h"
#include "Bit_Math.h"


void GINT_vidEnableAllInetrrupts (void)
{
	SET_BIT(GINT_SREG_REG , 7);
}

void GINT_vidDisableAllInetrrupts (void)
{
	CLEAR_BIT(GINT_SREG_REG , 7);
}
