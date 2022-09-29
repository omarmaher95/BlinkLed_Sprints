/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  GPIO module configuration
 *      \details  The Driver Configure All MCU gpios functions and internal configuration
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
//GPIO Registers helping Macros
#define GPIO_DATA(Port_GpioBase)                   (*((volatile uint32*)(Port_GpioBase+0x000)))
#define GPIO_DIR(Port_GpioBase)                    (*((volatile uint32*)(Port_GpioBase+0x400)))
#define GPIO_IM(Port_GpioBase)                     (*((volatile uint32*)(Port_GpioBase+0x410)))
#define GPIO_AFSEL(Port_GpioBase)                  (*((volatile uint32*)(Port_GpioBase+0x420)))
#define GPIO_DR2R(Port_GpioBase)                   (*((volatile uint32*)(Port_GpioBase+0x500)))
#define GPIO_DR4R(Port_GpioBase)                   (*((volatile uint32*)(Port_GpioBase+0x504)))
#define GPIO_DR8R(Port_GpioBase)                   (*((volatile uint32*)(Port_GpioBase+0x508)))
#define GPIO_ODR(Port_GpioBase)                    (*((volatile uint32*)(Port_GpioBase+0x50C)))
#define GPIO_PUR(Port_GpioBase)                    (*((volatile uint32*)(Port_GpioBase+0x510)))
#define GPIO_PDR(Port_GpioBase)                    (*((volatile uint32*)(Port_GpioBase+0x514)))
#define GPIO_DEN(Port_GpioBase)                    (*((volatile uint32*)(Port_GpioBase+0x51C)))
#define GPIO_LOCK(Port_GpioBase)                   (*((volatile uint32*)(Port_GpioBase+0x520)))
#define GPIO_CR(Port_GpioBase)                     (*((volatile uint32*)(Port_GpioBase+0x524)))
#define GPIO_PCTL(Port_GpioBase)                   (*((volatile uint32*)(Port_GpioBase+0x52C)))

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
void Port_Init(const Port_ConfigType * ConfigPtr){
	Port_PortType gpioPort = ConfigPtr->gpioPort;
	Port_PinType pinType = ConfigPtr->pinType;
	Port_ModeType modeType = ConfigPtr->modeType;
	Port_InternalAttachType internalAttachType = ConfigPtr->internalAttachType;
	Port_OutputCurrentType outputCurrentType = ConfigPtr->outputCurrentType;	
	uint32 gpioBase;
	switch(gpioPort){
		case Port_GPIOA:
			RCGCGPIO.PORTA = 1;
		  gpioBase = CORTEXM4_GPIOA_APB_BASE_ADDRESS;
		  break;
		case Port_GPIOB:
			RCGCGPIO.PORTB = 1;
      gpioBase = CORTEXM4_GPIOB_APB_BASE_ADDRESS;
		  break;
		case Port_GPIOC:
			RCGCGPIO.PORTC = 1; 
		  gpioBase = CORTEXM4_GPIOC_APB_BASE_ADDRESS;
		  break;
		case Port_GPIOD:
			RCGCGPIO.PORTD = 1;
      gpioBase = CORTEXM4_GPIOD_APB_BASE_ADDRESS;
		  break;
		case Port_GPIOE:
			RCGCGPIO.PORTE = 1;
		  gpioBase = CORTEXM4_GPIOE_APB_BASE_ADDRESS;
		  break;
		case Port_GPIOF:
			RCGCGPIO.PORTF = 1;
		  gpioBase = CORTEXM4_GPIOF_APB_BASE_ADDRESS;
		  break;
	}
  GPIO_LOCK(gpioBase) = PORT_GPIOKEY;             
  GPIO_CR(gpioBase) |= (1 << pinType); 
  switch(modeType){
		case DIGITAL:
			GPIO_AFSEL(gpioBase) &= ~(1 << pinType);
		  break;
		default:
			GPIO_AFSEL(gpioBase) |= (1 << pinType);
		  GPIO_PCTL(gpioBase) &= ~((uint32)(modeType) << pinType*4);   
		  GPIO_PCTL(gpioBase) |= ((uint32)(modeType) << pinType*4);   
	}         
  switch(internalAttachType){
		case OPENDRAIN:
			 GPIO_ODR(gpioBase) |= (1 << pinType);
	     break;
		case PULLDOWN:
			 GPIO_PDR(gpioBase) |= (1 << pinType);            
       break;
		case PULLUP:
			 GPIO_PUR(gpioBase) |= (1 << pinType);            
       break;
	}
	switch(outputCurrentType){
		case DRV2:
			GPIO_DR2R(gpioBase) |= (1 << pinType);
		  break;
		case DRV4:
			GPIO_DR4R(gpioBase) |= (1 << pinType);
		  break;
		case DRV8:
			GPIO_DR8R(gpioBase) |= (1 << pinType);
		  break;
	}
	switch(ConfigPtr->directionType){
		case OUTPUT:
			GPIO_DIR(gpioBase) |= (1 << pinType); 
      break;		
		case INPUT:
			GPIO_DIR(gpioBase) &= ~(1 << pinType); 
      break;	

	}
	GPIO_DEN(gpioBase) |= (1 << pinType);            

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
