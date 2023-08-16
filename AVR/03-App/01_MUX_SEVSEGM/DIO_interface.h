/******************************************/
/********** name    : kerollos samaan *****/
/********** date    : 21/7/2023       *****/
/********** SWC     : DIO             *****/
/********** verison : v-1             *****/
/******************************************/




#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/*Macro For Ports*/
#define  DIO_u8_PORTA   0
#define  DIO_u8_PORTB   1
#define  DIO_u8_PORTC   2
#define  DIO_u8_PORTD   3

/*Macro For PINS*/
#define  DIO_u8_PIN0    0
#define  DIO_u8_PIN1	1
#define  DIO_u8_PIN2	2
#define  DIO_u8_PIN3	3
#define  DIO_u8_PIN4	4
#define  DIO_u8_PIN5	5
#define  DIO_u8_PIN6	6
#define  DIO_u8_PIN7	7

/*Macro For Pin Direction*/

#define  DIO_u8_OUTPUT  1
#define  DIO_u8_INPUT   0

/*Macro For Pin Value*/

#define  DIO_u8_HIGH  1
#define  DIO_u8_LOW   0



void DIO_voidInit(void); 

u8   DIO_u8SetPinDirection   (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_PinDirection);

u8   DIO_u8SetPinValue       (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_PinValue);

u8   DIO_u8GetPinValue       (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 * Copy_pu8ReturnedPinValue );
 
u8   DIO_u8SetPortDirection  (u8 Copy_u8PortId, u8 Copy_PortDirection);

u8   DIO_u8SetPortValue      (u8 Copy_u8PortId, u8 Copy_PortValue);

u8   DIO_u8GetPortValue      (u8 Copy_u8PortId, u8 * Copy_pu8ReturnedPortValue );

u8   DIO_u8TogglePin		 (u8 Copy_u8PortId, u8 Copy_u8PinId );

u8   DIO_u8SendMostNebble    (u8 Copy_u8PortId, u8 Copy_u8Status );

u8   DIO_u8SendLeastNebble   (u8 Copy_u8PortId, u8 Copy_u8Status);

#endif 