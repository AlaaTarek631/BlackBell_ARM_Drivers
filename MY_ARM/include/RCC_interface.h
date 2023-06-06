#ifndef     RCC_INTERFACE_H
#define     RCC_INTERFACE_H

#define RCC_AHB1    0
#define RCC_AHB2    1
#define RCC_APB1    2
#define RCC_APB2    3

#define RCC_GPIOA        0
#define RCC_GPIOB        1
#define RCC_GPIOC        2
#define RCC_SPI1		 12

#define	RCC_USART1		 4		//APB2


void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClk(u8 Copy_u8PeripheralBus, u8 Copy_PeripheralID);
void MRCC_voidDisablePeripheralClk(u8 Copy_u8PeripheralBus, u8 Copy_PeripheralID);

#endif
