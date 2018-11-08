/*
 * BATT.c
 *
 *  Created on: Apr 11, 2017
 *      Author: gael fargeas
 */
#include <RECEPTION.h>
#include <DEFINE.h>

void init_sci_reception (void){
	//initialise la liaison sci
	SCI1BD=0xA4;
	SCI1C1=0x00;
	SCI1C2=0x04;

}

unsigned char reception_radio(void){
	unsigned char vall;
	//attent de recevoir un octet et r'envoie cette octet
	while (1)
	{
		if (SCI1S1_RDRF == 1) {

			vall=SCI1D ;	
			return vall ;	

		}

	}


}
