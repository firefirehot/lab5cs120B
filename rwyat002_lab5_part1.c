/*	Author: Robert Wyatt 
 *	lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


//   https://drive.google.com/open?id=199zChZkwZWehhqqshNtSXkNjbuPZ1eTE

#include <avr/io.h>

#ifdef _SIMULATE_

#include "simAVRHeader.h"

#endif



int main(void) {

    /* Insert DDR and PORT initializations */

	DDRA = 0x00; PORTA = 0xFF;

	DDRC = 0xFF; PORTC = 0x00;



    /* Insert your solution below */

    while (1) {
	if(!(~PINA & 0xFF)){
		PORTC = 0x40;

			}
	else if(!(~PINA & 0xFE) || !(~PINA & 0xFD)){

		PORTC = 0x60;

	}

	else if(!(~PINA & 0xFC) || !(~PINA & 0xFB)){

		PORTC = 0x70;

	}

	else if(!(~PINA & 0xFA) || !(~PINA & 0xF9)){

		PORTC = 0x38;

	}

	else if(!(~PINA & 0xF7) || !(~PINA & 0xF6) || !(~PINA & 0xF8)){

		PORTC = 0x3C;

	}

	else if(!(~PINA & 0xF5) || !(~PINA & 0xF4) || !(~PINA & 0xF3)){

		PORTC = 0x3E;}

	else if(!(~PINA & 0xF0) || !(~PINA & 0xF1) || !(~PINA & 0xF2)){

		PORTC = 0x3F;

	}



    }

    return 1;

}
