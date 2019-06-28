
#ifndef _UART_H
#define _UART_H

#include "reg.h"



void uart_initialization(void);
void uart_send_data(char data_to_send);
char uart_receive_data(void);
char uart_receive_data_ready(void);



#endif