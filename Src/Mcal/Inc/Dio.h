/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  header file for Dio Module    
 *  
 *********************************************************************************************************************/
#ifndef Dio_H
#define Dio_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef enum{PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,\
             PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7,\
             PE0,PE1,PE2,PE3,PE4,PE5,PF0=40,PF1,PF2,PF3,PF4}Dio_ChannelType;
typedef enum{Dio_GPIOA,Dio_GPIOB,Dio_GPIOC,Dio_GPIOD,Dio_GPIOE,Dio_GPIOF}Dio_PortType;
typedef enum{LOW,HIGH}Dio_LevelType;
typedef uint32  Dio_PortLevelType;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 /******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)                                      
* \Description     : read input channel and return its level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Input Channel to be read                     
* \Parameters (out): level of the input channel                                                      
* \Return value:   : None
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId)                                      
* \Description     : write output channel level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Output Channel to be read                     
* \Parameters (out):                                                       
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType level);
/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)                                      
* \Description     : read input port and return its level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Input port to be read                     
* \Parameters (out): level of the input port                                                      
* \Return value:   : None
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId)                                      
* \Description     : write output port level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Output port to be read                     
* \Parameters (out):                                                       
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level);
/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)                                       
* \Description     : flip channel and return its level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : channel to be flipped                     
* \Parameters (out): level of the channel                                                      
* \Return value:   : None
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif
/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
