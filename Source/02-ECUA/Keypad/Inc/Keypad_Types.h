/*
 * Keypad_Types.h
 *
 *  Created on: Sep 2, 2022
 *      Author: faster
 */

#ifndef SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_TYPES_H_
#define SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_TYPES_H_

typedef enum
{
	KP_ROW0,
	KP_ROW1,
	KP_ROW2,
	KP_ROW3,
	KP_NOROW = -1

}KP_row_t;

typedef enum
{
	KP_COL0,
	KP_COL1,
	KP_COL2,
	KP_COL3,
	KP_NOCOLUMN = -1
}KP_column_t;

#endif /* SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_TYPES_H_ */
