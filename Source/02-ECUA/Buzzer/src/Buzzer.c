/*
 * Buzzer.c
 *
 *  Created on: Aug 27, 2022
 *      Author: faster
 */

#include "Dio.h"
#include "Buzzer.h"

void Buzzer_vidinit(void)
{
	Dio_vidconfigChanel(DIO_PORTA, DIO_PIN3 ,DIO_OUTPUT);
}

void Buzzer_vidBuzzerOn(void)
{
	Dio_vidwriteChanel(DIO_PORTA, DIO_PIN3, DIO_HIGH);
}

void Buzzer_vidBuzzerOff(void)
{
	Dio_vidwriteChanel(DIO_PORTA, DIO_PIN3, DIO_LOW);
}

