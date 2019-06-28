
#include "eeprom.h"
#include "interrupt.h"

void eeprom_write(uint16_t address, uint8_t ee_data){
   EEADR_REG.Register = address & 0x00FF;
   EEADRH_REG.Register = (address & 0xFF00) >> 8;
   EEDATA_REG.Register = ee_data;
   EECON1_REG.Register_Bits.Bit2 = 1;
   enable_global_interrupt(INTERRUPT_DISABLE);
   EECON2_REG.Register = 0x55;
   EECON2_REG.Register = 0xAA;
   EECON1_REG.Register_Bits.Bit1 = 1;
   EECON1_REG.Register_Bits.Bit2 = 0;
   while(PIR2_REG.Register_Bits.Bit4 == 0);
   PIR2_REG.Register_Bits.Bit4 = 0;
}

uint8_t eeprom_read(uint16_t address){
   EEADR_REG.Register = address & 0x00FF;
   EEADRH_REG.Register = (address & 0xFF00) >> 8;
   EECON1_REG.Register_Bits.Bit7 = 0;
   EECON1_REG.Register_Bits.Bit0 = 1;
   return EEDATA_REG.Register;
}

void eeprom_write_string(uint16_t address, uint8_t *str, uint8_t str_len){
    uint8_t index = 0;
    for(index=0; index<str_len; index++){
        eeprom_write(address++, *str++);
    }
}