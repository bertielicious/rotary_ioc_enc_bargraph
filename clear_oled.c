/*
 * File:   clear_oled.c
 * Author: philip
 *
 * Created on 04 February 2018, 21:02
 */


#include <xc.h>

#include "config.h"
#include "config_oled.h"
#include "write_command.h"
#include "set_page_address.h"
#include "write_data.h"
void clear_oled(void)
{
    uchar row, seg;
    write_command (0x00);
    write_command (0x1f);
    for (row = 0; row < 8; row++)
    {
        set_page_address(row);
        for (seg = 0; seg < 128; seg++)
        {
            write_data(0x00);
        }
    }
}

