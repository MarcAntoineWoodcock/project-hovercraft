/*
 * can.c
 *
 *  Created on: May 11, 2017
 *      Author: Marc-Antoine
 */

#include "can.h"
#include "define.h"
void CAN_INIT(void){
	ADCCFG=0x00;
}							// Configuration du registre ADC 

void CANBAT(void){
	ADCSC1=0x08;			// Choix du channel
	while(ADCSC1_COCO==0){
	}						// Flag de conversion effectuée
	if(247<=ADCR)	{	
		PTCD_PTCD6=1;
		PTCD_PTCD7=1;
		PTAD_PTAD0=1;
		PTAD_PTAD1=1;		// Si la valeur contenu dans ADCR =>247 alors toutes les LEDs allumées
		return;
	}
	if ( (240<=ADCR))
	{
		PTCD_PTCD6=0;
		PTCD_PTCD7=1;
		PTAD_PTAD0=1;
		PTAD_PTAD1=1;		// Si la valeur contenu dans ADCR =>240 alors toutes les LED 1,2,3 allumées
		return;
	}
	if ( (216<=ADCR))
	{
		PTCD_PTCD6=0;
		PTCD_PTCD7=0;
		PTAD_PTAD0=1;
		PTAD_PTAD1=1;		// Si la valeur contenu dans ADCR =>216 alors toutes les LED 1,2 allumées
		return;

	}
	if  (ADCR<216)
	{
		PTCD_PTCD6=0;
		PTCD_PTCD7=0;
		PTAD_PTAD0=0;
		PTAD_PTAD1=1;		// Si la valeur contenu dans ADCR<216 alors toutes les LED 1, allumées
		return;
	}


}


unsigned char CAN_JOY1(void){
	unsigned char joy1;
	ADCSC1=0x02;			// Choix du channel utilisés
	while (ADCSC1_COCO==0){
	}						// Flag de conversion effectuée
	joy1=((ADCR*100)/255);	// Transformation de la valeur en pourcentage
	return(joy1);
}
unsigned char CAN_JOY2(void){		// joystick 2 donc commence par un 1 pour différencier
	unsigned char joy2;
	ADCSC1=0x23;			// Choix du channel utilisés
	while (ADCSC1_COCO==0){
	}						// Flag de conversion effectuée
	joy2=((ADCR*100)/255);	// Transformation de la valeur en pourcentage
	joy2=joy2+128;			// 
	return(joy2);
}

