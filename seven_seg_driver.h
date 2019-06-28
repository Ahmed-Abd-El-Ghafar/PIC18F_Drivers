
#ifndef _SEVEN_SEG_DRIVER_H
#define _SEVEN_SEG_DRIVER_H

#include "reg.h"

extern uint8_t seven_seg_values[10];

#define NUMBER0 (192)
#define NUMBER1 (249)
#define NUMBER2 (164)
#define NUMBER3 (176)
#define NUMBER4 (153)
#define NUMBER5 (146)
#define NUMBER6 (130)
#define NUMBER7 (248)
#define NUMBER8 (128)
#define NUMBER9 (144)

typedef enum{
    PORTA_R,
    PORTB_R,
    PORTC_R,
    PORTD_R
}Register_Name_t;

void seven_segment_print_port_nuumber_init(Register_Name_t port);
void seven_segment_print_port_nuumber(Register_Name_t port, uint8_t number);
uint8_t convert_number_seven_segement(uint8_t number);

#endif