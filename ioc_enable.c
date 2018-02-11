/*
 * File:   ioc_enable.c
 * Author: philip
 *
 * Created on 07 February 2018, 11:33
 */


#include <xc.h>
#include "config.h"
void ioc_enable(void) 
{
    INTCONbits.GIE = 1;
    INTCONbits.INTE = 1;       // enable external interrupt on PORTAbits.RA2 pin 17
    OPTION_REGbits.INTEDG = 0;  //interrupt of falling edge of 
   // INTCONbits.INTF = 0;       // clear external interrupt flag to allow future interrupts 
}