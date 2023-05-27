/*******************************/
/*
Author : Alaa Tarek
Date : 5/14/2023
compiler : GNU : ARM-GCC
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LED_MAT_interface.h"
#include "LED_MAT_private.h"
#include "LED_MAT_config.h"

void LED_MAT_voidInit(void)
{

	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_R0_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_R1_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_R2_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_R3_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_R4_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_R5_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_R6_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_R7_PIN, OUTPUT,GPIO_PUSH_PULL);

	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_C0_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_C1_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_C2_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_C3_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_C4_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_C5_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_C6_PIN, OUTPUT,GPIO_PUSH_PULL);
	MGPIO_voidSetPinDirection_Mode            (HLED_MAT_C7_PIN, OUTPUT,GPIO_PUSH_PULL);

	voidDisableAllColumns();

}

void LED_MAT_voidDisplay(u8 * Copy_pu8Data)
{
	u8 Local_u8ColuNo = 0;
	u8 Local_u8RowNo =0;
	u8 Local_u8Bit =0;
	u8 Local_u8Counter =0;
	static u8 Rows_Array[16] = {HLED_MAT_R0_PIN,HLED_MAT_R1_PIN,HLED_MAT_R2_PIN,HLED_MAT_R3_PIN,HLED_MAT_R4_PIN,HLED_MAT_R5_PIN,HLED_MAT_R6_PIN,HLED_MAT_R7_PIN};
	static u8 Columns_Array[16] = {HLED_MAT_C0_PIN,HLED_MAT_C1_PIN,HLED_MAT_C2_PIN,HLED_MAT_C3_PIN,HLED_MAT_C4_PIN,HLED_MAT_C5_PIN,HLED_MAT_C6_PIN,HLED_MAT_C7_PIN};
	for (Local_u8ColuNo = 0; Local_u8ColuNo <=7; Local_u8ColuNo++)
	{

		for (Local_u8RowNo = 0; Local_u8RowNo <=7; Local_u8RowNo++)
		{
			Local_u8Bit = GET_BIT (Copy_pu8Data[Local_u8ColuNo],Local_u8RowNo);
			for (Local_u8Counter = 0; Local_u8Counter <=15; Local_u8Counter++)
			{
				MGPIO_voidSetPinDirection_Mode(Rows_Array[Local_u8Counter],Rows_Array[Local_u8Counter+1], Local_u8Bit,GPIO_PUSH_PULL);
			}
		}
		voidDisableAllColumns();

		MGPIO_voidSetPinDirection_Mode(Columns_Array[Local_u8ColuNo*2],Columns_Array[Local_u8ColuNo+1], OUTPUT,GPIO_PUSH_PULL);
		MSTK_voidSetBusyWait(2500);
	}

}

static void voidDisableAllColumns()
{

	MGPIO_voidSetPinValue(HLED_MAT_C0_PIN, HIGH);
	MGPIO_voidSetPinValue(HLED_MAT_C1_PIN, HIGH);
	MGPIO_voidSetPinValue(HLED_MAT_C2_PIN, HIGH);
	MGPIO_voidSetPinValue(HLED_MAT_C3_PIN, HIGH);
	MGPIO_voidSetPinValue(HLED_MAT_C4_PIN, HIGH);
	MGPIO_voidSetPinValue(HLED_MAT_C5_PIN, HIGH);
	MGPIO_voidSetPinValue(HLED_MAT_C6_PIN, HIGH);
	MGPIO_voidSetPinValue(HLED_MAT_C7_PIN, HIGH);
}

