/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		08 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  08 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define NULL	((void *)0)

typedef struct {

volatile u32 IMR;
volatile u32 EMR;
volatile u32 RTSR;
volatile u32 FTSR;
volatile u32 SWIER;
volatile u32 PR;

}EXTI_t;

#define     MEXTI         ((volatile EXTI_t *)0x40013C00)
#define     SYSCFGCR1    *((volatile u32 *)0x40013808)

#define     MEXTI_DISABLE 0
#define     MEXTI_ENABLE  1 


#endif 
