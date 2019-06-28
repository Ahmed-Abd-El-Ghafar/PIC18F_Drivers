
#include "dio.h"

void Digital_Write(Register_t *reg, uint8_t pin, uint8_t status){
    if(status == ON){
        reg->Register |= (1 << pin);
    }
    else{
        reg->Register &= ~(1 << pin);
    }
}

void Write_To_register(Register_t *reg, uint8_t value){
    reg->Register = value;
}