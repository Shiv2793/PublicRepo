
void setup()
{
    DDRB=0xFF;
    DDRC|=(1<<PC0);//en
    DDRC|=(1<<PC1);//rs
}
void lcd_cmd(unsigned char val)
{   PORTB=val;
    PORTC&=~(1<<PC0);
    PORTC|=(1<<PC1);
    _delay_ms(100);
    PORTC&=~(1<<PC1);
}
void lcd_data(unsigned char data)
{
    PORTB=data;
    PORTC|=(1<<PC0);
    PORTC|=(1<<PC1);
    _delay_ms(100);
    PORTC&=~(1<<PC1);
}
void lcd_init()
{
    lcd_cmd(0x38);
   _delay_ms(300);
    lcd_cmd(0x0E);
    _delay_ms(300);
    lcd_cmd(0x0C);
    _delay_ms(300);
    lcd_cmd(0x01);
    _delay_ms(300);
    lcd_cmd(0xC0);
    _delay_ms(300);
}