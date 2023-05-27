#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "7SEG_interface.h"

int main(void)
{

u8 Copy_u8Counter;

SEGx *SEG1;

SEG1-> SEG_PORT =  GPIO_PORTB;

SEG1->pin_a = GPIO_PIN0;
SEG1->pin_b = GPIO_PIN1;
SEG1->pin_c = GPIO_PIN2;
SEG1->pin_d = GPIO_PIN3;
SEG1->pin_e = GPIO_PIN4;
SEG1->pin_f = GPIO_PIN5;
SEG1->pin_g = GPIO_PIN6;
SEG1->pin_dp = GPIO_PIN7;

SEG_voidInit(&SEG1);

for (Copy_u8Counter=0 ; Copy_u8Counter<10 ; Copy_u8Counter++)
{
	SEG_voidDisplayChar(&SEG1, Copy_u8Counter);
	SEG_voidCLR(&SEG1);
}

}
