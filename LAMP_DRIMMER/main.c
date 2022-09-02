/*
 * main.c
 *
 *  Created on: May 1, 2021
 *      Author: user1
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
//
void pwm_init();
void function_actived();

unsigned char N;
char F=0;
unsigned char duty=0;

int main(void){
	DDRD|=(1<<PD2);
	DDRB=0xC0;
	DDRA=0xFF;
	DDRC=0xFF;
	MCUCR|=(1<<ISC01)|(1<<ISC00);
	GICR=(1<<INT0);
	N=0;
	sei();
	PORTA=0X01;
	wdt_enable(WDTO_2S);
	while(1){

	switch(N)
		{
		case 0:PORTA=0X00;PORTC=0X00;TCCR0=0X00;TCCR2=0X00;PORTB=0x00;break;
		case 1:pwm_init();function_actived();break;
		default:;
		}
	wdt_reset();
}
		return 0;

	}

void pwm_init(){
		TCCR0|=(1<<CS02)|(1<<WGM01)|(1<<WGM00)|(1<<COM01);
		DDRB|=(1<<PB3);
		TCCR2|=(1<<CS22)|(1<<WGM21)|(1<<WGM20)|(1<<COM21);
		DDRD|=(1<<PD7);
	}
void function_actived(){
			if(!(PINA&(1<<PA0))){
			PORTA=0X01;}
			if (PINA&(1<<PA7)){
				if (F==0){
					PORTC=0X01;
				F=1;}}
				if((PINA&(1<<PA7))&&(!(PINC&(1<<PC0)))){
					PORTC=0X01;
					PORTA=0XFF;
				}
				if(PINB&(1<<PB0)){
					_delay_ms(100);
				if(PINB&(1<<PB0)){
					duty+=18;
					if (PINA&(1<<PA7)){
						PORTA=0XFF;
					PORTC|=(PORTC<<1);}
					PORTA|=(PORTA<<1);
				}
				while(PINB&(1<<PB0)){}
				}
				if(PINB&(1<<PB1)){
					_delay_ms(100);
					if(PINB&(1<<PB1)){
					duty-=18;
					PORTC&=((PORTC>>1));
					if (!(PINC&(1<<PC0))){
						PORTC=0X00;
						PORTA&=(PORTA>>1);
					}
				}
					while(PINB&(1<<PB1)){}
				}

			if ((PINA&(1<<PA0))&&(!(PINA&(1<<PA1)))){
				duty=0;
			}
			if ((PINC&(1<<PC6))&&((PINC&(1<<PC7)))){
				duty=250;
			}

				if(PINB&(1<<PB4)){
					OCR0=duty;
					OCR2=0;
				PORTB&=(~(1<<PB6));}
				else if (!(PINB&(1<<PB4))){
					OCR2=duty;
					OCR0=0;
					PORTB|=(1<<PB6);
				}
	}


ISR(INT0_vect){
				N++;
				if (N==2){
					N=0;
				}
			}
