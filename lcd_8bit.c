
#include "lcd_8bit.h"

static void lcd_send_eneble(void){
    LCD_EN = ON;
    Delay_us(2);
    LCD_EN = OFF;
    Delay_us(2);
}

void lcd_send_command(char command){
    LCD_RS = OFF;
    LCD_DATA = OFF;
    LCD_DATA = command;
    lcd_send_eneble();
}

void lcd_send_data(char inforamation){
    LCD_RS = ON;
    LCD_DATA = OFF;
    LCD_DATA = inforamation;
    lcd_send_eneble();
}

void lcd_initialization(void){
    LCD_EN_DIR = OUTPUT;
    LCD_RS_DIR = OUTPUT;
    LCD_DATA_DIR = OUTPUT;
    LCD_EN = OFF;
    LCD_RS = OFF;
    LCD_DATA = OFF;
    /////////////////////////////////////   Reset Operation
    Delay_ms(40);
    LCD_DATA = OFF;
    lcd_send_command(0x38); // 8 Bit Mode
    lcd_send_eneble();

    Delay_ms(6);
    LCD_DATA = OFF;
    lcd_send_command(0x38); // 8 Bit Mode
    lcd_send_eneble();
    
    Delay_us(300);
    LCD_DATA = OFF;
    lcd_send_command(0x38); // 8 Bit Mode
    lcd_send_eneble();
    
    lcd_send_command(0x01);  lcd_send_eneble(); Delay_ms(5);
    lcd_send_command(0x02);  lcd_send_eneble(); Delay_ms(5);
    lcd_send_command(0x06);  lcd_send_eneble(); Delay_ms(5);
    lcd_send_command(0x0C);  lcd_send_eneble(); Delay_ms(5);
    lcd_send_command(0x14);  lcd_send_eneble(); Delay_ms(5);
    lcd_send_command(0x38);  lcd_send_eneble(); Delay_ms(5);
    lcd_send_command(0x80); // (1,1)
}

void lcd_write_string(char *ptr_string){
    while(*ptr_string){
       lcd_send_data(*ptr_string++);
       Delay_ms(1);
    }
}

void lcd_set_cursor(uint8_t row, uint8_t col){
    row--;
    col--;
    lcd_send_command((0x80 + ((0x40 * row) + col)));
    Delay_ms(2);
}

void lcd_sed_data_pos(uint8_t row, uint8_t col, char info){
    lcd_set_cursor(row, col);
    lcd_send_data(info);
}

void lcd_sed_string_pos(uint8_t row, uint8_t col, char *info){
    lcd_set_cursor(row, col);
    lcd_write_string(info);
}

void convert_number_char(short number, char *arr){
    if(number < 10){
        arr[0] = number + 0x30;
    }
    else if(number >= 10 && number < 100){
        arr[0] = (number / 10) + 0x30;
        arr[1] = (number % 10) + 0x30;
    }
    else if(number >= 100 && number < 1000){
        arr[0] = (number / 100) + 0x30;
        arr[1] = (number % 100) / 10 + 0x30;
        arr[2] = (number % 100) % 10 + 0x30;
    }
}

void lcd_build_customChar(unsigned char loc, const char array[]){
    short i;
    if(loc < 8){
       lcd_send_command(0x40+(loc * 8));
       for(i=0; i<=7; i++){
          lcd_send_data(array[i]);
       }
       lcd_send_command(0x80);
    }
}
