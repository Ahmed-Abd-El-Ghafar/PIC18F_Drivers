
#ifndef _REG_H
#define _REG_H

#define SET_BIT(REG,BIT) (REG |= (1 << BIT))
#define CLEAR_BIT(REG,BIT) (REG &= ~(1 << BIT))
#define TOGGEL_BIT(REG,BIT) (REG ^= (1 << BIT))
#define IS_SET(REG,BIT) (REG &= (1 << BIT))
#define SET_REG(REG) (REG |= (255 << START_BIT))
#define CLEAR_REG(REG) (REG &= ~(255 << START_BIT))
#define TOGGEL_REG(REG) (REG ^= (255 << START_BIT))

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef union{
    uint8_t Register;
    struct{
        uint8_t Bit0 : 1;
        uint8_t Bit1 : 1;
        uint8_t Bit2 : 1;
        uint8_t Bit3 : 1;
        uint8_t Bit4 : 1;
        uint8_t Bit5 : 1;
        uint8_t Bit6 : 1;
        uint8_t Bit7 : 1;
    }Register_Bits;
}Register_t;

#define PIN0 (0)
#define PIN1 (1)
#define PIN2 (2)
#define PIN3 (3)
#define PIN4 (4)
#define PIN5 (5)
#define PIN6 (6)
#define PIN7 (7)

#define ACCESS_TYPE (1)

#if ACCESS_TYPE==0
  #define TRISC_REG (*((volatile uint8_t *)0xF94))
  #define TRISD_REG (*((volatile uint8_t *)0xF95))
  #define PORTC_REG (*((volatile uint8_t *)0xF82))
  #define PORTD_REG (*((volatile uint8_t *)0xF83))
  
#elif ACCESS_TYPE==1
  /* GPIOs */
  #define TRISC_REG     (*((volatile Register_t *)0xF94))
  #define TRISD_REG     (*((volatile Register_t *)0xF95))
  #define TRISB_REG     (*((volatile Register_t *)0xF93))
  #define TRISA_REG     (*((volatile Register_t *)0xF92))
  #define PORTC_REG     (*((volatile Register_t *)0xF82))
  #define PORTD_REG     (*((volatile Register_t *)0xF83))
  #define PORTB_REG     (*((volatile Register_t *)0xF81))
  #define PORTA_REG     (*((volatile Register_t *)0xF80))
  /* USART */
  #define TXSTA_REG     (*((volatile Register_t *)0xFAC))
  #define RCSTA_REG     (*((volatile Register_t *)0xFAB))
  #define BAUDCON_REG   (*((volatile Register_t *)0xFB8))
  #define SPBRG_REG     (*((volatile Register_t *)0xFAF))
  #define SPBRGH_REG    (*((volatile Register_t *)0xFB0))
  #define TXREG_REG     (*((volatile Register_t *)0xFAD))
  #define RCREG_REG     (*((volatile Register_t *)0xFAE))
  /* Timers */
  #define T0CON_REG     (*((volatile Register_t *)0xFD5))
  #define TMR0L_REG     (*((volatile Register_t *)0xFD6))
  #define TMR0H_REG     (*((volatile Register_t *)0xFD7))
  #define T1CON_REG     (*((volatile Register_t *)0xFCD))
  #define TMR1L_REG     (*((volatile Register_t *)0xFCE))
  #define TMR1H_REG     (*((volatile Register_t *)0xFCF))
  /* Interrupts */
  #define RCON_REG      (*((volatile Register_t *)0xFD0))
  #define INTCON_REG    (*((volatile Register_t *)0xFF2))
  #define INTCON2_REG   (*((volatile Register_t *)0xFF1))
  #define INTCON3_REG   (*((volatile Register_t *)0xFF0))
  #define PIR1_REG      (*((volatile Register_t *)0xF9E))
  #define PIR2_REG      (*((volatile Register_t *)0xFA1))
  #define PIE1_REG      (*((volatile Register_t *)0xF9D))
  #define PIE2_REG      (*((volatile Register_t *)0xFA0))
  #define IPR1_REG      (*((volatile Register_t *)0xF9F))
  #define IPR2_REG      (*((volatile Register_t *)0xFA2))
  /* ADC */
  #define ADCON1_REG    (*((volatile Register_t *)0xFC1))
  /* EEPROM */
  #define EECON1_REG    (*((volatile Register_t *)0xFA6))
  #define EECON2_REG    (*((volatile Register_t *)0xFA7))
  #define EEDATA_REG    (*((volatile Register_t *)0xFA8))
  #define EEADR_REG     (*((volatile Register_t *)0xFA9))
  #define EEADRH_REG    (*((volatile Register_t *)0xFAA))
  /* SPI - I2C */
  #define SSPSTAT_REG   (*((volatile Register_t *)0xFC7))
  #define SSPCON1_REG   (*((volatile Register_t *)0xFC6))
  #define SSPCON2_REG   (*((volatile Register_t *)0xFC5))
  #define SSPBUF_REG    (*((Register_t *)0xFC9))
  
#elif ACCESS_TYPE==2
  #define TRISC_REG_PTR ((volatile Register_t *)0xF94)
  #define TRISD_REG_PTR ((volatile Register_t *)0xF95)
  #define PORTC_REG_PTR ((volatile Register_t *)0xF82)
  #define PORTD_REG_PTR ((volatile Register_t *)0xF83)
#endif

#endif