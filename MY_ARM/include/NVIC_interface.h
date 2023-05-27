#ifndef     NVIC_INTERFACE_H
#define     NVIC_INTEFACE_H

#define     MNVIC_EXTI0     6
#define     MNVIC_EXTI1     7

void MNVIC_voidInit(void);
void MNVIC_voidEnablePeripheralInterrupt(u32 copy_u8PeripheralID);
void MNVIC_voidDisablePeripheralInterrupt(u32 copy_u8PeripheralID);
void MNVIC_voidSetPendingFlag(u32 copy_u8PeripheralID);
void MNVIC_voidClrPendingFlag(u32 copy_u8PeripheralID);
u8 MNVIC_u8GetActiveFlag(u8 copy_u8PeripheralID);
void MNVIC_voidSetPeripheralPriority(u32 copy_u8PeripheralID, u8 Copy_u8Priority);


#endif