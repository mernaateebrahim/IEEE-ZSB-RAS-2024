/*
 * main.c
 *
 *  Created on: Jul 1, 2024
 *      Author: Merna Atef
 */
#include <avr/io.h>
#include <util/delay.h>

#define DELAY 300

int main(void) {
    DDRA = 0b11111111; // port -> output

    while (1) {
        //Turn on the LEDs from bottom to top
        for (uint8_t i = 0; i < 8; i++) {
            PORTA = (1 << i);
            _delay_ms(DELAY);
        }

        //Turn on the LEDs from top to bottom
        for (int8_t i = 6; i >= 0; i--) {
            PORTA = (1 << i);
            _delay_ms(DELAY);
        }
    }
}
