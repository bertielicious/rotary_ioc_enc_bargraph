/*
 * File:   write_command.c
 * Author: philip
 *
 * Created on 04 February 2018, 18:14
 */


#include <xc.h>

#include "config.h"
#include "send_spi_byte.h"
void write_command (uchar comd)
{
    CS = 0;                 // select OLED display (CS is active low))
    DC = 0;                 // treat comd as a command (rather than data))
    send_spi_byte(comd);    // send byte comd via SPI MSB first
    CS = 1;                 // unselect OLED display
}
