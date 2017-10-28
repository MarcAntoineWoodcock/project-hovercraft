/*
 * BATT.c
 *
 *  Created on: Apr 11, 2017
 *      Author: gael fargeas
 */
#include <PWM.h>
#include <DEFINE.h>
#include <DEMARRAGE.h>
//initialisation PWM sustentation
void init_pwm_s (void)
{

	TPM2C0SC=0x28;  // Preconfigure la fonction PWM (etat de repos niveau haut) 
	TPM2MOD=0x8250; // Configure la PWM à 50 Hertz 
	TPM2C0V=0x0625; // Initialise le rapport cyclique pour la PWM a 1 % /!\ a configurer en fonction du poids
	TPM2SC=0x2B;    // Lance la PWM sustentation (center-aligned, division horloge par 8)

	return;
}

void init_pwm_p (void)
{

	TPM3C0SC=0x28;  
	TPM3C1SC=0x28;  // Preconfigure la fonction PWM (etat de repos niveau haut)
	TPM3C5SC=0x28;

	TPM3MOD=0x8250; // Configure la PWM à 50 Hertz

	TPM3C0V=0x0625; 
	TPM3C1V=0x0625; // Initialise le rapport cyclique pour la propulsiona 1 % /!\ a configurer 50% apres flash ESC
	TPM3C5V=0x0625;

	TPM3SC=0x2B;    // Lance la PWM propulsion (center-aligned, division horloge par 8)

	return;
}

void gestion_propulsion(unsigned char val_reception)
{
	//si la variable en parametre commence par un "1" on genere la pwm pour le moteur 			gauche ?
	if ( (val_reception >> 7)==1)
	{

		TPM3C1V=( (5*(val_reception & 0x7F)) +2123 );


	}
	//sinon il commence par un "0" on genere la pwm pour le moteur 		droit ? 
	else
	{
	
		TPM3C0V=( (5*(val_reception)) +2123 );
	}



	return;
}


void demarrage_sustentation (void) {

		//1.2ms	 theorique    : 1.1ms réel
		TPM2C0V=0x075F;
		timer();
		
		//1.3ms theorique    : 1.2ms réel	
		TPM2C0V=0x07FD;
		timer();

		//1.4ms theor+-ique    : 1.3ms réel	
		TPM2C0V=0x089A;
		timer();

		//1.5ms theorique    : 1.4ms réel	
		TPM2C0V=0x0937;
		timer();

		//1.55ms theorique    : 1.45ms réel	
		TPM2C0V=0x0985;
		timer();
		
	
	
	
	
	
}
