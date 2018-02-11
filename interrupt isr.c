/*
 * File:   interrupt isr.c
 * Author: philip
 *
 * Created on 07 February 2018, 20:25
 */


#include <xc.h>
#include "config.h"
#include "interrupt isr.h"
#include "set_page.h"
#include "set_columns.h"
#include "write_data.h"
#include "bar_graph.h"

void interrupt isr(void) 
{
    uchar col;
    uchar clear_port_a = 0;
    if(INTCONbits.INTF == 1)
    {
       if(CLK == 1)  
       {
           up_down = 1;
           count++;             // rot encoder is being turned clockwise
           
       }
       else 
       {
           up_down = 0;
           count--;             // rot encoder is being turned anti-clockwise
       }
       if (count >= COUNT_MAX)
    {
        count = COUNT_MAX;
    }
    if(count <= COUNT_MIN)
    {
        count = COUNT_MIN;
    }
   
        previous_count = count; 
     
    PORTBbits.RB5 = ~PORTBbits.RB5;
    clear_port_a = PORTA;
    INTCONbits.INTF = 0;
    
    }
}
