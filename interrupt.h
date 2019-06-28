
#ifndef _INTERRUPT_H
#define _INTERRUPT_H

#include "reg.h"

#define ENABLE  1
#define DISABLE 0

#define INT0_FLAG INTCON_REG.Register_Bits.Bit1
#define INT1_FLAG INTCON3_REG.Register_Bits.Bit0
#define INT2_FLAG INTCON3_REG.Register_Bits.Bit1
#define RB_FLAG   INTCON_REG.Register_Bits.Bit0

#define RB4_INTERRUPT_PIN PORTB_REG.Register_Bits.Bit4
#define RB4_INTERRUPT_PIN PORTB_REG.Register_Bits.Bit5
#define RB4_INTERRUPT_PIN PORTB_REG.Register_Bits.Bit6
#define RB4_INTERRUPT_PIN PORTB_REG.Register_Bits.Bit7

typedef enum{
    INTERRUPT_PR_ENABLE,
    INTERRUPT_PR_DISABLE
}_Interrupt_Pr_T;

typedef enum{
    INTERRUPT_ENABLE,
    INTERRUPT_DISABLE
}_Interrupt_ED_T;

typedef enum{
    INTERRUPT_INT0,
    INTERRUPT_INT1,
    INTERRUPT_INT2
}_External_Interrupt_T;

typedef enum{
    RISING_EDGE,
    FALLING_EDGE
}_External_Edge_T;

typedef enum{
    INTERRUPT_HIGH_P,
    INTERRUPT_LOW_P
}_Interrupt_Priority_T;

typedef enum{
    _On_Change_Interrupt_Rb4,
    _On_Change_Interrupt_Rb5,
    _On_Change_Interrupt_Rb6,
    _On_Change_Interrupt_Rb7,
}_On_Change_Interrupt_T;

void interrupt_priority_en_ds(_Interrupt_Pr_T state);
void enable_global_interrupt(_Interrupt_ED_T state);
void enable_Peripherals_interrupt(_Interrupt_ED_T state);
void enable_disable_interrupts(_Interrupt_ED_T i_state, _Interrupt_Pr_T p_state);
void external_interrupt_enable_disable(_External_Interrupt_T type, _Interrupt_ED_T state, _External_Edge_T edge_state, _Interrupt_Priority_T p_state);
void Enable_disable_portb_pull_up(_Interrupt_Pr_T status);
void enable_on_change_interrupt(_On_Change_Interrupt_T interrupt_name, _Interrupt_Priority_T pr_status);

#endif