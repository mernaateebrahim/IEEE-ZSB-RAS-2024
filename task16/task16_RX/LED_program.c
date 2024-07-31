/*

 * LED_program.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Merna Atef
 */
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

// Structure to define LED properties
typedef struct {
    u8 Port;            // Port of the LED
    u8 Pin;             // Pin of the LED
    u8 Active_State;    // Active state of the LED (ACTIVE_HIGH or ACTIVE_LOW)
} LED_TYPE;

// Initialize the LED
void LED_voidInit(LED_TYPE LED_Configuration) {
    DIO_enumSetPinDirection(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_OUTPUT);
}

// Turn on the LED
void LED_VoidOn(LED_TYPE LED_Configuration) {
    if (LED_Configuration.Active_State == ACTIVE_HIGH) {
        DIO_enumSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_HIGH);
    } else if (LED_Configuration.Active_State == ACTIVE_LOW) {
        DIO_enumSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_LOW);
    }
}

// Turn off the LED
void LED_VoidOff(LED_TYPE LED_Configuration) {
    if (LED_Configuration.Active_State == ACTIVE_HIGH) {
        DIO_enumSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_LOW);
    } else if (LED_Configuration.Active_State == ACTIVE_LOW) {
        DIO_enumSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_HIGH);
    }
}

// Toggle the LED state
void LED_voidToggle(LED_TYPE LED_Configuration) {
    DIO_enumTogglePinValue(LED_Configuration.Port, LED_Configuration.Pin);
}

#endif // LED_INTERFACE_H_
