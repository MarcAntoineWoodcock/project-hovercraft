/*
 * chenillard.c
 *
 *  Created on: May 11, 2017
 *      Author: Marc-Antoine
 */
#include "chenillard.h"
#include "define.h"
void DELAY(void){
	asm {
		LDA #$FF
		RET1: LDHX #$900
		ret:	AIX #-1
		CPHX #$0000
		BNE ret
		DECA 
		BNE RET1
	}

}
void CHENILLARD(void){
	PTCD_PTCD6=0;
	PTCD_PTCD7=0;
	PTAD_PTAD0=0;
	PTAD_PTAD1=0;		// Toutes les LEDs sont �teintes



	PTCD_PTCD6=1;		// LED_4 est allum�
	DELAY();			// Appel de la fonction DELAY
	
	PTCD_PTCD6=0;		// LED_4 est �teinte
	PTCD_PTCD7=1;		// LED_3 est allum�
	DELAY();			// Appel de la fonction DELAY

	PTCD_PTCD7=0;		// LED_3 est �teinte
	PTAD_PTAD0=1;		// LED_2 est allum�
	DELAY();			// Appel de la fonction DELAY

	PTAD_PTAD0=0;		// LED_2 est �teinte
	PTAD_PTAD1=1;		// LED_1 est allum�
	DELAY();			// Appel de la fonction DELAY

	PTAD_PTAD1=0;		// LED_1 est �teinte
	PTAD_PTAD0=1;		// LED_2 est allum�
	DELAY();			// Appel de la fonction DELAY

	PTAD_PTAD0=0;		// LED_2 est �teinte	
	PTCD_PTCD7=1;		// LED_3 est allum�
	DELAY();			// Appel de la fonction DELAY
	
	PTCD_PTCD7=0;		// LED_3 est �teinte
	PTCD_PTCD6=1;		// LED_4 est allum�
	DELAY();			// Appel de la fonction DELAY
	
	PTCD_PTCD6=0;		// LED_4 est �teinte
}
