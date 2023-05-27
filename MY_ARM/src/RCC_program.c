/*author: Alaa Tarek
date: 5/1/2023
compiler: ARM GCC
compiler version: v1.0
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInit(void)
{
    #if CPU_CLK_SOURCE == HSI
    //enable hsi
     SET_BIT  (RCC->CR,0);
    //select hsi as system clk
     CLR_BIT (RCC->CFGR,0);
     CLR_BIT (RCC->CFGR,1);
    #elif  CPU_CLK_SOURCE == HSE
    //enable HSE
     SET_BIT  (RCC->CR,16);
    //SELECT HSE AS SYSTEM CLK
     SET_BIT (RCC->CFGR,0);
     CLR_BIT (RCC->CFGR,1);

    #elif  CPU_CLK_SOURCE == PLL
        #if    PLL_SOURCE == HSI

        #elif  PLL_SOURCE == HSE
        
        #else
            #error "RCC CPU_CLK_SOURCE configuration error"asm
        #endif


    #else
        #error "RCC CPU_CLK_SOURCE configuration error"asm
    #endif

    #if RCC_AHB_PRESCALER > 15
        #error "RCC_AHB_PRESCALER Configuration Error"
    #else 
        RCC -> CFGR &= 0xFFFFFF0F;
        RCC -> CFGR |= RCC_AHB_PRESCALER << 4 ;
    #endif

}

void MRCC_voidEnablePeripheralClk(u8 Copy_u8PeripheralBus, u8 Copy_PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
        case 0:
        SET_BIT(RCC->AHB1ENR,Copy_PeripheralID);
        break;
        case 1:
        SET_BIT(RCC->AHB2ENR,Copy_PeripheralID);
        break;
        case 2:
        SET_BIT(RCC->APB1ENR,Copy_PeripheralID);
        break;
        case 3:
        SET_BIT(RCC->APB2ENR,Copy_PeripheralID);
        break;
        default:
        break;


    }

}

void MRCC_voidDisablePeripheralClk(u8 Copy_u8PeripheralBus, u8 Copy_PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
        case 0:
        CLR_BIT(RCC->AHB1ENR,Copy_PeripheralID);
        break;
        case 1:
        CLR_BIT(RCC->AHB2ENR,Copy_PeripheralID);
        break;
        case 2:
        CLR_BIT(RCC->APB1ENR,Copy_PeripheralID);
        break;
        case 3:
        CLR_BIT(RCC->APB2ENR,Copy_PeripheralID);
        break;
        default:
        break;


    }
}
