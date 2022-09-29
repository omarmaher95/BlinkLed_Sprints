/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port
 *
 *  Description:  header file for Port Module    
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_GPIOKEY                                   0x4C4F434B

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef enum{PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6}Port_PinType;
typedef enum{INPUT,OUTPUT}Port_DirectionType;
typedef enum{DIGITAL,AF1,AF2,AF3,AF4,AF5,AF6,AF7,\
             AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15}Port_ModeType;
typedef enum{PULLUP,PULLDOWN,OPENDRAIN}Port_InternalAttachType;
typedef enum{DRV2,DRV4,DRV8}Port_OutputCurrentType;
typedef enum{Port_GPIOA,Port_GPIOB,Port_GPIOC,Port_GPIOD,Port_GPIOE,Port_GPIOF}Port_PortType;

typedef struct{
	Port_PortType gpioPort;
	Port_PinType pinType;
	Port_ModeType modeType;
	Port_DirectionType directionType;
	Port_InternalAttachType internalAttachType;
	Port_OutputCurrentType outputCurrentType;
}Port_ConfigType;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void Port_Init(Const Port_ConfigType * ConfigPtr)                                      
* \Description     : initialize GPIO Module by parsing the Configuration 
*                    into GPIO registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : GPIO Configuration                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr);

#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
