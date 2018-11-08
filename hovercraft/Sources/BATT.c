/*
 * BATT.c
 *
 *  Created on: Apr 11, 2017
 *      Author: gael fargeas
 */
#include <BATT.h>
#include <DEFINE.h>


void CANBAT_init(void){
	//initialisation du can

	//preconfigure le can en low power
	ADCCFG=0x00;
	ADCSC2=0x00;

}

unsigned char valeur_bat(void){
	
	//variable local a la fonction
	unsigned char x ;

	
	//attent que la conversion sois fini puis retourne la valeur convertie.
	while (1){
	if (ADCSC1_COCO)
	{
		x=ADCRL;
		return x;
	}
	}
}
