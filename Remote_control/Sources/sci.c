/*
 * sci.c
 *
 *  Created on: May 11, 2017
 *      Author: Marc-Antoine
 */
#include "sci.h"
#include "define.h"

void SCI_INIT(void){
	SCI1BD=0xA4;
	SCI1C1=0x00;
	SCI1C2=0x08;
}								// Configuration du registre SCI1
void SCI_SEND(unsigned char direction){
	while(1){
		if( SCI1S1_TC==1){		// Flag de d'émission
			SCI1D=direction;	// Envoi de la vaiable direction
			return;
		}
	}
}
