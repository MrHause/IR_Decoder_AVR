/*
 * IR.c
 *
 * Created: 07.09.2018 11:00:14
 *  Author: MrHause
 */ 

#include "mkuart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <avr/wdt.h>
#include "IR.h"

volatile uint8_t counter;
volatile uint8_t temp;
volatile uint8_t flag;

void ir_init()
{
	DDRB &= ~IR_PIN;
	PORTB |= IR_PIN;
	
	TCCR1B |= (1<<CS11); //preskaler 8
	TCCR1B &= ~(1<<ICES1);
	TIMSK |= (1<<TICIE1);
	counter = 0;
	HEAD=0;
	TAIL=0;
	
	flag=0;
	newtime_flag=0;
}

ISR(TIMER1_CAPT_vect)
{
	uint8_t HEAD_TEMP;
	static uint16_t Last;
	
	pulse = ICR1 - Last;
	
	//dodanie danych do bufora pomocniczego
	HEAD_TEMP = (HEAD + 1) & BUFOR_MASK;
	HEAD=HEAD_TEMP;
	BUFOR[HEAD_TEMP]=pulse;
	
	//zapis czasu
	Last = ICR1;
	//zmiana reagowania na przeciwne zbocze
	TCCR1B ^= (1<<ICES1);

	newtime_flag=1;
	counter++;
	wdt_reset();
}