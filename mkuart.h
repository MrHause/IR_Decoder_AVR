/*
 * mkuart.h
 *
 *  Created on: 2010-09-04
 *       Autor: Miros�aw Karda�
 */

#ifndef MKUART_H_
#define MKUART_H_

#include <stdint.h>

#define UART_BAUD 38400	// tu definiujemy interesuj�c� nas pr�dko��



#define UART_RX_BUF_SIZE 32 // definiujemy bufor o rozmiarze 32 bajt�w
// definiujemy mask� dla naszego bufora
#define UART_RX_BUF_MASK ( UART_RX_BUF_SIZE - 1)

#define UART_TX_BUF_SIZE 16 // definiujemy bufor o rozmiarze 16 bajt�w
// definiujemy mask� dla naszego bufora
#define UART_TX_BUF_MASK ( UART_TX_BUF_SIZE - 1)


// deklaracje funkcji publicznych

void USART_Init(uint16_t baud );
char uart_getc(void);
void uart_putc( char data );
void uart_puts(char *s);
void uart_putint(int value, int radix);

#endif /* MKUART_H_ */
