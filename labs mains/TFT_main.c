#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "SPI_interface.h"

#include "TFT_interface.h"

#include "MyImage.h"

void main(void)
{

	MRCC_voidInit();
	MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOA);
	MRCC_voidEnablePeripheralClk(RCC_APB2, RCC_SPI1);

	MSTK_voidInit();

	MSPI1_voidInit();


	HTFT_voidInit();



	//HTFT_voidSetWindow(0, 127, 0, 159);

	HTFT_voidDisplayImage(arr);

	while(1)
	{

	}
}
