/*
 * File:   set_columns.c
 * Author: philip
 *
 * Created on 04 February 2018, 20:11
 */


#include <xc.h>
#include "config.h"
#include "write_command.h"

void set_columns (uchar column_mode, uchar lo_col_addr, uchar hi_col_addr)
{
    write_command(column_mode);
    write_command(lo_col_addr);
    write_command(hi_col_addr);
}
