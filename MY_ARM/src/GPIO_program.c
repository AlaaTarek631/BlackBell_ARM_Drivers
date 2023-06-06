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

void MGPIO_voidSetPinSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinSpeed)
{
    switch (Copy_u8PortName)
    {
    case GPIO_PORTA:
        switch (Copy_u8PinSpeed)
        {
        case MGPIO_LOW_SPEED:
            GPIO_A->GPIOx_OSPEEDR |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_MEDIUM_SPEED:
            GPIO_A->GPIOx_OSPEEDR |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_HIGH_SPEED:
            GPIO_A->GPIOx_OSPEEDR |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_VHIGH_SPEED:
            GPIO_A->GPIOx_OSPEEDR |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case GPIO_PORTB:
        switch (Copy_u8PinSpeed)
        {
        case MGPIO_LOW_SPEED:
            GPIO_B->GPIOx_OSPEEDR |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_MEDIUM_SPEED:
            GPIO_B->GPIOx_OSPEEDR |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_HIGH_SPEED:
            GPIO_B->GPIOx_OSPEEDR |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_VHIGH_SPEED:
            GPIO_B->GPIOx_OSPEEDR |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;
        break;

    case GPIO_PORTC:
        switch (Copy_u8PinSpeed)
        {
        case MGPIO_LOW_SPEED:
            GPIO_C->GPIOx_OSPEEDR |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_MEDIUM_SPEED:
            GPIO_C->GPIOx_OSPEEDR |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_HIGH_SPEED:
            GPIO_C->GPIOx_OSPEEDR |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_VHIGH_SPEED:
            GPIO_C->GPIOx_OSPEEDR |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;
        break;
    }
}

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
        	                case AF:
        	                	GPIO_A->GPIOx_MODER |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
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
        									case AF:
        									 GPIO_B->GPIOx_MODER |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
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
        									case AF:
        									GPIO_C->GPIOx_MODER |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
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

void MGPIO_voidChangeAltenativeFunction(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8FunctionValue)
{
	switch (Copy_u8PortName)
	{
	    case GPIO_PORTA:
	    	if (Copy_u8PinNumber<8)
	    		    		    	{
	    		    		    		GPIO_A ->GPIOx_AFRL &= ~ (0b1111 << (Copy_u8PinNumber*4));
	    		    		    		GPIO_A -> GPIOx_AFRL   |= (Copy_u8FunctionValue << (Copy_u8PinNumber*4));
	    		    		    	}
	    		    		    	else
	    		    		    	{
	    		    		    		GPIO_A -> GPIOx_AFRH &= ~ (0b1111 << ((Copy_u8PinNumber-8)*4));
	    		    		    		 GPIO_A -> GPIOx_AFRH |= (Copy_u8FunctionValue << ((Copy_u8PinNumber-8)*4));
	    		    		    	}
	    	break;
	    case GPIO_PORTB:
	    	if (Copy_u8PinNumber<8)
	    		    	{
	    		    		GPIO_B ->GPIOx_AFRL &= ~ (0b1111 << (Copy_u8PinNumber*4));
	    		    		GPIO_B -> GPIOx_AFRL   |= (Copy_u8FunctionValue << (Copy_u8PinNumber*4));
	    		    	}
	    		    	else
	    		    	{
	    		    		GPIO_B -> GPIOx_AFRH &= ~ (0b1111 << ((Copy_u8PinNumber-8)*4));
	    		    		 GPIO_B -> GPIOx_AFRH |= (Copy_u8FunctionValue << ((Copy_u8PinNumber-8)*4));
	    		    	}
	    	break;
	    case GPIO_PORTC:
	    	if (Copy_u8PinNumber<8)
	    		    		    	{
	    		    		    		GPIO_C ->GPIOx_AFRL &= ~ (0b1111 << (Copy_u8PinNumber*4));
	    		    		    		GPIO_C -> GPIOx_AFRL   |= (Copy_u8FunctionValue << (Copy_u8PinNumber*4));
	    		    		    	}
	    		    		    	else
	    		    		    	{
	    		    		    		GPIO_C -> GPIOx_AFRH &= ~ (0b1111 << ((Copy_u8PinNumber-8)*4));
	    		    		    		 GPIO_C -> GPIOx_AFRH |= (Copy_u8FunctionValue << ((Copy_u8PinNumber-8)*4));
	    		    		    	}
	    	 break;
	}
}
