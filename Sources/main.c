
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
	unsigned char boucle;

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
	hovercraft_on();

	//initialisation sci
	init_sci ();

	//initialisation pwm 
	timer();
	timer();

	init_pwm_p();
	init_pwm_s();
	timer();
	timer();
	//initialisation can
	CANBAT_init();
	timer();
	timer();
	timer();



	demarrage_sustentation () ;




	while (1) {


		//lance une conversion 
		ADCSC1=0x06;

		
		for (boucle=0;boucle<255;boucle++)
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
