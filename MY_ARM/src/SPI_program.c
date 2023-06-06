/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		30 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  30 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void MSPI1_voidInit(void)
{
	MGPIO_voidSetPinDirection_Mode(MSPI1_MOSI_PORTPIN, AF, 0); // PA7 MOSI
	MGPIO_voidSetPinDirection_Mode(MSPI1_SCK_PORTPIN, AF, 0);  // PA5 SCK

	MGPIO_voidSetPinSpeed(MSPI1_MOSI_PORTPIN, MGPIO_LOW_SPEED);
	MGPIO_voidSetPinSpeed(MSPI1_SCK_PORTPIN, MGPIO_LOW_SPEED);

	MGPIO_voidChangeAltenativeFunction(MSPI1_MOSI_PORTPIN, 5);
	MGPIO_voidChangeAltenativeFunction(MSPI1_SCK_PORTPIN, 5);

	MGPIO_voidSetPinDirection_Mode(MSPI1_NSS_PORTPIN, AF,0);	// PA4 NSS
	MGPIO_voidSetPinDirection_Mode(MSPI1_NSS_PORTPIN, INPUT, GPIO_PULL_UP);
	MGPIO_voidChangeAltenativeFunction(MSPI1_NSS_PORTPIN, 5);

    /*Set The CPHA = 1, Write of the leading edge */
    SPI1 -> CR1 = 0x0347;    
}

u8 MSPI_u8TrancieveSynchronous(u8 Copy_u8Data, u8 * Copy_pu8ReceivedData)
{
    u8 Local_u8ReceivedData;
    SPI1 -> DR = Copy_u8Data;
    while(GET_BIT(SPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = SPI1 -> DR;
    return Local_u8ReceivedData;
}
