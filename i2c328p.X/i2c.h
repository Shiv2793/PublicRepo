void twi_init()
{
   sei();//SREG i-bit set 
   TWBR=0x62;
   TWSR=0x00;//set prescaler to 1
   TWCR=(1<<TWEN);//enable start
   
}
void twi_start()
{
TWCR = (1<<TWINT)|(1<<TWSTA)| (1<<TWEN);
while (!(TWCR & (1<<TWINT)));

}
void twi_write(unsigned char data){
TWDR = data;
TWCR = (1<<TWINT) | (1<<TWEN);
while (!(TWCR & (1<<TWINT)));

}
char twi_read()
{
    TWCR = (1<<TWINT) | (1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    return TWDR;   
}
void twi_stop()
{
TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}