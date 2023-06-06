#ifndef     GPIO_PRIVATE_H
#define     GPIO_PRIVATE_H


typedef  struct
{
    volatile u32 GPIOx_MODER;
    volatile u32 GPIOx_OTYPER;
    volatile u32 GPIOx_OSPEEDR;
    volatile u32 GPIOx_PUPDR;
    volatile u32 GPIOx_IDR;
    volatile u32 GPIOx_ODR;
    volatile u32 GPIOx_BSRR;
    volatile u32 GPIOx_LCKR;
    volatile u32 GPIOx_AFRL;
    volatile u32 GPIOx_AFRH;


}GPIO_x;

#define GPIO_A     ((volatile GPIO_x *)0x40020000)
#define GPIO_B     ((volatile GPIO_x *)0x40020400)
#define GPIO_C     ((volatile GPIO_x *)0x40020800)
#define GPIO_D     ((volatile GPIO_x *)0x40020C00)

#define	PIN_BITS_OFFSET	2

#endif
