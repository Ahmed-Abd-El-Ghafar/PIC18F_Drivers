
#ifndef _DIO_H
#define _DIO_H

#include "reg.h"

#define START_BIT (0)
#define ON 1
#define OFF 0

void Digital_Write(Register_t *reg, uint8_t pin, uint8_t status);
void Write_To_register(Register_t *reg, uint8_t value);

#endif