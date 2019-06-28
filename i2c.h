#ifndef _I2C_H
#define _I2C_H

#include "reg.h"

#define _TRANSMISSION_RECEPTION_WAIT 0
#define _TRANSMISSION_RECEPTION_DONE 1

#define ACK_NOT_RECEIVED 1
#define ACK_RECEIVED     0

/* The Def of flag bit */
#define T_R_FLAG    PIR1_REG.Register_Bits.Bit3
#define ACK_STATUS  SSPCON2_REG.Register_Bits.Bit6

#define SLEW_RATE_CONTROL SSPSTAT_REG.Register_Bits.Bit7
#define SLEW_RATE_CONTROL_DISABLED 1
#define SLEW_RATE_CONTROL_ENABLED  0

#define SMBUS_CONTROL	  SSPSTAT_REG.Register_Bits.Bit6
#define SMBUS_CONTROL_DISABLED 0
#define SMBUS_CONTROL_ENABLED  1

typedef enum{
    NACK,
    ACK
}Ack_Nack_t;

typedef enum{
    TRANSMIT_RECEIVE_BUFFER_EMPTY,
	TRANSMIT_RECEIVE_BUFFER_FULL
}Buffer_Transmit_Receive_t;

typedef enum{
	I2C_SLAVE_MODE_7BIT_ADDRESS,
	I2C_SLAVE_MODE_10BIT_ADDRESS,
	I2C_SLAVE_MODE_7BIT_ADDRESS_START_STOP_IE,
	I2C_SLAVE_MODE_10BIT_ADDRESS_START_STOP_SSIE,
	I2C_MASTER_MODE,
	I2C_FIRMWARE_MASTER_MODE_CONTROLLED_SLAVE_IDLE
}I2c_Mode_t;

void I2C1_Init(const unsigned long clock);
void I2C_Ready(void);
unsigned short I2C1_Start(void);
void I2C1_Repeated_Start(void);
unsigned short I2C1_Is_Idle(void);
unsigned short I2C1_Rd(Ack_Nack_t status);
unsigned short I2C1_Wr(unsigned short data_);
void I2C1_Stop(void);
void Ack_Nack(Ack_Nack_t status);

#endif