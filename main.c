/*
 * inzynierka1.c
 *
 * Created: 03.07.2018 22:32:57
 * Author : Filip Rak
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/wdt.h>

#include "mkuart.h"
#include "IR.h"


int main(void)
{
	USART_Init(UART_BAUD);
	ir_init();
	sei();
    wdt_enable(WDTO_500MS);
    while (1) 
    {
		wdt_reset();
		if(TAIL!=HEAD)
		{
			TAIL = (TAIL + 1) & BUFOR_MASK;
			uart_putint(BUFOR[TAIL],10);
			uart_putc('\r');
			uart_putc('\n');
		}
    }
}

