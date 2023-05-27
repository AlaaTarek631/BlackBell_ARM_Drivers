/*****************************************************************************************
 * Author:				Alaa Tarek
 * Creation Data:		22 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
*****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (* pvCallBack[16])(void) = {{NULL}};

void MEXTI_voidInit(void)
{

}	
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTIlINE)
{
	if(Copy_u8EXTIlINE >15)
	{
		return;
	}
	SET_BIT (MEXTI->IMR, Copy_u8EXTIlINE); 
}
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTIlINE)
{
	if(Copy_u8EXTIlINE >15)
	{
		return;
	}
	CLR_BIT (MEXTI->IMR, Copy_u8EXTIlINE); 
}
void MEXTI_ChangeSenseMode(u8 Copy_u8EXTIlINE, u8 Copy_u8SenseSignal)
{
	switch(Copy_u8SenseSignal)
	{
		case MEXTI_RISING_EDGE:
		CLR_BIT(MEXTI->FTSR,Copy_u8EXTIlINE);
		SET_BIT(MEXTI->RTSR,Copy_u8EXTIlINE);
		break;
		case MEXTI_FALLING_EDGE:
		CLR_BIT(MEXTI->RTSR,Copy_u8EXTIlINE);
		SET_BIT(MEXTI->FTSR,Copy_u8EXTIlINE);
		break;
		case MEXTI_ON_CHANGE:
		SET_BIT(MEXTI->RTSR,Copy_u8EXTIlINE);
		SET_BIT(MEXTI->FTSR,Copy_u8EXTIlINE);
		break;

	}
}
void MEXTI_voidSetCallBack(u8 Copy_u8EXTIlINE, void (*PuNotificationFunction)(void))
{
	pvCallBack[Copy_u8EXTIlINE]=PuNotificationFunction;

}

void EXTI0_IRQHandler(void)
{
	if (pvCallBack[0] != NULL)
	{
		pvCallBack[0]();
	}
	SET_BIT(MEXTI->PR,0);
	
}



