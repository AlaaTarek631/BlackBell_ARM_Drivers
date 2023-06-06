#ifndef     GPIO_INTERFACE_H
#define     GPIO_INTERFACE_H

#define GPIO_PORTA    0
#define GPIO_PORTB    1
#define GPIO_PORTC    2
#define GPIO_PORTD    3

#define GPIO_PIN0   0
#define GPIO_PIN1   1
#define GPIO_PIN2   2
#define GPIO_PIN3   3
#define GPIO_PIN4   4
#define GPIO_PIN5   5
#define GPIO_PIN6   6
#define GPIO_PIN7   7
#define GPIO_PIN8   8
#define GPIO_PIN9   9
#define GPIO_PIN10  10
#define GPIO_PIN11  11
#define GPIO_PIN12  12
#define GPIO_PIN13  13
#define GPIO_PIN14  14
#define GPIO_PIN15  15

//choose the ouput mode 
#define GPIO_PUSH_PULL   0
#define GPIO_OPEN_DRAIN  1

//choose the input mode
#define GPIO_PULL_UP   0
#define GPIO_PULL_DOWN 1

#define INPUT   0
#define OUTPUT  1
#define AF  	2
#define ANALOG 	3


#define LOW      0
#define HIGH     1

#define MGPIO_LOW_SPEED 0
#define MGPIO_MEDIUM_SPEED 1
#define MGPIO_HIGH_SPEED 2
#define MGPIO_VHIGH_SPEED 3

#define SPI_ALTERNATIVE_FUNC 		0b0101

void MGPIO_voidSetPinDirection_Mode(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinMode,  u8 Copy_u8ModeType);

void  MGPIO_voidSetPortMode  (u8 Copy_u8PortName, u8 Copy_u32PortMode);

void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);

u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);

void MGPIO_voidChangeAltenativeFunction(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8FunctionValue);

void MGPIO_voidSetPinSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinSpeed);

#endif
