/*author: Alaa Tarek
date: 5/21/2023
compiler: ARM GCC
compiler version: v1.0
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
    SCB_AIRCR = (AIRCR_PRIVKEY << 16) | (MNVIC_GRP_SUB_DISTRIBUTION<<8);
}

void MNVIC_voidEnablePeripheralInterrupt(u32 copy_u8PeripheralID)
{

    MNVIC-> ISER[copy_u8PeripheralID/32] = (1<<(copy_u8PeripheralID%32));
}
void MNVIC_voidDisablePeripheralInterrupt(u32 copy_u8PeripheralID)
{
    MNVIC-> ICER[copy_u8PeripheralID/32] = (1<<(copy_u8PeripheralID%32));
}
void MNVIC_voidSetPendingFlag(u32 copy_u8PeripheralID)
{
    MNVIC-> ISPR[copy_u8PeripheralID/32] = (1<<(copy_u8PeripheralID%32));
}
void MNVIC_voidClrPendingFlag(u32 copy_u8PeripheralID)
{
    MNVIC-> ICPR[copy_u8PeripheralID/32] = (1<<(copy_u8PeripheralID%32));
}

u8 MNVIC_u8GetActiveFlag(u8 copy_u8PeripheralID)
{
    
   return (GET_BIT(MNVIC-> IABR[copy_u8PeripheralID/32],(copy_u8PeripheralID%32) )) ;

}
void MNVIC_voidSetPeripheralPriority(u32 copy_u8PeripheralID, u8 Copy_u8Priority)
{
    MNVIC-> IPR[copy_u8PeripheralID] = (Copy_u8Priority<<4);
}
