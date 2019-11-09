#ifndef USART18F4550_H
#define USART18F4550_H
void usart_init(long BAUD);
void usart_tx(char data);
char usart_rx(void);
#endif