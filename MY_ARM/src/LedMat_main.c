#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_MAT_interface.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"



int main(void)
{
	MSTK_voidInit();
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOA);
	MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOB);

	LED_MAT_voidInit();
	u8 LED_MAT_Data[4] = {2,5,2,7};

	while(1)
	{

		LED_MAT_voidDisplay(LED_MAT_Data);

	}
}
