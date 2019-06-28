
#include "spi.h"

void SPI_Init_Advanced_Lib(spi_mode_ut master_slav, sample_bit_ut data_sample, clock_polarity_ut clock_idle, clock_select_ut transmit_edge){
    if(_SPI_DATA_SAMPLE_MIDDLE_L == data_sample){
        SSPSTAT_REG.Register_Bits.Bit7 = 0; 	// Input data sampled at middle of data output time
    }
    else if(_SPI_DATA_SAMPLE_END_L == data_sample){
        SSPSTAT_REG.Register_Bits.Bit7 = 1; 	// nput data sampled at end of data output time
    }
    //================================================
    if(_SPI_MASTER_OSC_DIV4_L == master_slav){
        SSPCON1_REG.Register_Bits.Bit0 = 0; 	//  SPI Master mode, clock = FOSC/4
        SSPCON1_REG.Register_Bits.Bit1 = 0; 	//  SPI Master mode, clock = FOSC/4
        SSPCON1_REG.Register_Bits.Bit2 = 0; 	//  SPI Master mode, clock = FOSC/4
        SSPCON1_REG.Register_Bits.Bit3 = 0; 	//  SPI Master mode, clock = FOSC/4
    }
    else if(_SPI_MASTER_OSC_DIV16_L == master_slav){
        SSPCON1_REG.Register_Bits.Bit0 = 1;	// SPI Master mode, clock = FOSC/16
        SSPCON1_REG.Register_Bits.Bit1 = 0;	// SPI Master mode, clock = FOSC/16
        SSPCON1_REG.Register_Bits.Bit2 = 0;	// SPI Master mode, clock = FOSC/16
        SSPCON1_REG.Register_Bits.Bit3 = 0;	// SPI Master mode, clock = FOSC/16
    }
    else if(_SPI_MASTER_OSC_DIV64_L == master_slav){
        SSPCON1_REG.Register_Bits.Bit0 = 0;	// SPI Master mode, clock = FOSC/64
        SSPCON1_REG.Register_Bits.Bit1 = 1;	// SPI Master mode, clock = FOSC/64
        SSPCON1_REG.Register_Bits.Bit2 = 0;	// SPI Master mode, clock = FOSC/64
        SSPCON1_REG.Register_Bits.Bit3 = 0;	// SPI Master mode, clock = FOSC/64
    }
    else if(_SPI_MASTER_TMR2_L == master_slav){
        SSPCON1_REG.Register_Bits.Bit0 = 1;	// SPI Master mode, clock = TMR2 output/2
        SSPCON1_REG.Register_Bits.Bit1 = 1;	// SPI Master mode, clock = TMR2 output/2
        SSPCON1_REG.Register_Bits.Bit2 = 0;	// SPI Master mode, clock = TMR2 output/2
        SSPCON1_REG.Register_Bits.Bit3 = 0;	// SPI Master mode, clock = TMR2 output/2
    }
    else if(_SPI_SLAVE_SS_ENABLE_L == master_slav){
        SSPCON1_REG.Register_Bits.Bit0 = 0;	// SPI Slave mode, clock = SCK pin, SS pin control enabled
        SSPCON1_REG.Register_Bits.Bit1 = 0;	// SPI Slave mode, clock = SCK pin, SS pin control enabled
        SSPCON1_REG.Register_Bits.Bit2 = 1;	// SPI Slave mode, clock = SCK pin, SS pin control enabled
        SSPCON1_REG.Register_Bits.Bit3 = 0;	// SPI Slave mode, clock = SCK pin, SS pin control enabled
    }
    else if(_SPI_SLAVE_SS_DIS_L == master_slav){
        SSPCON1_REG.Register_Bits.Bit0 = 1;	// SPI Slave mode, clock = SCK pin, SS pin control disabled
        SSPCON1_REG.Register_Bits.Bit1 = 0;	// SPI Slave mode, clock = SCK pin, SS pin control disabled
        SSPCON1_REG.Register_Bits.Bit2 = 1;	// SPI Slave mode, clock = SCK pin, SS pin control disabled
        SSPCON1_REG.Register_Bits.Bit3 = 0;	// SPI Slave mode, clock = SCK pin, SS pin control disabled
    }
    //================================================
    if(_SPI_CLK_IDLE_HIGH_L == clock_idle && _SPI_LOW_2_HIGH_L == transmit_edge){
        SSPCON1_REG.Register_Bits.Bit4 = 1; 	// Clock LOW_2_HIGH
        SSPSTAT_REG.Register_Bits.Bit6 = 1; 	// Clock LOW_2_HIGH
    }
    else if(_SPI_CLK_IDLE_HIGH_L == clock_idle && _SPI_HIGH_2_LOW_L == transmit_edge){
        SSPCON1_REG.Register_Bits.Bit4 = 1;
        SSPSTAT_REG.Register_Bits.Bit6 = 0;
    }
    else if(_SPI_CLK_IDLE_LOW_L == clock_idle && _SPI_LOW_2_HIGH_L == transmit_edge){
        SSPCON1_REG.Register_Bits.Bit4 = 0;
        SSPSTAT_REG.Register_Bits.Bit6 = 0;
    }
    else if(_SPI_CLK_IDLE_LOW_L == clock_idle && _SPI_HIGH_2_LOW_L == transmit_edge){
        SSPCON1_REG.Register_Bits.Bit4 = 0;
        SSPSTAT_REG.Register_Bits.Bit6 = 1;
    }
    //================================================
    SSPCON1_REG.Register_Bits.Bit5 = 1; // Enables SPI
    //================================================
    if(_SPI_MASTER_OSC_DIV4_L == master_slav || _SPI_MASTER_OSC_DIV16_L == master_slav ||
       _SPI_MASTER_OSC_DIV64_L == master_slav || _SPI_MASTER_TMR2_L == master_slav){
       ADCON1_REG.Register_Bits.Bit2 = 0; 	// A5 Digital
       TRISC_REG.Register_Bits.Bit3 = 0; 	// SCK Output
       TRISC_REG.Register_Bits.Bit4 = 1; 	// SDI Input
       TRISC_REG.Register_Bits.Bit5 = 0; 	// SDO Output
       TRISA_REG.Register_Bits.Bit5 = 0; 	// SS  Output
    }
    else if(_SPI_SLAVE_SS_ENABLE_L == master_slav || _SPI_SLAVE_SS_DIS_L == master_slav){
       ADCON1_REG.Register_Bits.Bit2 = 0; 	// A5 Digital
       TRISC_REG.Register_Bits.Bit3 = 1; 	// SCK Input
       TRISC_REG.Register_Bits.Bit4 = 1; 	// SDI Input
       TRISC_REG.Register_Bits.Bit5 = 0; 	// SDO Output
       TRISA_REG.Register_Bits.Bit5 = 1; 	// SS  Input
    }
    
    T_R_FLAG = _TRANSMISSION_RECEPTION_WAIT; 	// Celar Flag
}


void SPI_Write_Lib(unsigned char val){
    uint8_t data_flush;		// To Clear the Buffer
    SSPBUF_REG.Register = val; 	// Write the value
    while(T_R_FLAG == _TRANSMISSION_RECEPTION_WAIT); // Wait the Flag
    T_R_FLAG = 0; // Clear The Flag
    data_flush = SSPBUF_REG.Register; // Clear the Buffer
    
}

void SPI_Write_String(char *str){
	while(*str){
		SPI_Write_Lib(*str++);
	}
}

unsigned char SPI_Read_Lib(){
    SSPBUF_REG.Register = 0xFF; // Add value to the master to start the receive data
    while(T_R_FLAG == _TRANSMISSION_RECEPTION_WAIT);
    T_R_FLAG = 0;
    return (SSPBUF_REG.Register); // Return the received value
}

void SPI_Read_String(char *str, unsigned char str_len){
	unsigned char len = 0;
	for(len = 0; len < str_len; len++){
		str[len] = SPI_Read_Lib();
	}
}
