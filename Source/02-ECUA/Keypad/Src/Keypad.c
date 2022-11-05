/*
 * Keypad.c
 *
 *  Created on: Sep 2, 2022
 *      Author: faster
 */
#include "Keypad.h"
#include "Keypad_Types.h"

void Keypad_vidInit (void)
{
	// configure rows pins as input
	Dio_vidconfigChanel(DIO_PORTC ,DIO_PIN0 , DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTC ,DIO_PIN1 , DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTC ,DIO_PIN2 , DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTC ,DIO_PIN3 , DIO_INPUT);

	//configure Columns pins as outputs
	Dio_vidconfigChanel(DIO_PORTC ,DIO_PIN4 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTC ,DIO_PIN5 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTC ,DIO_PIN6 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTC ,DIO_PIN7 , DIO_OUTPUT);

	Dio_vidPullUpEnalple(DIO_PORTC , DIO_PIN0);
	Dio_vidPullUpEnalple(DIO_PORTC , DIO_PIN1);
	Dio_vidPullUpEnalple(DIO_PORTC , DIO_PIN2);
	Dio_vidPullUpEnalple(DIO_PORTC , DIO_PIN3);

	//initialize columns as zero
	Dio_vidWriteChanelGroup(DIO_PORTC , DIO_PIN4 , DIO_LOW);
	Dio_vidWriteChanelGroup(DIO_PORTC , DIO_PIN5 , DIO_LOW);
	Dio_vidWriteChanelGroup(DIO_PORTC , DIO_PIN6 , DIO_LOW);
	Dio_vidWriteChanelGroup(DIO_PORTC , DIO_PIN7 , DIO_LOW);

}

static boolean Keypad_IsPressed(void)
{
	if (
			Dio_udtreadChanel(DIO_PORTC , DIO_PIN0) == DIO_LOW  ||
			Dio_udtreadChanel(DIO_PORTC , DIO_PIN1) == DIO_LOW  ||
			Dio_udtreadChanel(DIO_PORTC , DIO_PIN2) == DIO_LOW  ||
			Dio_udtreadChanel(DIO_PORTC , DIO_PIN3) == DIO_LOW
		)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

static KP_row_t Keypad_GetRow(void)
{
	KP_row_t loc_Button = KP_NOROW;
	if (Dio_udtreadChanel(DIO_PORTC , DIO_PIN0) == DIO_LOW)
	{
		loc_Button = KP_ROW0;
	}
	else if (Dio_udtreadChanel(DIO_PORTC , DIO_PIN0) == DIO_LOW)
	{
		loc_Button = KP_ROW1;
	}
	else if (Dio_udtreadChanel(DIO_PORTC , DIO_PIN0) == DIO_LOW)
	{
		loc_Button = KP_ROW2;
	}
	else if (Dio_udtreadChanel(DIO_PORTC , DIO_PIN0) == DIO_LOW)
	{
		loc_Button = KP_ROW3;
	}
	else
	{
		KP_row_t loc_Button = KP_NOROW;
	}

	return loc_Button;
}

static KP_column_t Keypad_GetColumn(KP_row_t current_row)
{
	KP_column_t loc_ButtonCol = KP_NOCOLUMN;

	Dio_vidwriteChanel(DIO_PORTC , DIO_PIN0 , DIO_LOW);
	Dio_vidwriteChanel(DIO_PORTC , DIO_PIN1 , DIO_HIGH);
	Dio_vidwriteChanel(DIO_PORTC , DIO_PIN2 , DIO_HIGH);
	Dio_vidwriteChanel(DIO_PORTC , DIO_PIN3 , DIO_HIGH);

	if (Keypad_GetRow() == current_row)
	{
		loc_ButtonCol = KP_COL0;
	}
	else
	{
		Dio_vidwriteChanel(DIO_PORTC , DIO_PIN0 , DIO_HIGH);
		Dio_vidwriteChanel(DIO_PORTC , DIO_PIN1 , DIO_LOW);
		Dio_vidwriteChanel(DIO_PORTC , DIO_PIN2 , DIO_HIGH);
		Dio_vidwriteChanel(DIO_PORTC , DIO_PIN3 , DIO_HIGH);

		if (Keypad_GetRow() == current_row)
		{
			loc_ButtonCol = KP_COL1;
		}
		else
		{
			Dio_vidwriteChanel(DIO_PORTC , DIO_PIN0 , DIO_HIGH);
			Dio_vidwriteChanel(DIO_PORTC , DIO_PIN1 , DIO_HIGH);
			Dio_vidwriteChanel(DIO_PORTC , DIO_PIN2 , DIO_LOW);
			Dio_vidwriteChanel(DIO_PORTC , DIO_PIN3 , DIO_HIGH);

			if (Keypad_GetRow() == current_row)
			{
				loc_ButtonCol = KP_COL2;
			}
			else
			{
				Dio_vidwriteChanel(DIO_PORTC , DIO_PIN0 , DIO_HIGH);
				Dio_vidwriteChanel(DIO_PORTC , DIO_PIN1 , DIO_HIGH);
				Dio_vidwriteChanel(DIO_PORTC , DIO_PIN2 , DIO_HIGH);
				Dio_vidwriteChanel(DIO_PORTC , DIO_PIN3 , DIO_LOW);

				if (Keypad_GetRow() == current_row)
				{
					loc_ButtonCol = KP_COL3;
				}
				else
				{
					KP_column_t loc_ButtonCol = KP_NOCOLUMN;
				}
			}
		}
	}
	return loc_ButtonCol;
}

u8 Keypad_u8GetKeypad (void)
{
	u8 Loc_Key = 0xFF;
	KP_row_t loc_Row = KP_NOROW;
	KP_row_t loc_Col = KP_NOCOLUMN;

	Keypad_vidInit(); // to return the keypad to original case after first press

	// check if the keypad is pressed or not
	if (Keypad_IsPressed() == TRUE)
	{
		//get pressed key row
		loc_Row = Keypad_GetRow();

		//get pressed key column
		loc_Col = Keypad_GetColumn(loc_Row);

		// loc_key = keypad_layout [row] [column]
		Loc_Key = Keypad_layout [loc_Row][loc_Col];
	}
	else
	{
		//do nothing
		Loc_Key = 0xFF;
	}
	return Loc_Key;
}
