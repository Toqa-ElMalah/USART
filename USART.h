#ifndef USART_H_
#define USART_H_

void UART_init (unsigned long baud);
void UART_sendData (char data);
char UART_recieveData (void);
void UART_sendString (char * ptr);


#endif /* USART_H_ */
