/*
 * File:   init_ports.c
 * Author: philip
 *
 * Created on 02 February 2018, 18:05
 */


#include <xc.h>

void init_ports(void) 
{
    /* turn off adc module and comparators*/
    ANSEL = 0x00;
    ANSELH = 0x00;  // ADC module off
    CM1CON0 = 0x00;
    CM2CON0 = 0x00; // comparators off
    
    /* internal clock setup*/
    OSCCONbits.IRCF2 = 1;           // 4 MHz clock configuration
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 0;
    
    /*make SPI pins all outputs*/
    TRISBbits.TRISB6 = 0;       // SCK serial clock output pin 11
    TRISCbits.TRISC7 = 0;       // SDO serial data out pin 9
    TRISCbits.TRISC1 = 0;       // RESET pin 15
    TRISCbits.TRISC2 = 0;       // D/C pin 14
    TRISAbits.TRISA5 = 0;       // CS chip select (active low) pin 2 )
    TRISBbits.TRISB5 = 0;       // interrupt diagnostic LED
    /*make interrupt on change pins inputs*/
    TRISCbits.TRISC5 = 1;       // CLK input pin 5
    TRISAbits.TRISA2 = 1;       // DT input pin 17
    /* SPI setup where uController in Master mode, OLED display will be a slave
     SSPSTAT REG (sync serial port status register*/
    SSPSTATbits.SMP = 1;    // data sampled at end of output time
    SSPSTATbits.CKE = 0;    // data transmitted on falling edge of SCK, CKP = 0 
    /* SSPCON REG (sync serial port control register*/
    SSPCONbits.WCOL = 0;    // cleared for no collision detection required
    SSPCONbits.SSPOV = 0;   // cleared for no overflow detection required
    SSPCONbits.SSPEN = 1;   // set to enable serial port pins SCK and SDO as serial port pins
    SSPCONbits.CKP = 1;     // set means idle state of clock is HIGH
    SSPCONbits.SSPM3 = 0;    // SPI master mode, clock = fosc/4
    SSPCONbits.SSPM2 = 0;
    SSPCONbits.SSPM1 = 0;
    SSPCONbits.SSPM0 = 0;
}
