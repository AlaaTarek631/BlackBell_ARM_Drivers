/*author: Alaa Tarek
date: 5/7/2023
compiler: ARM GCC
compiler version: v1.0
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidSetPinDirection_Mode(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinMode,  u8 Copy_u8ModeType)
{
    switch(Copy_u8Port)
    {
        case GPIO_PORTA:
        	switch (Copy_u8PinMode)
        	            {
        	                case INPUT:
        	                CLR_BIT(GPIO_A->GPIOx_MODER,(Copy_u8PinNumber*2));
        	                CLR_BIT(GPIO_A->GPIOx_MODER,((Copy_u8PinNumber*2)+1));
								switch(Copy_u8ModeType)
								{
									case GPIO_PULL_DOWN:
									CLR_BIT(GPIO_A->GPIOx_PUPDR,(Copy_u8PinNumber*2));
									SET_BIT(GPIO_A->GPIOx_PUPDR,((Copy_u8PinNumber*2)+1));
									break;
									case GPIO_PULL_UP:
									CLR_BIT(GPIO_A->GPIOx_PUPDR,((Copy_u8PinNumber*2)+1));
									SET_BIT(GPIO_A->GPIOx_PUPDR,(Copy_u8PinNumber*2));
									break;
									default:
									break;
								}
        	                break;
        	                case OUTPUT:
        	                SET_BIT(GPIO_A->GPIOx_MODER,(Copy_u8PinNumber*2));
        	                CLR_BIT(GPIO_A->GPIOx_MODER,((Copy_u8PinNumber*2)+1));
								switch(Copy_u8ModeType)
								{
									case GPIO_PUSH_PULL:
									CLR_BIT (GPIO_A->GPIOx_OTYPER,Copy_u8PinNumber);
									break;
									case GPIO_OPEN_DRAIN:
									SET_BIT (GPIO_A->GPIOx_OTYPER,Copy_u8PinNumber);
									break;
									default:
									break;

								}
        	                break;
        	            }
        	break;
        case GPIO_PORTB:
        	switch (Copy_u8PinMode)
        	        	            {
        	        	                case INPUT:
        	        	                CLR_BIT(GPIO_B->GPIOx_MODER,(Copy_u8PinNumber*2));
        	        	                CLR_BIT(GPIO_B->GPIOx_MODER,((Copy_u8PinNumber*2)+1));
        									switch(Copy_u8ModeType)
        									{
        										case GPIO_PULL_DOWN:
        										CLR_BIT(GPIO_B->GPIOx_PUPDR,(Copy_u8PinNumber*2));
        										SET_BIT(GPIO_B->GPIOx_PUPDR,((Copy_u8PinNumber*2)+1));
        										break;
        										case GPIO_PULL_UP:
        										CLR_BIT(GPIO_B->GPIOx_PUPDR,((Copy_u8PinNumber*2)+1));
        										SET_BIT(GPIO_B->GPIOx_PUPDR,(Copy_u8PinNumber*2));
        										break;
        										default:
        										break;
        									}
        	        	                break;
        	        	                case OUTPUT:
        	        	                SET_BIT(GPIO_B->GPIOx_MODER,(Copy_u8PinNumber*2));
        	        	                CLR_BIT(GPIO_B->GPIOx_MODER,((Copy_u8PinNumber*2)+1));
        									switch(Copy_u8ModeType)
        									{
        										case GPIO_PUSH_PULL:
        										CLR_BIT (GPIO_B->GPIOx_OTYPER,Copy_u8PinNumber);
        										break;
        										case GPIO_OPEN_DRAIN:
        										SET_BIT (GPIO_B->GPIOx_OTYPER,Copy_u8PinNumber);
        										break;
        										default:
        										break;

        									}
        	        	                break;
        	        	            }
        	        	break;
        case GPIO_PORTC:
        	switch (Copy_u8PinMode)
        	        	            {
        	        	                case INPUT:
        	        	                CLR_BIT(GPIO_C->GPIOx_MODER,(Copy_u8PinNumber*2));
        	        	                CLR_BIT(GPIO_C->GPIOx_MODER,((Copy_u8PinNumber*2)+1));
        									switch(Copy_u8ModeType)
        									{
        										case GPIO_PULL_DOWN:
        										CLR_BIT(GPIO_C->GPIOx_PUPDR,(Copy_u8PinNumber*2));
        										SET_BIT(GPIO_C->GPIOx_PUPDR,((Copy_u8PinNumber*2)+1));
        										break;
        										case GPIO_PULL_UP:
        										CLR_BIT(GPIO_C->GPIOx_PUPDR,((Copy_u8PinNumber*2)+1));
        										SET_BIT(GPIO_C->GPIOx_PUPDR,(Copy_u8PinNumber*2));
        										break;
        										default:
        										break;
        									}
        	        	                break;
        	        	                case OUTPUT:
        	        	                SET_BIT(GPIO_C->GPIOx_MODER,(Copy_u8PinNumber*2));
        	        	                CLR_BIT(GPIO_C->GPIOx_MODER,((Copy_u8PinNumber*2)+1));
        									switch(Copy_u8ModeType)
        									{
        										case GPIO_PUSH_PULL:
        										CLR_BIT (GPIO_C->GPIOx_OTYPER,Copy_u8PinNumber);
        										break;
        										case GPIO_OPEN_DRAIN:
        										SET_BIT (GPIO_C->GPIOx_OTYPER,Copy_u8PinNumber);
        										break;
        										default:
        										break;

        									}
        	        	                break;

                                }
        	            }
}

void    MGPIO_voidSetPortMode  (u8 Copy_u8PortName, u8 Copy_u32PortMode)
{
    switch (Copy_u8PortName)
    {
        case GPIO_PORTA:
                switch (Copy_u32PortMode)
                {
                    case INPUT:
                    GPIO_A->GPIOx_MODER =0X00000000;
                    break;
                    case OUTPUT:
                    GPIO_A->GPIOx_MODER =0X55555555;
                    break;
                    default:
                    break;

                }
        break;
        case GPIO_PORTB:
            switch (Copy_u32PortMode)
                {
                    case INPUT:
                    GPIO_B->GPIOx_MODER =0X00000000;
                    break;
                    case OUTPUT:
                    GPIO_B->GPIOx_MODER =0X55555555;
                    break;
                    default:
                    break;

                }
        break;
        case GPIO_PORTC:
        switch (Copy_u32PortMode)
                {
                    case INPUT:
                    GPIO_C->GPIOx_MODER =0X00000000;
                    break;
                    case OUTPUT:
                    GPIO_C->GPIOx_MODER =0X55555555;
                    break;
                    default:
                    break;

                }
        break;
        default:
        break;

    }
}
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    switch(Copy_u8Port)
    {
        case GPIO_PORTA:
                    switch(Copy_u8PinValue)
                    {
                        case LOW:
                            SET_BIT(GPIO_A->GPIOx_BSRR,(Copy_u8PinNumber+16));
                        break;
                        case HIGH:
                            SET_BIT(GPIO_A->GPIOx_BSRR,Copy_u8PinNumber);
                        break;
                        default:
                        break;
                    }
        break;
        case GPIO_PORTB:
                    switch(Copy_u8PinValue)
                    {
                        case LOW:
                            SET_BIT(GPIO_B->GPIOx_BSRR,(Copy_u8PinNumber+16));
                        break;
                        case HIGH:
                            SET_BIT(GPIO_B->GPIOx_BSRR,Copy_u8PinNumber);
                        break;
                        default:
                        break;
                    }
        break;
        case GPIO_PORTC:
                    switch(Copy_u8PinValue)
                    {
                        case LOW:
                            SET_BIT(GPIO_C->GPIOx_BSRR,(Copy_u8PinNumber+16));
                        break;
                        case HIGH:
                            SET_BIT(GPIO_C->GPIOx_BSRR,Copy_u8PinNumber);
                        break;
                        default:
                        break;
                    }
        break;
        default:
        break;
    }
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    u8 Local_u8PinValue ;
   
    switch (Copy_u8PortName)
    {
    case GPIO_PORTA:

        Local_u8PinValue = GET_BIT(GPIO_A->GPIOx_IDR, Copy_u8PinNumber);
        break;

    case GPIO_PORTB:
       
        Local_u8PinValue = GET_BIT(GPIO_B->GPIOx_IDR, Copy_u8PinNumber);
        break;

    case GPIO_PORTC:
       
        Local_u8PinValue = GET_BIT(GPIO_C->GPIOx_IDR, Copy_u8PinNumber);
        break;
    default:
    	break;
    }

 
    return Local_u8PinValue;
}
