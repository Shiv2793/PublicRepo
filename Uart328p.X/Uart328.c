#include <avr/io.h>
#include <util/delay.h>

#include <avr/interrupt.h>

#include "Clock_rate.h"

//#define F_CPU 8000000UL

int main()
{
    Clock_Normal_async(9600);
    UART_init();
    while(1){
        _delay_ms(2000);
     UDR0='8';
     _delay_ms(2000);
   
    }  
    return 0;
}