/*
 * IR.h
 *
 * Created: 07.09.2018 11:00:01
 *  Author: MrHause
 */ 


#ifndef IR_H_
#define IR_H_

#define BUFOR_SIZE 32

volatile uint16_t pulse;
volatile uint8_t newtime_flag;
volatile uint16_t BUFOR[BUFOR_SIZE];
volatile uint8_t HEAD;
volatile uint8_t TAIL;


#define BUFOR_MASK (BUFOR_SIZE-1)
#define IR_PIN (1<<PB0)
#define Tolerance 200
void ir_init();




#endif /* IR_H_ */