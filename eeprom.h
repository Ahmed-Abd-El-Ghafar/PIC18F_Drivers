
#ifndef _EEPROM_H
#define _EEPROM_H

#include "reg.h"

void eeprom_write(uint16_t address, uint8_t ee_data);
uint8_t eeprom_read(uint16_t address);
void eeprom_write_string(uint16_t address, uint8_t *str, uint8_t str_len);

#endif