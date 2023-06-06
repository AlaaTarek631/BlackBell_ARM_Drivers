#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);
void UART_voidTransmitDataSynchronous(u8 Copy_u8Data);
void UART_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData);

#endif
