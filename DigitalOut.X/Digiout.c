/* 
 * File:   Digiout.c
 * Author: Shivashish
 *
 * Created on 4 June, 2021, 2:09 AM
 */

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
/*
 * 
 */
int main() {
    //DDRD = 0xFF;
    DDRD=(1<<PD1);
    while(1)
    {
       // PORTD=0x02;
        PORTD |= (1<<PD1);
        _delay_ms(1000);
        //PORTD=0x00;
        PORTD &=~(1<<PD1);
        _delay_ms(1000);
    }
    return 0;
}

