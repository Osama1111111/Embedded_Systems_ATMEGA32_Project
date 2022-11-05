/*
 * SSD.c
 *
 *  Created on: Aug 30, 2022
 *      Author: faster
 */
#include "SSD.h"
#include "Dio.h"
#include <util/delay.h>
#include "Std_Types.h"


void SSD_vidInit(void)
{
	Dio_vidconfigChanel(DIO_PORTB , DIO_PIN1 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTB , DIO_PIN2 , DIO_OUTPUT);

	Dio_vidconfigChanel(DIO_PORTA , DIO_PIN4 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA , DIO_PIN5 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA , DIO_PIN6 , DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA , DIO_PIN7 , DIO_OUTPUT);
}
void SSD_viddisplyNum(u8 num)
{
	//Dio_vidWriteChanelGroup(DIO_PORTA , 5);

	//num = 25
	u8 loc_secondDigit = (num%10) <<4; //to shift 4 bits to the left
	u8 loc_firstDigit = (num/10) <<4;

	// ENable SSD 1 -> EN1 = HIGH
	Dio_vidwriteChanel(DIO_PORTB , DIO_PIN2 , DIO_HIGH);
	// Disable SSD 2 -> EN2 = LOW
	Dio_vidwriteChanel(DIO_PORTB , DIO_PIN1 , DIO_LOW);
	// Write first digit
	Dio_vidWriteChanelGroup( DIO_PORTA , loc_firstDigit , SSD_MASK);
	_delay_us(500);

	// ENable SSD 1 -> EN1 = LOW
	Dio_vidwriteChanel(DIO_PORTB , DIO_PIN2 , DIO_LOW);
	// Disable SSD 2 -> EN2 = HIGH
	Dio_vidwriteChanel(DIO_PORTB , DIO_PIN1 , DIO_HIGH);
	// Write second digit
	Dio_vidWriteChanelGroup( DIO_PORTA , loc_secondDigit , SSD_MASK);
	_delay_us(500);
}
void SSD_viddelayWithDisplay_ms(u8 num , u32 delay)
{
	u32 loc_iter = 0;
	for (loc_iter=0 ; loc_iter<delay ; loc_iter++)
	{
		SSD_viddisplyNum(num);
	}
}
