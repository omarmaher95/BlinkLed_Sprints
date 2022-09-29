/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define INTCTRL_INTA_PERI                          0
#define INTCTRL_INTB_PERI                          1
#define INTCTRL_INTC_PERI                          2
#define INTCTRL_INTD_PERI                          3
#define INTCTRL_VECTKEY                                0x05FA
#define INTCTRL_INVALID_INTNUM                         NULL_PTR
//PRI Registers helping Macros
//Macro determines PRI Register For Specific Interrupt
#define IntCtrl_IntPriReg(IntCtrl_InterruptType)    (IntCtrl_InterruptType>=0?\
                                                    (&PRI0+(IntCtrl_InterruptType/4)):INTCTRL_INVALID_INTNUM)
//Macro determines PRI Field A/B/C/D For Specific Interrupt
#define IntCtrl_IntPriField(IntCtrl_InterruptType)  ((uint8)(IntCtrl_InterruptType%4))
//Macro determines EN Register For Specific Interrupt
#define IntCtrl_IntEnReg(IntCtrl_InterruptType)     (IntCtrl_InterruptType>=0?\
                                                    (&EN0+(IntCtrl_InterruptType/32)):INTCTRL_INVALID_INTNUM)
//Macro determines EN Bit For Specific Interrupt
#define IntCtrl_IntEnField(IntCtrl_InterruptType)   ((uint8)IntCtrl_InterruptType%32)             

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void){
	uint8 intPriField = 0;
	uint8 intEnField = 0;
	volatile uint32 * intEnReg = NULL_PTR;
	volatile PRI_Tag * priReg = NULL_PTR;

 
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
  APINT.R = (INTCTRL_PRIORITY_GROUP << 8) | (INTCTRL_VECTKEY << 16) ; 
  /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
  /*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
  for(uint8 i = 0;i < INTCTRL_EXCEPTION_NUM;i++){
		 intPriField = IntCtrl_IntPriField(exceptionQueue[i]);
		 intEnField = IntCtrl_IntEnField(exceptionQueue[i]);
		 priReg = IntCtrl_IntPriReg(exceptionQueue[i]);
		 switch(intPriField){
			 case INTCTRL_INTA_PERI:
				 priReg->B.INTA = exceptionQueuePrority[i];
		     break;
			 case INTCTRL_INTB_PERI:
				 priReg->B.INTB = exceptionQueuePrority[i];
		     break;
			 case INTCTRL_INTC_PERI:
				 priReg->B.INTC = exceptionQueuePrority[i];
		     break;
			 case INTCTRL_INTD_PERI:
				 priReg->B.INTD = exceptionQueuePrority[i];
		     break;
		 }
		 intEnReg = IntCtrl_IntEnReg(exceptionQueue[i]);
		 *intEnReg |= (1 << intEnField);
	 }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
