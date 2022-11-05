/*
 * Spi.h
 *
 *  Created on: Nov 5, 2022
 *      Author: faster
 */

#ifndef SOURCE_01_MCAL_SPI_INC_SPI_H_
#define SOURCE_01_MCAL_SPI_INC_SPI_H_

#include "Spi_Reg.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Dio.h"

#define SPI_SCK_FREQ_FCPU_DIV_4			(0<<0)
#define SPI_SCK_FREQ_FCPU_DIV_16		(1<<0)
#define SPI_SCK_FREQ_FCPU_DIV_64		(2<<0)
#define SPI_SCK_FREQ_FCPU_DIV_128		(3<<0)

#define SPI_SPE_BIT_NO           	(6)
#define SPI_MSTR_BIT_NO				(4)
#define SPI_SPIF_BIT_NO				(7)

void Spi_vidMasterInit(void);
void Spi_vidSlaveInit(void);
void Spi_MasterWrite(u8 data);
u8 Spi_u8MasterRead(void);
u8 Spi_u8MasterTranseve(u8 data);

u8 Spi_u8SlaveRead(void);
void Spi_vidSlaveWrite(u8 data);

#endif /* SOURCE_01_MCAL_SPI_INC_SPI_H_ */
