/*
 * SSD.h
 *
 *  Created on: Aug 30, 2022
 *      Author: faster
 */

#ifndef SOURCE_02_ECUA_SSD_INC_SSD_H_
#define SOURCE_02_ECUA_SSD_INC_SSD_H_

#include "Std_Types.h"
#define SSD_MASK  (0x0F)

void SSD_vidInit(void);
void SSD_viddisplyNum(u8 num);
void SSD_viddelayWithDisplay_ms(u8 num , u32 delay);

#endif /* SOURCE_02_ECUA_SSD_INC_SSD_H_ */
