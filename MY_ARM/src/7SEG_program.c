/*******************************************************/
/*Authpr : Alaa Tarek
date : 13/5/2023
compiler: ARM GCC*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "7SEG_interface.h"
#include "7SEG_private.h"
#include "7SEG_config.h"

#include "GPIO_interface.h"

void SEG_voidInit(SEGx * SEGobj)
{
    MGPIO_voidSetPortMode  (SEGobj->SEG_PORT, OUTPUT );
}
void SEG_voidDisplayChar(SEGx * SEGobj , u8 Copy_u8CharToDisplay)
{
    switch (Copy_u8CharToDisplay)
    {
        case 0:
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        case 1:
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        case 2:
            MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        case 3:
            MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , LOW);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        case 4:
            MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        case 5:
            MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        case 6:
            MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        case 7:
            MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , LOW);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , LOW);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        case 8:
            MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        case 9:
            MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , HIGH );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , HIGH);
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
        break;
        default:
        break;


    }
}

void SEG_voidCLR(SEGx * SEGobj)
{
    MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , LOW );
             MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp , LOW );
}


