
#include "motor.h"

void motor_config(Register_t *reg1, Register_t *reg2, uint8_t val1, uint8_t val2){
    Write_To_register(reg1, val1);
    Write_To_register(reg2, val2);
}

void motor_forward(Register_t *reg, uint8_t pin0, uint8_t pin1){
    Digital_Write(reg, pin0, ON);
    Digital_Write(reg, pin1, OFF);
}

void motor_backword(Register_t *reg, uint8_t pin0, uint8_t pin1){
    Digital_Write(reg, pin0, OFF);
    Digital_Write(reg, pin1, ON);
}

void motor_stop(Register_t *reg, uint8_t pin0, uint8_t pin1){
    Digital_Write(reg, pin0, OFF);
    Digital_Write(reg, pin1, OFF);
}
