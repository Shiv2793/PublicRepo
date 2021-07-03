#include <avr/io.h>
#include <util/delay.h>

uint16_t ADC_val;
uint16_t val;
//uint8_t  ADC_8bit_Low_Byte  = 0; // unsigned int 8 bit variable
//uint8_t  ADC_8bit_High_Byte = 0; // unsigned int 8 bit variable
 
int main()
{
   DDRD|=(1<<PD3);
    DDRC&=~(1<<PINC0);
    ADCSRA |=(1<<ADPS2)|(1<<ADPS1);
    ADMUX = (1<<REFS1)|(1<<REFS0);
//ADC_8bit_Low_Byte   = ADCL;   // Read the 8 bit ADCL first,then ADCH
//ADC_8bit_High_Byte  = ADCH;   // Order have to be maintained,
    while(1)
    {
    ADCSRA = (1<<ADEN);
    ADCSRA |=(1<<ADSC);
        ADC_val=ADCL|(ADCH<<8);
        val=ADC_val;
       
    if(val<300)
    {
        PORTD=(1<<PD3);
    }
    else
    {
        PORTD&=~(1<<PD3);
    }
     _delay_ms(1000);
    }
    
    return 0;
}