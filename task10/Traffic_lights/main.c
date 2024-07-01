/*

 * main.c
 *
 *  Created on: Jul 1, 2024
 *      Author: Merna Atef
 */
#define F_CPU 8000000UL  // Frequency of the seven-segment display
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"

int main(void) {
    DDRC = 0xFF;  // Port for the RIGHT seven-segment display
    DDRD = 0xFF;  // Port for the LEFT seven-segment display
    DDRA = 0xFF;  // Ports for LEDs

    u8 segment[] = {
        0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
    };

    while (1) {
        // Red LED
        for (int i = 15; i > 0; i--) {
            PORTA = (1 << PA0);  // Turn on red LED
            PORTC = segment[i / 10];  // Tens place
            _delay_ms(5);
            PORTD = segment[i % 10];  // Ones place
            _delay_ms(5);
            _delay_ms(990);
        }

        // Yellow LED
        for (int i = 5; i > 0; i--) {
            PORTA = (1 << PA1);  // Turn on yellow LED
            PORTC = segment[i / 10];  // Tens place
            _delay_ms(5);
            PORTD = segment[i % 10];  // Ones place
            _delay_ms(5);
            _delay_ms(990);
        }

        // Green LED
        for (int i = 10; i > 0; i--) {
            PORTA = (1 << PA2);  // Turn on green LED
            PORTC = segment[i / 10];  // Tens place
            _delay_ms(5);
            PORTD = segment[i % 10];  // Ones place
            _delay_ms(5);
            _delay_ms(990);
        }
    }

    return 0;
}
