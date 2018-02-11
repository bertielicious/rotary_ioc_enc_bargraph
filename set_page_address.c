/*
 * File:   set_page_address.c
 * Author: philip
 *
 * Created on 04 February 2018, 21:03
 */


#include <xc.h>
#include "config.h"
#include "write_command.h"
void set_page_address(uchar add)
{
    add = 0xb0|add;
    write_command(add);
}
