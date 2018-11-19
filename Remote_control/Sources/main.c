/* ###################################################################
 **     Filename    : main.c
 **     Project     : QE16CWL
 **     Processor   : MC9S08QE16CWL
 **     Version     : Driver 01.12
 **     Compiler    : CodeWarrior HCS08 C Compiler
 **     Date/Time   : 2017-04-28, 18:29, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.12
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */         
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "chenillard.h"
#include "define.h"
#include "can.h"
#include "sci.h"

/* User includes (#include below this line is not maintained by Processor Expert) */


unsigned char direction;		
unsigned char boucle;

void main(void)
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/
	//CAN_Init();
	/* Write your code here */
	//for(;;){
//
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

/* For example: for(;;) { } */

/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
/*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  //for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
