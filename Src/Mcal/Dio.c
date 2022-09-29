/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital input output Driver
 *
 *      \details  The Driver Configure All MCU GPIOs to act as digital input output ports
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define MASK_GPIO_DATA(Port_GpioBase,Pin)                   (*((volatile uint32*)(Port_GpioBase+0x000+(1<<(Pin%8+2)))))
#define MASK_PORT_DATA(Port_GpioBase)                       (*((volatile uint32*)(Port_GpioBase+0x3FC)))

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
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)                                      
* \Description     : read input channel and return its level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Input Channel to be read                     
* \Parameters (out): level of the input channel                                                      
* \Return value:   : None
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
	/*TODO Read GPIOs input value*/
	Dio_LevelType level =LOW;
	if(ChannelId <= PA7){
		level = MASK_GPIO_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS,ChannelId);
	}else if(ChannelId <= PB7){
		level = MASK_GPIO_DATA(CORTEXM4_GPIOB_APB_BASE_ADDRESS,ChannelId);
  }else if(ChannelId <= PC7){
		level = MASK_GPIO_DATA(CORTEXM4_GPIOC_APB_BASE_ADDRESS,ChannelId);
  }else if(ChannelId <= PD7){
		level = MASK_GPIO_DATA(CORTEXM4_GPIOD_APB_BASE_ADDRESS,ChannelId);
	}else if(ChannelId <= PE5){
		level = MASK_GPIO_DATA(CORTEXM4_GPIOE_APB_BASE_ADDRESS,ChannelId);
  }else{
		level = MASK_GPIO_DATA(CORTEXM4_GPIOF_APB_BASE_ADDRESS,ChannelId);
	}
	return level >> ChannelId%8;
}
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
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType level){ 
	/*TODO Write GPIOs output value*/
	if(ChannelId <= PA7){
		 MASK_GPIO_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS,ChannelId) = level<<ChannelId;
	}else if(ChannelId <= PB7){
		 MASK_GPIO_DATA(CORTEXM4_GPIOB_APB_BASE_ADDRESS,ChannelId) = level<<ChannelId%8;
  }else if(ChannelId <= PC7){
     MASK_GPIO_DATA(CORTEXM4_GPIOC_APB_BASE_ADDRESS,ChannelId) = level<<ChannelId%8;
  }else if(ChannelId <= PD7){
		 MASK_GPIO_DATA(CORTEXM4_GPIOD_APB_BASE_ADDRESS,ChannelId) = level<<ChannelId%8;
	}else if(ChannelId <= PE5){
		 MASK_GPIO_DATA(CORTEXM4_GPIOE_APB_BASE_ADDRESS,ChannelId) = level<<ChannelId%8;
  }else{
		 MASK_GPIO_DATA(CORTEXM4_GPIOF_APB_BASE_ADDRESS,ChannelId) = level<<ChannelId%8;
	}
}

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
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
	/*TODO Read port input value*/
	Dio_PortLevelType level = 0;
	if(PortId == Dio_GPIOA){
		level = MASK_PORT_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS);
	}else if(PortId == Dio_GPIOB){
		level = MASK_PORT_DATA(CORTEXM4_GPIOB_APB_BASE_ADDRESS);
  }else if(PortId == Dio_GPIOC){
		level = MASK_PORT_DATA(CORTEXM4_GPIOC_APB_BASE_ADDRESS);
  }else if(PortId == Dio_GPIOD){
		level = MASK_PORT_DATA(CORTEXM4_GPIOD_APB_BASE_ADDRESS);
	}else if(PortId == Dio_GPIOE){
		level = MASK_PORT_DATA(CORTEXM4_GPIOE_APB_BASE_ADDRESS);
  }else{
		level = MASK_PORT_DATA(CORTEXM4_GPIOF_APB_BASE_ADDRESS);
	}
	return level;
}
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
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level){
	/*TODO Write port output value*/
	if(PortId == Dio_GPIOA){
		MASK_PORT_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS) = level;
	}else if(PortId == Dio_GPIOB){
		MASK_PORT_DATA(CORTEXM4_GPIOB_APB_BASE_ADDRESS) = level;
  }else if(PortId == Dio_GPIOC){
		MASK_PORT_DATA(CORTEXM4_GPIOC_APB_BASE_ADDRESS) = level;
  }else if(PortId == Dio_GPIOD){
		MASK_PORT_DATA(CORTEXM4_GPIOD_APB_BASE_ADDRESS) = level;
	}else if(PortId == Dio_GPIOE){
		MASK_PORT_DATA(CORTEXM4_GPIOE_APB_BASE_ADDRESS) = level;
  }else{
		MASK_PORT_DATA(CORTEXM4_GPIOF_APB_BASE_ADDRESS) = level;
	}
}
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
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId) {
	/*TODO flip channel value*/
	Dio_LevelType level = 0;
	if(ChannelId <= PA7){
		MASK_GPIO_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS,ChannelId) ^= 1<<ChannelId%8;
		level = MASK_GPIO_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS,ChannelId);
	}else if(ChannelId <= PB7){
		MASK_GPIO_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS,ChannelId) ^= 1<<ChannelId%8;
		level = MASK_GPIO_DATA(CORTEXM4_GPIOB_APB_BASE_ADDRESS,ChannelId);
  }else if(ChannelId <= PC7){
		MASK_GPIO_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS,ChannelId) ^= 1<<ChannelId%8;
		level = MASK_GPIO_DATA(CORTEXM4_GPIOC_APB_BASE_ADDRESS,ChannelId);
  }else if(ChannelId <= PD7){
		MASK_GPIO_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS,ChannelId) ^= 1<<ChannelId%8;
		level = MASK_GPIO_DATA(CORTEXM4_GPIOD_APB_BASE_ADDRESS,ChannelId);
	}else if(ChannelId <= PE5){
		MASK_GPIO_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS,ChannelId) ^= 1<<ChannelId%8;
		level = MASK_GPIO_DATA(CORTEXM4_GPIOE_APB_BASE_ADDRESS,ChannelId);
  }else{
		MASK_GPIO_DATA(CORTEXM4_GPIOA_APB_BASE_ADDRESS,ChannelId) ^= 1<<ChannelId%8;
		level = MASK_GPIO_DATA(CORTEXM4_GPIOF_APB_BASE_ADDRESS,ChannelId);
	}
	return level;
}


/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
