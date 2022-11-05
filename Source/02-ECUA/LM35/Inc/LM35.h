/*
 * LM35.h
 *
 *  Created on: Sep 9, 2022
 *      Author: faster
 */

#ifndef SOURCE_02_ECUA_LM35_INC_LM35_H_
#define SOURCE_02_ECUA_LM35_INC_LM35_H_

#include "ADC.h"


void LM35_vidInit(void);
u16 LM35_u16TempRead(void);

#endif /* SOURCE_02_ECUA_LM35_INC_LM35_H_ */
