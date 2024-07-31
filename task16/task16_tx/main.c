/*
 * main.c
 *
 *  Created on: Jul 31, 2024
 *      Author: Merna Atef
 */
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "UART_interface.h"
#include "DIO_interface.h"

void main(void) {
    // Initialize UART
    USART_voidInit();

    // Set Port C pins 0 and 1 as input
    DIO_VoidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
    DIO_VoidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_INPUT);

    while (1) {
        // Check the state of the switches and send corresponding data
        if (DIO_VoidGetPinValue(DIO_PORTA, DIO_PIN0) == DIO_PIN_HIGH) {
            USART_u8SendData(0x01); // Send 0x01 if switch connected to PIN0 is pressed
        } else if (DIO_VoidGetPinValue(DIO_PORTA, DIO_PIN1) == DIO_PIN_HIGH) {
            USART_u8SendData(0x02); // Send 0x02 if switch connected to PIN1 is pressed
        }

        _delay_ms(300); // Delay to debounce switch presses
    }
}
