//#define BR 9600
//#define BRC ((F_CPU/16/BR)-1)
    void Clock_Normal_async(unsigned int Boad)
    {
        int BRC= (F_CPU/16/Boad)-1;
        UBRR0H=(BRC>>8);
        UBRR0L=(BRC);
       
    }
    void UART_init()
    {
        UCSR0B=(1<<TXEN0);//tx enable
        //UCSR0C=(1<<UPM01);//even parity
        UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);
    }
    void Uart_send(char data)
    {
        UDR0=data;
        
    }


