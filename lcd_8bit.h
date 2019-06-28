
#ifndef _LCD_8BIT_H
#define _LCD_8BIT_H

#include "reg.h"

#define ON 1
#define OFF 0
#define OUTPUT 0
#define INPUT 1

#define LCD_RS PORTC_REG.Register_Bits.Bit0
#define LCD_EN PORTC_REG.Register_Bits.Bit1
#define LCD_RS_DIR TRISC_REG.Register_Bits.Bit0
#define LCD_EN_DIR TRISC_REG.Register_Bits.Bit1
#define LCD_DATA PORTD_REG.Register
#define LCD_DATA_DIR TRISD_REG.Register

static void lcd_send_eneble(void);
void lcd_send_command(uint8_t command);
void lcd_send_data(uint8_t inforamation);
void lcd_initialization(void);
void lcd_write_string(char *ptr_string);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_sed_data_pos(uint8_t row, uint8_t col, char info);
void lcd_sed_string_pos(uint8_t row, uint8_t col, char *info);
void convert_number_char(short number, char *arr);
void lcd_build_customChar(unsigned char loc, const char array[]);

#endif