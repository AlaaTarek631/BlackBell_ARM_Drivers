#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

typedef struct{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR12;
    volatile u32 CR3;
    volatile u32 GTPR;

}USART_t

#define         USART1      ((volatile USART_t *)0x40011000)

#endif
