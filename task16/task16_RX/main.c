/*
 * main.c
 *
 *  Created on: Jul 31, 2024
 *      Author: Merna Atef
 */
#include <avr/io.h>
#include "STD_TYPES.h"
#include "UART_interface.h"
#include "DIO_interface.h"
#include "LED_interface.h"

void main(void) {
    // Initialize UART
    USART_voidInit();

    // Set Port C as output for LEDs
    DIO_VoidSetPortDirection(DIO_PORTC, 0xFF); // 0xFF means all pins as output

    u8 receivedData;

    // Initialize LEDs
    LED_TYPE LED0 = {DIO_PORTC, DIO_PIN0, ACTIVE_HIGH};
    LED_TYPE LED1 = {DIO_PORTC, DIO_PIN1, ACTIVE_HIGH};
    LED_TYPE LED2 = {DIO_PORTC, DIO_PIN2, ACTIVE_HIGH}; // Changed to DIO_PIN2
    LED_TYPE LED3 = {DIO_PORTC, DIO_PIN3, ACTIVE_HIGH}; // Changed to DIO_PIN3
    LED_VoidInit(LED0);
    LED_VoidInit(LED1);
    LED_VoidInit(LED2);
    LED_VoidInit(LED3);

    while (1) {
        // Receive data from UART
        if (USART_u8RecevieData(&receivedData) == 1) {
            if (receivedData == 0x01) {
                // Turn on LED0 and turn off LED1
                LED_VoidOn(LED0);
                LED_VoidOff(LED1);
                LED_VoidOff(LED2); // Ensure other LEDs are turned off
                LED_VoidOff(LED3);
            } else if (receivedData == 0x02) {
                // Turn on LED1 and turn off LED0
                LED_VoidOn(LED1);
                LED_VoidOff(LED0);
                LED_VoidOff(LED2); // Ensure other LEDs are turned off
                LED_VoidOff(LED3);
            } else if (receivedData == 0x03) {
                // Turn on LED2 and turn off LED0 and LED1
                LED_VoidOn(LED2);
                LED_VoidOff(LED0);
                LED_VoidOff(LED1);
                LED_VoidOff(LED3);
            } else if (receivedData == 0x04) {
                // Turn on LED3 and turn off LED0, LED1, and LED2
                LED_VoidOn(LED3);
                LED_VoidOff(LED0);
                LED_VoidOff(LED1);
                LED_VoidOff(LED2);
            }
        }
    }
}


