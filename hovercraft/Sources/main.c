
#include "Cpu.h"
#include "Events.h"

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "BATT.h"
#include "DEMARRAGE.h"
#include "LED_BATT.h"
#include "PWM.h"
#include "RECEPTION.h"



void main(void)
{
	unsigned char val_bat;
	unsigned char val_reception;
	unsigned short boucle;

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/



	//direction des port
	PTADD_PTADD2=1;
	PTADD_PTADD3=1;
	PTADD_PTADD6=1;
	PTADD_PTADD7=1;

	SOPT1=0b11000011;
	//SOPT1_RSTPE=1;
	//attent la fin des pib des ESC
	timer();
	timer();
	timer();
	hovercraft_on();

	//initialisation sci
	init_sci_reception ();

	//initialisation pwm

	init_pwm_p();
	init_pwm_s();

	//initialisation can
	CANBAT_init();
	//attent la fin de l'initialisation des ESC
	timer();
	timer();
	timer();
	timer();
	timer();
	timer();
	timer();

	demarrage_sustentation () ;




	while (1) {


		//lance une conversion 
		ADCSC1=0x06;


		for (boucle=0;boucle<4800;boucle++)
		{
			//fonction reçois donnée
			val_reception=reception_radio();

			//fonction moteur avec la donnée reçus en parametre
			gestion_propulsion(val_reception);

		}
		//fonction valbat
		val_bat=valeur_bat();

		//fonction led batt (buzzer)
		Led_batt(val_bat);

	}


#ifdef PEX_RTOS_START
	PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif

	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for(;;){}
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
