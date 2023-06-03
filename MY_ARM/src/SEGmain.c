#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "7SEG_interface.h"

int main(void)
{
	MSTK_voidInit();


	u8 Copy_u8Counter;

			SEGx SEG1;

			SEG1.SEG_PORT =  GPIO_PORTB;

			SEG1.pin_a = GPIO_PIN0;
			SEG1.pin_b = GPIO_PIN1;
			SEG1.pin_c = GPIO_PIN2;
			SEG1.pin_d = GPIO_PIN3;
			SEG1.pin_e = GPIO_PIN4;
			SEG1.pin_f = GPIO_PIN5;
			SEG1.pin_g = GPIO_PIN6;
			SEG1.pin_dp = GPIO_PIN7;

			SEGx SEG2;

			SEG2. SEG_PORT =  GPIO_PORTA;

			SEG2.pin_a = GPIO_PIN4;
			SEG2.pin_b = GPIO_PIN5;
			SEG2.pin_c = GPIO_PIN6;
			SEG2.pin_d = GPIO_PIN7;
			SEG2.pin_e = GPIO_PIN8;
			SEG2.pin_f = GPIO_PIN9;
			SEG2.pin_g = GPIO_PIN10;
			SEG2.pin_dp = GPIO_PIN11;

			SEG_voidInit(&SEG1);
			SEG_voidInit(&SEG2);

			SEG_voidDisplayChar(&SEG1, 8);

	while (1)
	{

		for (Copy_u8Counter=0 ; Copy_u8Counter<10 ; Copy_u8Counter++)
		{
			for (Copy_u8Counter1=0 ; Copy_u8Counter1<10 ; Copy_u8Counter1++)
			{
			SEG_voidDisplayChar(&SEG1, Copy_u8Counter);
			SEG_voidDisplayChar(&SEG2, Copy_u8Counter1);
			MSTK_voidSetBusyWait(100000);
			SEG_voidCLR(&SEG1);
			SEG_voidCLR(&SEG2);

		}
	}
*/

}
