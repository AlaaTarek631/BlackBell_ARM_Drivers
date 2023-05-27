#ifndef     SEG_INTERFACE_H
#define     SEG_INTERFACE_H

typedef struct{
/*
<MGPIO_PORTA ,MGPIO_PORTB ,MGPIO_PORTC >
*/
u8 SEG_PORT;
u8 pin_a;
u8 pin_b;
u8 pin_c;
u8 pin_d;
u8 pin_e;
u8 pin_f;
u8 pin_g;
u8 pin_dp;

}SEGx;

void SEG_voidInit(SEGx * SEGobj);
void SEG_voidDisplayChar(SEGx * SEGobj , u8 Copy_u8CharToDisplay);
void SEG_voidCLR(SEGx * SEGobj);

#endif