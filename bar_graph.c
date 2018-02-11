/*
 * File:   bar_graph.c
 * Author: philip
 *
 * Created on 09 February 2018, 20:00
 */


#include <xc.h>
#include "bar_graph.h"
#include "config.h"
#include "set_columns.h"
#include "set_page.h"
#include "write_data.h"
#include "write_command.h"
void bar_graph(void) 
{
    uchar col;
    write_command(0xb6);            // write upper bar graph line b6
    write_command(0x21);
    write_command(0x09);
    write_command(0x7d);
    if(up_down == 1)                // if clockwise rotation detected
    {
        for(col = 0;col <= count;col++)   
        {
            write_data(0xff);      // write a bar graph representation of the value of count 
        }     
    }
    else                            // if anti-clockwise rotation detected
        {
            for(col = 0; col <= count ; col++)   // write a bar graph representation of count-1
            {   
                write_data(0xff);
            }
            write_data(0x01);
        }
    
    write_command(0xb7);            // write lower bar graph line b7
    write_command(0x21);
    write_command(0x09);
    write_command(0x7d);
  
    if(up_down == 1)  
    {
        for(col=0;col<=count;col++)   
        {
            write_data(0xff);       
        }     
    }
    else
        {
            for(col = 0; col <= count ; col++)
            {   
                write_data(0xff);
            }
            write_data(0x80);
        }
}
