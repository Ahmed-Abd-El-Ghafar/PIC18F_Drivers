
#include "uart.h"

void uart_initialization(void){
    RCSTA_REG.Register_Bits.Bit7 = 1; // As per DataSheet
    TRISC_REG.Register_Bits.Bit7 = 1; // As per DataSheet
    TRISC_REG.Register_Bits.Bit6 = 1; // As per DataSheet
    // ==============================
    TXSTA_REG.Register_Bits.Bit6 = 0; // Selects 8-bit transmission
    TXSTA_REG.Register_Bits.Bit5 = 1; // Transmit enabled
    TXSTA_REG.Register_Bits.Bit4 = 0; // Asynchronous mode
    TXSTA_REG.Register_Bits.Bit2 = 1; // High speed
    // ==============================
    RCSTA_REG.Register_Bits.Bit7 = 1; // Serial port enabled
    RCSTA_REG.Register_Bits.Bit6 = 0; // Selects 8-bit reception
    RCSTA_REG.Register_Bits.Bit4 = 1; // Enables receiver
    // ==============================
    BAUDCON_REG.Register_Bits.Bit3 = 0; // 8-bit Baud Rate Generator – SPBRG only
    // ==============================
    SPBRG_REG.Register = 25; // 9600 Bit/sec
}

void uart_send_data(char data_to_send){
    while(TXSTA_REG.Register_Bits.Bit1 == 0);
    TXREG_REG.Register = data_to_send;
}

char uart_receive_data(void){
    return RCREG_REG.Register;
}

char uart_receive_data_ready(void){
   return PIR1_REG.Register_Bits.Bit5;
}

