/*

 * DIO_interface.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Merna Atef
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT  0

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

typedef enum
{ DIO_NOK,
	DIO_OK
	}DIO_ErrorStatus;

    //IO PINS
	DIO_ErrorStatus DIO_VoidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction);
	DIO_ErrorStatus DIO_VoidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value);
	u8 DIO_VoidGetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN);
	DIO_ErrorStatus DIO_TogglePortValue(u8 Copy_u8PORT);
	//IO PORT
	DIO_ErrorStatus DIO_VoidSetPortDirection(u8 Copy_u8PORT, u8 Copy_u8Direction);
	DIO_ErrorStatus DIO_VoidSetPortValue(u8 Copy_u8PORT, u8 Copy_u8Value);
	u8 DIO_VoidGetPortDirection(u8 Copy_u8PORT, u8 Copy_u8PIN);
	DIO_ErrorStatus DIO_TogglePortValue(u8 Copy_u8PORT);
	#endif

