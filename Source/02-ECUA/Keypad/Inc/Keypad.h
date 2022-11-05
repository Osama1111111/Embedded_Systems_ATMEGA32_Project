/*
 * Keypad.h
 *
 *  Created on: Sep 2, 2022
 *      Author: faster
 */

#ifndef SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_H_
#define SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_H_

#include "Dio.h"

u8 Keypad_layout[4][4] =
	{
		{'1' , '2' , '3' , 'A'},
		{'4' , '5' , '6' , 'B'},
		{'7' , '8' , '9' , 'C'},
		{'*' , '0' , '#' , 'D'}
	};

void Keypad_vidInit (void);
u8 Keypad_u8GetKeypad (void);

#endif /* SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_H_ */
