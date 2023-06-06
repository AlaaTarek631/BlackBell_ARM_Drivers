/*author: Alaa Tarek
date: 5/1/2023
compiler: ARM GCC
compiler version: v1.0
*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_voidInit(void)
{


    u8 Local_u8UCSRCTemp = 0;
    
    /*Set The USART Mode To Be Asynchronous Mode*/
    SET_BIT(UART1->CR1 , 13);

    /*Enable The Tx & Rx Circuits*/
    SET_BIT(UART1->CR1, 3);
    SET_BIT(UART1->CR1, 2);

    /*Set The Data Size Bits To Be 8-bit*/
    CLR_BIT(UART1->CR1, 12);

    /*Disable The Parity Mode*/
    CLR_BIT(UART1->CR1, 10);
    
    
    /*Stop Bit = 1-bit*/
    CLR_BIT(UART1->CR2, 13);
    CLR_BIT(UART1->CR2, 12);


    /*Set The Baudrate To Be 9600bps*/
    UART1->BRR |= 0x00000683

}

void UART_voidTransmitDataSynchronous(u8 Copy_u8Data)
{
    /*Polling (Busy Wait) On The UDR Empty Flag*/
    while(GET_BIT(UART1->SR, 7) == 0);
    /*Copy The Data To The UDR Register*/
    UART1->DR = Copy_u8Data;
    /*Polling (Busy Wait) On The TXC Flag*/
    while(GET_BIT(UART1->SR, 6) == 0);
    /* Clear The Flag */
    CLR_BIT(UART1->SR, 6);
}

void UART_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData)
{
    /*Polling (Busy Wait) On The Receive Complete Flag*/
    while(GET_BIT(UART1->SR, 5) == 0);
    /*Get The Received Data And Assign It To The Passed Variable*/
    *Copy_pu8ReceivedData = UART1->DR;
    CLR_BIT(UART1->SR, 6);
}