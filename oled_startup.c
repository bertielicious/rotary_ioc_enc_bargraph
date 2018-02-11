/*
 * File:   oled_startup.c
 * Author: philip
 *
 * Created on 02 February 2018, 18:33
 */


#include <xc.h>
#include "config.h"
void oled_startup (void) 
{
    __delay_ms(100);        // wait for VDD to be come stable +5V
    RST = low;
    __delay_ms(100);
    RST = high;
}
