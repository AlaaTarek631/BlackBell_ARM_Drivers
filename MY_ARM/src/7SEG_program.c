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


u8 SEG_ARRAY_VALUES[10][8]= {{1,1,1,1,1,1,0,0},
						  {0,1,1,0,0,0,0,0},
						  {1,1,0,1,1,0,1,0},
						  {1,1,1,1,0,0,1,0},
						  {0,1,1,0,0,1,1,0},
						  {1,0,1,1,0,1,1,0},
						  {1,0,1,1,1,1,1,0},
						  {1,1,1,1,0,0,0,0},
						  {1,1,1,1,1,1,1,0},
						  {1,1,1,1,0,1,1,0}};

void SEG_voidInit(SEGx * SEGobj)
{
    MGPIO_voidSetPortMode  (SEGobj->SEG_PORT, OUTPUT );
}
void SEG_voidDisplayChar(SEGx * SEGobj , u8 Copy_u8CharToDisplay)
{
	MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_a , SEG_ARRAY_VALUES[Copy_u8CharToDisplay][0]);
	MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_b , SEG_ARRAY_VALUES[Copy_u8CharToDisplay][1]);
	MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_c , SEG_ARRAY_VALUES[Copy_u8CharToDisplay][2]);
	MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_d , SEG_ARRAY_VALUES[Copy_u8CharToDisplay][3]);
	MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_e , SEG_ARRAY_VALUES[Copy_u8CharToDisplay][4]);
	MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_f , SEG_ARRAY_VALUES[Copy_u8CharToDisplay][5]);
	MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_g , SEG_ARRAY_VALUES[Copy_u8CharToDisplay][6]);
	MGPIO_voidSetPinValue           (SEGobj->SEG_PORT,SEGobj->pin_dp, SEG_ARRAY_VALUES[Copy_u8CharToDisplay][7]);
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


