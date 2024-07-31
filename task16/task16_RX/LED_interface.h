/*

 * LED_interface.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Merna Atef
 */
#include "DIO_interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#ifndef   LED_INTERFACE_H_
#define   LED_INTERFACE_H_

#define ACTIVE_HIGH 1
#define ACTIVE_LOW 0

typedef struct {
	u8 port;
	u8 pin;
	u8 Active_state;
}LED_TYPE;

void LED_VoidInit(LED_TYPE LED_Configuration);
void LED_VoidOn(LED_TYPE LED_Configuration);
void LED_VoidOff(LED_TYPE LED_Configuration);
void LED_voidToggle(LED_TYPE LED_Configuration);

#endif



