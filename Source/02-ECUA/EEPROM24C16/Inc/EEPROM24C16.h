/*
 * EEPROM24C16.h
 *
 *  Created on: Nov 5, 2022
 *      Author: faster
 */

#ifndef SOURCE_02_ECUA_EEPROM24C16_INC_EEPROM24C16_H_
#define SOURCE_02_ECUA_EEPROM24C16_INC_EEPROM24C16_H_

#include "I2c.h"

void Eeprom24C16_Init(void);
/*	2048 byte	*/
void Eeprom24C16_WriteByte(u16 addr, u8 data);
u8 Eeprom24C16_ReadByte(u16 addr);

#endif /* SOURCE_02_ECUA_EEPROM24C16_INC_EEPROM24C16_H_ */
