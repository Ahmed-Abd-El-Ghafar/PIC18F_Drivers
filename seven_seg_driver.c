
#include "seven_seg_driver.h"

uint8_t seven_seg_values[10] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 144};

void seven_segment_print_port_nuumber_init(Register_Name_t port){
    if(port == PORTA_R){
       TRISA_REG.Register = 0;    // All Reg is Output
       PORTA_REG.Register = 255; // All Port Reg = 255
    }
    else if(port == PORTB_R){
       TRISB_REG.Register = 0;    // All Reg is Output
       PORTB_REG.Register = 255; // All Port Reg = 255
    }
    else if(port == PORTC_R){
       TRISC_REG.Register = 0;    // All Reg is Output
       PORTC_REG.Register = 255; // All Port Reg = 255
    }
    else if(port == PORTD_R){
       TRISD_REG.Register = 0;    // All Reg is Output
       PORTD_REG.Register = 255; // All Port Reg = 255
    }
}

void seven_segment_print_port_nuumber(Register_Name_t port, uint8_t number){
    if(port == PORTA_R){
       PORTA_REG.Register = number;
    }
    else if(port == PORTB_R){
       PORTB_REG.Register = number;
    }
    else if(port == PORTC_R){
       PORTC_REG.Register = number;
    }
    else if(port == PORTD_R){
       PORTD_REG.Register = number;
    }
}

uint8_t convert_number_seven_segement(uint8_t number){
    return (number%10 | ((number/10)<<4));
}

