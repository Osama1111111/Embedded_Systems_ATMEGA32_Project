/*
 * LM35.c
 *
 *  Created on: Sep 9, 2022
 *      Author: faster
 */

#include "LM35.h"

void LM35_vidInit(void)
{
	ADC_vidInit();
}

u16 LM35_u16TempRead(void)
{
	f64 loc_adcRead =0;
	u16 loc_temp =0;

	loc_adcRead = ADC_f64ADCRead (ADC_CHANNEL1);
	loc_temp = loc_adcRead / 10;

	return loc_temp;
}
