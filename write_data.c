/*
 * File:   write_data.c
 * Author: philip
 *
 * Created on 04 February 2018, 19:40
 */


#include <xc.h>
#include "config.h"
#include "send_spi_byte.h"
#include "write_data.h"
void write_data(uchar data) 
{
    CS = 0;
    DC = 1;
    send_spi_byte(data);
    CS = 1;
}
