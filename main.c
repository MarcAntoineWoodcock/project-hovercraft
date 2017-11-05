#include "Cpu.h"
#include "Events.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "chenillard.h"
#include "define.h"
#include "can.h"
#include "sci.h"

unsigned char direction;		
unsigned char boucle;

void main(void)
{
	/*** Processor Expert internal initialization. ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization. ***/
  
	
	
	PTCDD_PTCDD6=1;
	PTCDD_PTCDD7=1; 				// La direction du port est en sortie
	PTADD_PTADD0=1;
	PTADD_PTADD1=1;					// La direction de ce port est en sortie

	CHENILLARD();					// Appel de la fonction CHENILLARD
	CAN_INIT();						// Appel de la fonction CAN_INIT
	SCI_INIT();						// Appel de la fonction SCI_INIT
	while(1){
		CANBAT();					// Appel de la fonction CANBAT
		for (boucle=0; boucle<255; boucle++){
			direction=CAN_JOY1();	// La variable direction contient le résultat de conversion du potentiomètre 1
			
			SCI_SEND(direction);	// Envoi de cette valeur
			
			
			direction=CAN_JOY2();	// La variable direction contient le résultat de conversion du potentiomètre 2
			
			
			SCI_SEND(direction);	// Envoi de cette valeur
		}
		
	}
}
