
void lcd_send_cmd(unsigned char cmd)
{
    //for cmd rs must be 0 which is P0
    //P1 is en must be transit from 1 to 0 at end of transmission.
    //so we have upper bits like P7,P6,P5,P4,P3,P2,P1,P0
    //.......................... x, x, x, x, - ,- ,1 , 0 = FE or 0E or 02 or F2
    //...........................x, x, x, x, - ,- ,0 , 0 = FC or 0C or 00 or F0
    char data_u, data_l;
    uint8_t data_t[4];
    data_u=(cmd&0xf0);
    data_l=((cmd<<4)&0xf0);
    //next what we want from here is en=1 rs=0
    data_t[0]=data_u|0x02;
    twi_write(data_t[0]);
    _delay_ms(100);
    data_t[1]=data_u|0x00;
     twi_write(data_t[1]);
     _delay_ms(100);
    data_t[2]=data_l|0x02;
     twi_write(data_t[2]);
     _delay_ms(100);
    data_t[3]=data_l|0x00;
     twi_write(data_t[3]);
     _delay_ms(100);
}
void lcd_send_data(unsigned char data)
{
      char data_u, data_l;
    uint8_t data_t[4];
    data_u=(data&0xf0);
    data_l=((data<<4)&0xf0);
    //next what we want from here is en=1 rs=1
    data_t[0]=data_u|0x03;
    twi_write(data_t[0]);
    _delay_ms(100);
    data_t[1]=data_u|0x01;
     twi_write(data_t[1]);
     _delay_ms(100);
    data_t[2]=data_l|0x03;
     twi_write(data_t[2]);
     _delay_ms(100);
    data_t[3]=data_l|0x01;
     twi_write(data_t[3]);
     _delay_ms(100);
}