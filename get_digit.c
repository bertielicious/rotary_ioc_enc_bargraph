/*
 * File:   get_digit.c
 * Author: philip
 *
 * Created on 08 February 2018, 15:20
 */


#include <xc.h>
#include "config.h"
#include "write_character.h"

void get_digit(uchar digit, uchar shuffle) 
{
    switch(digit)
    {
        case 0:
            write_character(&cero[0],shuffle,0xb3);
            break;
        case 1:
            write_character(&uno[0],shuffle,0xb3);
            break;
        case 2:
            write_character(&dos[0],shuffle,0xb3);
            break;
        case 3:
            write_character(&tres[0],shuffle,0xb3);
            break;
        case 4:
            write_character(&cuatro[0],shuffle,0xb3);
            break;
        case 5:
            write_character(&cinco[0],shuffle,0xb3);
            break;
        case 6:
            write_character(&seis[0],shuffle,0xb3);
            break;
        case 7:
            write_character(&siete[0],shuffle,0xb3);
            break;
        case 8:
            write_character(&ocho[0],shuffle,0xb3);
            break;
        case 9:
            write_character(&nueve[0],shuffle,0xb3);
            break;     
    }
}
