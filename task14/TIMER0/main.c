/*

 * main.c
 *
 *  Created on: Jul 22, 2024
 *      Author: Merna Atef
 */
#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>
#include "TIMER_interface.h"
#include "DIO_interface.h"

#define BUTTON_PORT DIO_PORTC
#define BUTTON_INC_PIN DIO_PIN0
#define BUTTON_RESET_PIN DIO_PIN1
#define BUTTON_DEC_PIN DIO_PIN2

typedef unsigned char u8;

void adjustDutyCycles(void) {
    static u8 temp = 0;
    u8 buttonValue;

    // Increase duty cycle
    DIO_enumGetPinValue(BUTTON_PORT, BUTTON_INC_PIN, &buttonValue);
    if (buttonValue == DIO_PIN_LOW) {
        _delay_ms(250);
        if (temp < 90) temp += 10;
    }

    // Set duty cycle to zero
    DIO_enumGetPinValue(BUTTON_PORT, BUTTON_RESET_PIN, &buttonValue);
    if (buttonValue == DIO_PIN_LOW) {
        _delay_ms(250);
        temp = 0;
    }

    // Decrease duty cycle
    DIO_enumGetPinValue(BUTTON_PORT, BUTTON_DEC_PIN, &buttonValue);
    if (buttonValue == DIO_PIN_LOW) {
        _delay_ms(250);
        if (temp > 0) temp -= 10;
    }

    TIMER_voidSetPWM((0xFF * temp) / 100);
}

int main(void) {
    // Set PC0, PC1, PC2 as inputs and enable internal pull-up resistors
    DIO_enumSetPinDirection(BUTTON_PORT, BUTTON_INC_PIN, DIO_PIN_INPUT);
    DIO_enumSetPinDirection(BUTTON_PORT, BUTTON_RESET_PIN, DIO_PIN_INPUT);
    DIO_enumSetPinDirection(BUTTON_PORT, BUTTON_DEC_PIN, DIO_PIN_INPUT);

    DIO_enumConnectPullup(BUTTON_PORT, BUTTON_INC_PIN, DIO_PIN_HIGH);
    DIO_enumConnectPullup(BUTTON_PORT, BUTTON_RESET_PIN, DIO_PIN_HIGH);
    DIO_enumConnectPullup(BUTTON_PORT, BUTTON_DEC_PIN, DIO_PIN_HIGH);

    // Initialize Timer0 in Fast PWM mode
    TIMER0_voidInit();

    // Set PB3 as output for PWM
    DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);

    // Set initial duty cycle to 0%
    TIMER_voidSetPWM(0);

    while (1) {
        adjustDutyCycles();
    }
}
