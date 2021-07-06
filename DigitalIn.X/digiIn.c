/* 
 * File:   digiIn.c
 * Author: Shivashish
 *
 * Created on 4 June, 2021, 2:53 PM
 */

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL

/*
 * 
 */
int main() {
    DDRB &=~(1<<PINB3);
    PORTB |=(1<<PINB3);
    DDRD |=(1<<PD1);
   
    while(1)
    {
        if(PINB&(1<<PINB3))
        {
            PORTD &=~(1<<PD1);
        }
        else
        {
            PORTD |=(1<<PD1);
        }
    }
    return 0;
}

