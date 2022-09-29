/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECTRESET   :1;
    uint32 VECTCLRACT  :1;
    uint32 SYSRESREQ   :1;
    uint32             :5;
    uint32 PRIGROUP    :3;
    uint32             :4;
    uint32 ENDINRSS    :1;
    uint32 VECTKEY     :16;
}APINT_BF;
typedef union 
{
    uint32 R;
    APINT_BF B;
}APINT_Tag;


typedef struct 
{
    uint32             :5;
    uint32 INTA        :3;
    uint32             :5;
    uint32 INTB        :3;
    uint32             :5;
    uint32 INTC        :3;
    uint32             :5;
    uint32 INTD        :3;
}PRI_BF;
typedef union 
{
    uint32 R;
    PRI_BF B;
}PRI_Tag;


typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef struct{
	uint32 PORTA : 1;
	uint32 PORTB : 1;
	uint32 PORTC : 1;
	uint32 PORTD : 1;
	uint32 PORTE : 1;
	uint32 PORTF : 1;
	uint32       : 18;
}RCGCGPIO_BF;

typedef struct{
	uint32 TIM0  : 1;
	uint32 TIM1  : 1;
	uint32 TIM2  : 1;
	uint32 TIM3  : 1;
	uint32 TIM4  : 1;
	uint32 TIM5  : 1;
	uint32       : 26;
}RCGCTIMER_BF;

typedef struct{
	uint32 PIN0  : 1;
	uint32 PIN1  : 1;
	uint32 PIN2  : 1;
	uint32 PIN3  : 1;
	uint32 PIN4  : 1;
	uint32 PIN5  : 1;
	uint32 PIN6  : 1;
	uint32 PIN7  : 1;
	uint32       : 24;
}GPIO_BF;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define CORTEXM4_SYSCTRL_BASE_ADDRESS          0x400FE000
#define CORTEXM4_GPIOA_APB_BASE_ADDRESS        0x40004000
#define CORTEXM4_GPIOB_APB_BASE_ADDRESS        0x40005000
#define CORTEXM4_GPIOC_APB_BASE_ADDRESS        0x40006000
#define CORTEXM4_GPIOD_APB_BASE_ADDRESS        0x40007000
#define CORTEXM4_GPIOE_APB_BASE_ADDRESS        0x40024000
#define CORTEXM4_GPIOF_APB_BASE_ADDRESS        0x40025000

#define RCGCTIMER                              (*((volatile RCGCTIMER_BF*)(CORTEXM4_SYSCTRL_BASE_ADDRESS+0x604)))
#define RCGCGPIO                               (*((volatile RCGCGPIO_BF*)(CORTEXM4_SYSCTRL_BASE_ADDRESS+0x608)))

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


#define EN0                                    (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100)))
#define EN1                                    (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104)))
#define EN2                                    (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108)))
#define EN3                                    (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C)))
	
#define PRI0                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x400)))
#define PRI1                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x404)))
#define PRI2                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x408)))
#define PRI3                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C)))
#define PRI4                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x410)))
#define PRI5                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x414)))
#define PRI6                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x418)))
#define PRI7                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C)))
#define PRI8                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x420)))
#define PRI9                                   (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x424)))
#define PRI10                                  (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x428)))
#define PRI11                                  (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C)))	
#define PRI12                                  (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x430)))
#define PRI13                                  (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x434)))
#define PRI14                                  (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x438)))
#define PRI15                                  (*((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C)))
	
#define SWTRIG                                 (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00)))
#define APINT                                  (*((volatile APINT_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C)))
#define INTCTRL                                (*((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
