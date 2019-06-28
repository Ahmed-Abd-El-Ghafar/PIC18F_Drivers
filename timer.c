
#include "timer.h"

void timer0_timer_init(void){
    T0CON_REG.Register_Bits.Bit7 = 0;   // Stops Timer0
    T0CON_REG.Register_Bits.Bit6 = 0;   // Timer0 is configured as a 16-bit timer
    T0CON_REG.Register_Bits.Bit5 = 0;   // Timer mode
    T0CON_REG.Register_Bits.Bit4 = 0;   // Not used
    T0CON_REG.Register_Bits.Bit3 = 0;   // prescaler ON
    T0CON_REG.Register_Bits.Bit2 = 0;   // 1:8 Prescale value
    T0CON_REG.Register_Bits.Bit1 = 1;   // 1:8 Prescale value
    T0CON_REG.Register_Bits.Bit0 = 0;   // 1:8 Prescale value
    TMR0L_REG.Register = 0xEE;
    TMR0H_REG.Register = 0x85;
    T0CON_REG.Register_Bits.Bit7 = 1;   // Enables Timer0
}

void timer0_counter_init(void){
    T0CON_REG.Register_Bits.Bit7 = 0;   // Stops Timer0
    T0CON_REG.Register_Bits.Bit6 = 0;   // Timer0 is configured as a 16-bit timer
    T0CON_REG.Register_Bits.Bit5 = 1;   // Counter mode
    T0CON_REG.Register_Bits.Bit4 = 0;   // Increment on low-to-high transition
    T0CON_REG.Register_Bits.Bit3 = 1;   // prescaler OFF
    T0CON_REG.Register_Bits.Bit2 = 0;   // 1:8 Prescale value
    T0CON_REG.Register_Bits.Bit1 = 0;   // 1:8 Prescale value
    T0CON_REG.Register_Bits.Bit0 = 0;   // 1:8 Prescale value
    TMR0L_REG.Register = 0x00;
    TMR0H_REG.Register = 0x00;
    T0CON_REG.Register_Bits.Bit7 = 1;   // Enables Timer0
}

void timer1_timer_init(void){
    T1CON_REG.Register_Bits.Bit0 = 0;   // Stops Timer1
    T1CON_REG.Register_Bits.Bit7 = 0;   // 2 8-bit reg operations
    T1CON_REG.Register_Bits.Bit6 = 0;   // Timer or Counter
    T1CON_REG.Register_Bits.Bit5 = 1;   // 1:8 Prescale value
    T1CON_REG.Register_Bits.Bit4 = 1;   // 1:8 Prescale value
    T1CON_REG.Register_Bits.Bit3 = 0;   // Timer1 oscillator is shut off
    T1CON_REG.Register_Bits.Bit2 = 0;   // Ignored
    T1CON_REG.Register_Bits.Bit1 = 0;   // Timer
    TMR1L_REG.Register = 0xDC;
    TMR1H_REG.Register = 0x0B;
    T1CON_REG.Register_Bits.Bit0 = 1;   // Enables Timer1
}

void timer1_counter_init(void){
    T1CON_REG.Register_Bits.Bit0 = 0;   // Stops Timer1
    T1CON_REG.Register_Bits.Bit7 = 0;   // 2 8-bit reg operations
    T1CON_REG.Register_Bits.Bit6 = 0;   // Timer or Counter
    T1CON_REG.Register_Bits.Bit5 = 0;   // 1:8 Prescale value
    T1CON_REG.Register_Bits.Bit4 = 0;   // 1:8 Prescale value
    T1CON_REG.Register_Bits.Bit3 = 0;   // Timer1 oscillator is shut off
    T1CON_REG.Register_Bits.Bit2 = 1;   // Do not synchronize external clock input
    T1CON_REG.Register_Bits.Bit1 = 1;   // Counter
    TMR1L_REG.Register = 0x00;
    TMR1H_REG.Register = 0x00;
    T1CON_REG.Register_Bits.Bit0 = 1;   // Enables Timer1
}

