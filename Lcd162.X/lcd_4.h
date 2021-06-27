

//assume that you have defined connections as
//DDRB=0xFF;
//PC0 is en
//PC1 is rs
//PB4 to PB7 are 4 bit data

    void setup1()
{
    DDRB=0xFF;
    DDRC|=(1<<PC1);//rs
    DDRC|=(1<<PC0);//en  
}
void lcd_cmd1(unsigned char val)
{   PORTB=(PORTB & 0x0F)|(val & 0xF0);
    PORTC&=~(1<<PC1);
    PORTC|=(1<<PC0);
    _delay_ms(100);
    PORTC&=~(1<<PC0);
    
    
    PORTB=(PORTB & 0x0F )|(val<<4);
     PORTC&=~(1<<PC1);
    PORTC|=(1<<PC0);
    _delay_ms(100);
    PORTC&=~(1<<PC0);
    
}
void lcd_data1(unsigned char data)
{
     PORTB=(PORTB & 0x0F)|(data & 0xF0);
    PORTC|=(1<<PC1);
    PORTC|=(1<<PC0);
    _delay_ms(100);
    PORTC&=~(1<<PC0);
    
    
    PORTB=(PORTB & 0x0F )|(data<<4);
     PORTC|=(1<<PC1);
    PORTC|=(1<<PC0);
    _delay_ms(100);
    PORTC&=~(1<<PC0);
 
}
void lcd_init1()
{
   lcd_cmd1(0x02);
    _delay_ms(300);
    lcd_cmd1(0x28);
   _delay_ms(300);
    lcd_cmd1(0x01);
    _delay_ms(300);
    lcd_cmd1(0x0E);
    _delay_ms(300);
    lcd_cmd1(0x80);
}
