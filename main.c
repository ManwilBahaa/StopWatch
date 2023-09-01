/*
 * main.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Manwil
 */

#include "DIO.h"
#include "INTERRUPT.h"
#include "LCD.h"
#include "TIMER.h"


u16 counter=0;

u8 last_stop=0;
u8 minutes = 0;
u8 seconds = 0;

u8 last_sec_screen=10;
u8 last_min_screen=10;

u8 state=0;

void main(){

	INTERRUPT_GIE_ENABLE();
	LCD_INIT();

	DIO_u8_SET_PIN(PORTD, PIN2, INPUT);
	DIO_u8_SET_PIN(PORTD, PIN3, INPUT);
	DIO_u8_SET_PIN(PORTB, PIN2, INPUT);

	DIO_u8_WRITE_PIN(PORTD, PIN2, HIGH);
	DIO_u8_WRITE_PIN(PORTD, PIN3, HIGH);
	DIO_u8_WRITE_PIN(PORTB, PIN2, HIGH);

	INTERRUPT_INIT(INTERRUPT_PIN_0 , MOOD_FALL);
	INTERRUPT_INIT(INTERRUPT_PIN_1 , MOOD_FALL);
	INTERRUPT_INIT(INTERRUPT_PIN_2 , MOOD_FALL);

	while(1){

		if(counter == 4000){

			seconds++;
			if(seconds ==60){
				seconds=0;
				minutes++;
			}
			counter=0;
		}

		// check for change
		if(last_sec_screen != seconds || last_min_screen != minutes){
			LCD_CLEAR();

			LCD_WRITE_INT(minutes);
			LCD_WRITE_STRING(" - ");
			LCD_WRITE_INT(seconds);

			last_sec_screen=seconds;
			last_min_screen=minutes;
		}
	}
}
// start/resume
ISR(INT0){
	TIMER_0_SET_INIT(last_stop);
	TIMER_0_SET_COMPARE(250);

	TIMER_0_INIT(CTC_0, PRE_8);
	state=1;
}

ISR(TIMER_0_COMP){
	switch(state){
	case 1:
		// start /  resume
		counter++;
		break;
	default:
		break;

	}

}

// stop
ISR(INT1){
	state=0;
	last_stop=TIMER_0_GET_TCNT();
}
// reset
ISR(INT2){
	state=0;

	last_stop=0;
	counter=0;
	minutes=0;
	seconds=0;

}
