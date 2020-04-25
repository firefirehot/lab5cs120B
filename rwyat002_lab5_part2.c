/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


//   https://drive.google.com/open?id=1AaR74gzcmRogKIVuNXLKtEJ6mo-0Iiao


#include <avr/io.h>

#ifdef _SIMULATE_

#include "simAVRHeader.h"

#endif


enum States { START, CENTER, INCTRANS, DECTRANS,INC, DEC,RESETTRANS,RESET} state;


unsigned char ucIn;
unsigned char ucOutput;



void Tick()

{
  ucIn = ~PINA;
  switch(state) {   // Transitions

     case START:  // Initial transition

	ucOutput = 0x07;

	state = CENTER;

        break;



     case CENTER:

	if(ucIn == 0x00)

		state = CENTER;

	else if(ucIn == 0x01)

		state = INCTRANS;

	else if(ucIn == 0x02)

		state = DECTRANS;

	else if(ucIn == 0x03)

		state = RESETTRANS;

        break;



     case INCTRANS:
	if(ucIn == 3){

                state = RESETTRANS;
        }

	else if(ucIn != 1){
		if(ucOutput < 9)

                        ucOutput = ucOutput + 1;

		state = INC;
	}
	else{
		
		state = INCTRANS;
	}
        break;

      case DECTRANS:
	if(ucIn == 3){

                state = RESETTRANS;
        }
	else if(ucIn != 2){
		if(ucOutput > 0)

                        ucOutput = ucOutput - 1;

		state = DEC;
	}
	else

		state = DECTRANS;

	break;

      case RESETTRANS:

	if(ucIn != 3)

		state = RESET;

	else

		state = RESETTRANS;

	break;

	

	case INC:

		state = CENTER;

	break;

	case DEC:

		state = CENTER;

	break;

	case RESET:

		state = CENTER;

	break;



     default:

        state = START;

        break;

  } // Transitions



  switch(state) {   // State actions

	case CENTER:

		PORTC = ucOutput;

        break;



	case INCTRANS:


        break;

	

	case DECTRANS:


	break;

	

	case RESETTRANS:

	ucOutput = 0;

	break;



	case INC:

	break;



	case DEC:

	break;



	case RESET:

	break;



	default:

        break;

   } // State actions

}



int main() {

	DDRA = 0x00; PORTA = 0xFF;

	DDRC = 0xFF; PORTC = 0x00;



   ucOutput = 0x00;              // Initialize outputs
	ucIn = 0x00;
   state = START; // Indicates initial call



   while(1) {
      Tick();

   }

}
