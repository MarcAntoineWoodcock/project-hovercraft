/*
 * ON.c
 *
 *  Created on: Apr 11, 2017
 *      Author: gael fargeas
 */

#include <LED_BATT.h>
#include <DEFINE.h>

void Led_batt(unsigned char val_bat){

	if(val_bat>=244){
		// si le niveaux de batterie est supperieur ou egal a 80%  sa allume la 1er LED
		LED_1=1;
		LED_2=1;
		LED_3=1;
		LED_4=1;
		TPM1C0SC=0x00;
		return ;
	}

	if(val_bat>=232){
		// si le niveaux de batterie est supperieur ou egal a 60% sa allume la 2eme LED	
		LED_1=0;
		LED_2=1;
		LED_3=1;
		LED_4=1;
		TPM1C0SC=0x00;
		return;
	}

	if(val_bat>=221){
		// si le niveaux de batterie est supperieur ou egal a 40%  sa allume la 3eme LED	
		LED_1=0;
		LED_2=0;
		LED_3=1;
		LED_4=1;
		TPM1C0SC=0x00;
		return ;
	}

	if(val_bat<221){
		// si le niveaux de batterie est infferieur ou egal a 40% sa allume la 4eme LED	
		LED_1=0;
		LED_2=0;
		LED_3=0;
		LED_4=1;

		//buzzer
		//preconfigure la PWM buzzer
		TPM1C0SC=0x28;
		//configure la frequence et le raport cyclique de la pwm buzzer
		TPM1MOD=0x00C5;
		TPM1C0V=0x0062;
		//lance la pwm buzzer
		TPM1SC=0x2F;
		return ;
	}

}
