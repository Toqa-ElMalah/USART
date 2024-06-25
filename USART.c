/*
 * USART.c
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "std_macrous.h"

void UART_init (unsigned long baud){
	/* choose baud rate*/
	unsigned short UBRR;
	UBRR = (F_CPU/(16*baud))-1;
	UBRRH=(unsigned char)(UBRR>>8);
	UBRRL=(unsigned char)UBRR;
	
	/* enable USART Tx & Rx */
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	/* choose no. of data to be send
	8-bit data,1 stop bit, no parity*/
	UCSRC=(1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}

void UART_sendData (char data){
	while (READ_BIT(UCSRA,UDRE)==0);
	UDR=data;
}

char UART_recieveData (void){
	while (READ_BIT(UCSRA,RXC)==0);
	return UDR;
}

void UART_sendString (char * ptr){
	while (*ptr != 0){
		UART_sendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}	