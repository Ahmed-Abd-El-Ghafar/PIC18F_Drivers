#ifndef _SPI_H
#define _SPI_H

#include "reg.h"

#define _TRANSMISSION_RECEPTION_WAIT 0
#define _TRANSMISSION_RECEPTION_DONE 1
/* The Def of flag bit */
#define T_R_FLAG PIR1_REG.Register_Bits.Bit3

typedef enum{
    _SPI_DATA_SAMPLE_MIDDLE_L,
    _SPI_DATA_SAMPLE_END_L
}sample_bit_ut;

typedef enum{
    _SPI_MASTER_OSC_DIV4_L,
    _SPI_MASTER_OSC_DIV16_L,
    _SPI_MASTER_OSC_DIV64_L,
    _SPI_MASTER_TMR2_L,
    _SPI_SLAVE_SS_ENABLE_L,
    _SPI_SLAVE_SS_DIS_L
}spi_mode_ut;

typedef enum{
    _SPI_CLK_IDLE_HIGH_L,
    _SPI_CLK_IDLE_LOW_L
}clock_polarity_ut;

typedef enum{
    _SPI_LOW_2_HIGH_L,
    _SPI_HIGH_2_LOW_L
}clock_select_ut;

void SPI_Init_Advanced_Lib(spi_mode_ut master_slav, sample_bit_ut data_sample, clock_polarity_ut clock_idle, clock_select_ut transmit_edge);
void SPI_Write_Lib(unsigned char val);
unsigned char SPI_Read_Lib();

#endif