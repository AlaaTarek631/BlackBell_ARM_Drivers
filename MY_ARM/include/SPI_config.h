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
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define MSPI1_MOSI_PORTPIN		GPIO_PORTA , GPIO_PIN7
#define MSPI1_MISO_PORTPIN		GPIO_PORTA , GPIO_PIN6
#define MSPI1_SCK_PORTPIN		GPIO_PORTA , GPIO_PIN5
#define MSPI1_NSS_PORTPIN		GPIO_PORTA , GPIO_PIN4

#endif
