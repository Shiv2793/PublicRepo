
#include<avr/io.h>        // AVR header
#include<util/delay.h>    // delay header
#include "lcd_8.h" 
#include "lcd_4.h"

//use lcd_4.h functions for 4bit lcd mode

int main()
{
   DDRB=0xFF;
    DDRC|=(1<<PC0);//en
    DDRC|=(1<<PC1);//rs
    lcd_init();
  
    lcd_data('S');
    lcd_data('H');
    lcd_data('I');
    lcd_data('V');
    return 0;
}