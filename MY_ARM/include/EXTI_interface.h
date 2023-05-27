#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define MEXTI_LINE0          0
#define MEXTI_LINE1          1
#define MEXTI_LINE2          2
#define MEXTI_LINE3          3
#define MEXTI_LINE4          4
#define MEXTI_LINE5          5
#define MEXTI_LINE6          6
#define MEXTI_LINE7          7
#define MEXTI_LINE8          8
#define MEXTI_LINE9          9
#define MEXTI_LINE10         10



#define MEXTI_RISING_EDGE    0
#define MEXTI_FALLING_EDGE   1
#define MEXTI_ON_CHANGE      2



void MEXTI_voidInit(void);
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTIlINE);
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTIlINE);
void MEXTI_ChangeSenseMode(u8 Copy_u8EXTIlINE, u8 Copy_u8SenseSinal);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTIlINE, void (*PuNotificationFunction)(void));


#endif 
