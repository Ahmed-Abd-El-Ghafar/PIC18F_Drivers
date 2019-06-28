
#ifndef _MOTOR_H
#define _MOTOR_H

#include "dio.h"

void motor_config(Register_t *reg1, Register_t *reg2, uint8_t val1, uint8_t val2);
void motor_forward(Register_t *reg, uint8_t pin0, uint8_t pin1);
void motor_backword(Register_t *reg, uint8_t pin0, uint8_t pin1);
void motor_stop(Register_t *reg, uint8_t pin0, uint8_t pin1);

#endif