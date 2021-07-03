#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "i2c.h"
#include "i2clcd.h"
#define F_CPU 8000000UL;
void i2c_init()
{
    twi_init();
    twi_start();
    twi_write(0x40); 
}
void lcd_init()
{
    lcd_send_cmd(0x02);
    _delay_ms(300);
    lcd_send_cmd(0x28);
     _delay_ms(300);
    lcd_send_cmd(0x01);
     _delay_ms(300);
    lcd_send_cmd(0x0E);
     _delay_ms(300);
    lcd_send_cmd(0x80);
     _delay_ms(300);
}
int main()
{ 
   i2c_init();
   _delay_ms(300);
   lcd_init();
   _delay_ms(100);
   lcd_send_data('S');
   _delay_ms(200);
   lcd_send_data('H');
   _delay_ms(200);
   lcd_send_data('I');
   _delay_ms(200);
   lcd_send_data('V');
   _delay_ms(200);
   
   return 0;
}