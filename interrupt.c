#include "interrupt.h"
#include "dio.h"

void interrupt_priority_en_ds(_Interrupt_Pr_T state){
    if(state == INTERRUPT_PR_ENABLE){
       RCON_REG.Register_Bits.Bit7 = ENABLE; // Enable priority levels
    }
    else if(state == INTERRUPT_PR_DISABLE){
       RCON_REG.Register_Bits.Bit7 = DISABLE; // Disable priority levels
    }
}

void enable_global_interrupt(_Interrupt_ED_T state){
    if(state == INTERRUPT_ENABLE){
      INTCON_REG.Register_Bits.Bit7 = ENABLE;   // Global Interrupt Enable
    }
    else if(state == INTERRUPT_DISABLE){
       INTCON_REG.Register_Bits.Bit7 = DISABLE; // Global Interrupt Disable
    }
}

void enable_Peripherals_interrupt(_Interrupt_ED_T state){
    if(state == INTERRUPT_ENABLE){
      INTCON_REG.Register_Bits.Bit6 = ENABLE;   // Peripheral Interrupt Enable
    }
    else if(state == INTERRUPT_DISABLE){
       INTCON_REG.Register_Bits.Bit6 = DISABLE; // Peripheral Interrupt Disable
    }
}

void enable_disable_interrupts(_Interrupt_ED_T i_state, _Interrupt_Pr_T p_state){
    if(i_state == INTERRUPT_ENABLE){
        if(p_state == INTERRUPT_PR_ENABLE){
           interrupt_priority_en_ds(INTERRUPT_PR_ENABLE);
        }
        else if(p_state == INTERRUPT_PR_DISABLE){
           interrupt_priority_en_ds(INTERRUPT_PR_DISABLE);
        }
        enable_global_interrupt(INTERRUPT_ENABLE);
        enable_Peripherals_interrupt(INTERRUPT_ENABLE);
    }
    else{
        enable_global_interrupt(INTERRUPT_DISABLE);
        enable_Peripherals_interrupt(INTERRUPT_DISABLE);
    }
}

void external_interrupt_enable_disable(_External_Interrupt_T type, _Interrupt_ED_T state, _External_Edge_T edge_state, _Interrupt_Priority_T p_state){
    if(INTERRUPT_INT0 == type){
        if(state == INTERRUPT_ENABLE){
            if(edge_state == RISING_EDGE){
                INTCON2_REG.Register_Bits.Bit6 = ENABLE; // Interrupt on rising edge
            }
            else if(edge_state == FALLING_EDGE){
                INTCON2_REG.Register_Bits.Bit6 = DISABLE;// Interrupt on falling edge
            }
            INTCON_REG.Register_Bits.Bit4 = ENABLE; // Enables the INT0 external interrupt
            INTCON_REG.Register_Bits.Bit1 = DISABLE;//  The INT0 external interrupt did not occur
        }
        else{
            INTCON_REG.Register_Bits.Bit4 = DISABLE; // DISABLE the INT0 external interrupt
        }
    }
    else if(INTERRUPT_INT1 == type){
        if(state == INTERRUPT_ENABLE){
            if(edge_state == RISING_EDGE){
               INTCON2_REG.Register_Bits.Bit5 = ENABLE; // Interrupt on rising edge
            }
            else if(edge_state == FALLING_EDGE){
               INTCON2_REG.Register_Bits.Bit5 = DISABLE;// Interrupt on falling edge
            }
            if(p_state == INTERRUPT_HIGH_P){
               INTCON3_REG.Register_Bits.Bit6 = ENABLE; // // Interrupt on High priority
            }
            else if(p_state == INTERRUPT_LOW_P){
               INTCON3_REG.Register_Bits.Bit6 = DISABLE;// // Interrupt on Low priority
            }
            INTCON3_REG.Register_Bits.Bit3 = ENABLE; // Enables the INT1 external interrupt
            INTCON3_REG.Register_Bits.Bit0 = DISABLE;//  The INT1 external interrupt did not occur
        }
        else{
            INTCON3_REG.Register_Bits.Bit3 = DISABLE; // DISABLE the INT1 external interrupt
        }
    }
    else if(INTERRUPT_INT2 == type){
        if(state == INTERRUPT_ENABLE){
            if(edge_state == RISING_EDGE){
               INTCON2_REG.Register_Bits.Bit4 = ENABLE; // Interrupt on rising edge
            }
            else if(edge_state == FALLING_EDGE){
               INTCON2_REG.Register_Bits.Bit4 = DISABLE;// Interrupt on falling edge
            }
            if(p_state == INTERRUPT_HIGH_P){
               INTCON3_REG.Register_Bits.Bit7 = ENABLE; // Interrupt on High priority
            }
            else if(p_state == INTERRUPT_LOW_P){
               INTCON3_REG.Register_Bits.Bit7 = DISABLE;// Interrupt on LOW priority
            }
            INTCON3_REG.Register_Bits.Bit4 = ENABLE; // Enables the INT2 external interrupt
            INTCON3_REG.Register_Bits.Bit1 = DISABLE;//  The INT2 external interrupt did not occur
        }
        else{
            INTCON3_REG.Register_Bits.Bit4 = DISABLE; // DISABLE the INT2 external interrupt
        }
    }
}

void Enable_disable_portb_pull_up(_Interrupt_Pr_T status){
    if(ENABLE == status){
       INTCON2_REG.Register_Bits.Bit7 = 0;
    }
    else{
       INTCON2_REG.Register_Bits.Bit7 = 1;
    }
}

void enable_on_change_interrupt(_On_Change_Interrupt_T interrupt_name, _Interrupt_Priority_T pr_status){
    /* Convert AN8 ~ AN12 from analog to digital pins */
    ADCON1_REG.Register = 0x07;
    /* Convert pins at portb to input */
    switch(interrupt_name){
         case _On_Change_Interrupt_Rb4 : SET_BIT(TRISB_REG.Register, PIN4); break;
         case _On_Change_Interrupt_Rb5 : SET_BIT(TRISB_REG.Register, PIN5); break;
         case _On_Change_Interrupt_Rb6 : SET_BIT(TRISB_REG.Register, PIN6); break;
         case _On_Change_Interrupt_Rb7 : SET_BIT(TRISB_REG.Register, PIN7); break;
    }
    /* Configure interrupt */
    INTCON_REG.Register_Bits.Bit3 = 1;  // Enables the RB port change interrupt
    INTCON_REG.Register_Bits.Bit0 = 0;  // The RB7:RB4 pins not changed state
    if(INTERRUPT_HIGH_P == pr_status){
       INTCON2_REG.Register_Bits.Bit0 = 1;  // High priority
    }
    else{
       INTCON2_REG.Register_Bits.Bit0 = 0;  // Low priority
    }
}





