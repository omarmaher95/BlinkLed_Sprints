/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define INTCTRL_PRI_XXX                                0X0
#define INTCTRL_PRI_XXY                                0X5
#define INTCTRL_PRI_XYY                                0X6
#define INTCTRL_PRI_YYY                                0X7

#define INTCTRL_EXCEPTION_NUM                          1
#define INTCTRL_PRIORITY_GROUP                        INTCTRL_PRI_YYY


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	SP = -14,
	Reset,
	NMI,
	HardFault,
	MemFault,
	BusFault,
	UsageFault,
	SVCall = -5,
	DebugMonitor,
	PendSV = -2,
	SysTick,
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	UART0,
	UART1,
	SSIO0,
	I2C0,
	PWM0F,
	PWM0Gen0,
	PWM0Gen1,
	PWM0Gen2,
	QEI0,
	ADC0Seq0,
	ADC0Seq1,
	ADC0Seq2,
	ADC0Seq3,
	WD_TIM0_TIM1,
	TIM0A,
	TIM0B,
	TIM1A,
	TIM1B,
	TIM2A,
	TIM2B,
	AnalogComp0,
	AnalogComp1,
	SysCtrl = 28
}IntCtrl_InterruptType;



extern IntCtrl_InterruptType exceptionQueue[INTCTRL_EXCEPTION_NUM];
extern uint8 exceptionQueuePrority[INTCTRL_EXCEPTION_NUM];



#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
