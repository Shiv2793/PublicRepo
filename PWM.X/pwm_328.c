/* 
 * File:   pwm_328.c
 * Author: Shivashish
 *
 * Created on 4 July, 2021, 1:49 AM
 */

#include <avr/io.h>
#include <util/delay.h>
//ctc mode
int main()
{
    //prescaler 64
    DDRD=(1<<PD6);
    TCCR0A=(1<<COM0A0)|(1<<WGM01);      
    TCCR0B=(1<<CS01)|(1<<CS00);
    OCR0A=220;      
    return 0;
}