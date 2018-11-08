/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cpu.h
**     Project     : prog_hovercraft_final
**     Processor   : MC9S08QE32CWL
**     Component   : MC9S08QE32_28
**     Version     : Component 01.005, Driver 01.40, CPU db: 3.00.025
**     Datasheet   : MC9S08QE32RM Rev. 3 Draft A 11/2009
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2017-04-24, 11:19, # CodeGen: 3
**     Abstract    :
**         This component "MC9S08QE32_28" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
**     Settings    :
**
**     Contents    :
**         EnableInt  - void Cpu_EnableInt(void);
**         DisableInt - void Cpu_DisableInt(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.h
** @version 01.40
** @brief
**         This component "MC9S08QE32_28" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

#ifndef __Cpu
#define __Cpu

/* Active configuration define symbol */
#define PEcfg_Debug_S08QE32CFT 1U


/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* MODULE Cpu. */

#ifndef __BWUserType_tPowerDownModes
#define __BWUserType_tPowerDownModes
  typedef enum {                       /* OBSOLETE: don't use for new projects */
    PowerDown,
    PartialPowerDown,
    StandBy
  } tPowerDownModes;
#endif

#define CPU_BUS_CLK_HZ              0x01800000UL /* Initial value of the bus clock frequency in Hz */

#define CPU_INSTR_CLK_HZ            0x01800000UL /* Initial value of the instruction clock frequency in Hz */

#define CPU_EXT_CLK_HZ              0x8000UL /* Value of the main clock frequency (crystal or external clock) in Hz */
#define CPU_INT_CLK_HZ              0x8000UL /* Value of the internal oscillator clock frequency in Hz */

#define CPU_TICK_NS                 0x7736U /* CPU tick is a unit derived from the frequency of external clock source. If no external clock is enabled or available it is derived from the value of internal clock source. The value of this constant represents period of the clock source in ns. */

#define CPU_CORE_HCS08                 /* Specification of the core type of the selected cpu */
#define CPU_DERIVATIVE_MC9S08QE32      /* Name of the selected cpu derivative */
#define CPU_PARTNUM_MC9S08QE32CWL      /* Part number of the selected cpu */


/* Global variables */
extern volatile byte CCR_reg;          /* Current CCR register */
extern volatile byte CCR_lock;         /* Nesting level of critical regions */

void _EntryPoint(void);
/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S08QE32_28)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

__interrupt void Cpu_Interrupt(void);
/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component MC9S08QE32_28)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


#define   Cpu_DisableInt()  __DI()     /* Disable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S08QE32_28)
**     Description :
**         Disables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define   Cpu_EnableInt()  __EI()      /* Enable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S08QE32_28)
**     Description :
**         Enables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void PE_low_level_init(void);
/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S08QE32_28)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END Cpu. */

#endif /* ifndef __Cpu */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
