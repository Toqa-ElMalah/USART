/*
 * USART__1_.c
 */ 

#include "USART.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	UART_init(9600);
	_delay_ms(300);
	UART_sendString("Toqa");
    while(1)
    {
        
		   }
}