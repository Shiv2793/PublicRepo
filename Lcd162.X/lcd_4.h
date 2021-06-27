

//assume that you have defined connections as
//DDRB=0xFF;
//PB0 is en
//PB1 is rs
//PB4 to PB7 are 4 bit data
void setup1()
{
    DDRB=0xFF;  
}
void lcd_cmd1(unsigned char val)
{   PORTB=(PORTB & 0x0F)|(val & 0xF0);
    PORTB&=~(1<<PB1);
    PORTB|=(1<<PB0);
    _delay_ms(100);
    PORTB&=~(1<<PB0);
    _delay_ms(200);
    
    PORTB=(PORTB & 0x0F )|(val<<4);
     PORTB&=~(1<<PB1);
    PORTB|=(1<<PB0);
    _delay_ms(100);
    PORTB&=~(1<<PB0);
    _delay_ms(200);
}
void lcd_data1(unsigned char data)
{
     PORTB=(PORTB & 0x0F)|(data & 0xF0);
    PORTB|=(1<<PB1);
    PORTB|=(1<<PB0);
    _delay_ms(100);
    PORTB&=~(1<<PB0);
    _delay_ms(200);
    
    PORTB=(PORTB & 0x0F )|(data<<4);
     PORTB|=(1<<PB1);
    PORTB|=(1<<PB0);
    _delay_ms(100);
    PORTB&=~(1<<PB0);
    _delay_ms(200);
}
void lcd_init1()
{
    lcd_cmd1(0x38);
   _delay_ms(300);
    lcd_cmd1(0x0E);
    _delay_ms(300);
    lcd_cmd1(0x0C);
    _delay_ms(300);
    lcd_cmd1(0x01);
    _delay_ms(300);
    lcd_cmd1(0xC0);
    _delay_ms(300);
}