/*

 * main.c
 *
 *  Created on: Jul 4, 2024
 *      Author: Merna Atef
 */
#include <avr/io.h>
#include <util/delay.h>

#define DELAY 300

int main(void) {
    DDRC = 0b00000000; // Port C -> Input
    DDRD = 0b11111111; // Port D -> Output

    while (1) {
        // Turn on the LEDs from bottom to top
        if (PINC == 0b00000001) {
            for (uint8_t i = 0; i < 8; i++) {
                PORTD = (1 << i);
                _delay_ms(DELAY);

            }
            PORTD=0b00000000;
        }
        // Turn on the LEDs from top to bottom
        else if (PINC == 0b00000010) {
            for (int8_t i = 7; i >= 0; i--) { // Starting from 7 since we have 8 LEDs
                PORTD = (1 << i);
                _delay_ms(DELAY);
            }
            PORTD=0b00000000;
        }
    }
}
