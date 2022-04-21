/*
 * main.c
 *
 * Created: 4/19/2022 11:19:38 AM
 *  Author: Srinu
 */ 

#include <avr/io.h>
#include <avr/delay.h>

int main()
{
	DDRD |=1<<PD1; //enable pin 28 red1
	DDRD |=1<<PD2; //enable pin 27 yellow1
	DDRD |=1<<PD3; //enable pin 26 green1
	DDRB |=1<<PB3; //enable pin 17 red2
	DDRB |=1<<PB2; //enable pin 16 yellow2
	DDRB |=1<<PB1; //enable pin 15 green2
	while(1)
	{
		PORTD &= ~(1<<PC1); //on red1 pin28
		PORTB &= ~(1<<PB1); //on green2 pin 15
		PORTB |=(1<<PB3); //off red2
		PORTD |=(1<<PD2); //off yellow1
		PORTB |=(1<<PB2); //off yellow2
		PORTD |=(1<<PD3); //off green1
		_delay_ms(400000);
		PORTB &= ~(1<<PB2); //on yellow2
		PORTB |=(1<<PB1); //off green2
		_delay_ms(100000);
		PORTD |=(1<<PD1); //off red1
		PORTB |=(1<<PB2); //off yellow2
		PORTD &= ~(1<<PD3); //on green1
		PORTB &= ~(1<<PB3); //on red2
		_delay_ms(400000);
		PORTD &= ~(1<<PD2); //on yellow1
		PORTD |=(1<<PD3); //off green1
		_delay_ms(100000);
	}
}