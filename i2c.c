
#include "i2c.h"

void I2C_Ready(void){
    /* Wait for operation complete */
    while(T_R_FLAG == _TRANSMISSION_RECEPTION_WAIT);
    T_R_FLAG = 0;  // Clear SSPIF interrupt flag
}

unsigned short I2C1_Wr(unsigned short data_){
    SSPBUF_REG.Register = data_;
    I2C_Ready();
    if(ACK_STATUS == ACK_NOT_RECEIVED){
       return ACK_NOT_RECEIVED;
    }
    else if(ACK_STATUS == ACK_RECEIVED){
       return ACK_RECEIVED;
    }
}

unsigned short I2C1_Start(void){

}

void I2C1_Repeated_Start(void){

}

void I2C1_Stop(void){
    I2C_Ready();
}

void Ack_Nack(Ack_Nack_t status){
    if(status == ACK){ // Acknowledgement
       SSPCON2_REG.Register_Bits.Bit5 = 0;
    }
    else if(status == NACK){  // Negative Acknowledgement
       SSPCON2_REG.Register_Bits.Bit5 = 1;
    }
    // Initiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit.
    SSPCON2_REG.Register_Bits.Bit4 = 1;
    /* Automatically cleared by hardware. */
    while(SSPCON2_REG.Register_Bits.Bit4 == 1);
}

unsigned short I2C1_Rd(Ack_Nack_t status){
    if(status == ACK){
       Ack_Nack(ACK);
    }
    if(status == NACK){
       Ack_Nack(NACK);
    }
    I2C_Ready();
    return(SSPBUF_REG.Register);
}

