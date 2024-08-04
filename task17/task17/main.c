/*
 * main.c
 *
 *  Created on: Aug 4, 2024
 *      Author: Merna Atef
 */
#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>
#include "SPI_interface.h"
#include "DIO_interface.h"

void tc72Init(void) {
    // Set PB4 high (CS line high)
    DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);

    // Transmit 0x80 to the device
    SPI_VoidSendByte(0x80);

    // Transmit 0x04 to the device
    SPI_VoidSendByte(0x04);

    // Set PB4 low (CS line low)
    DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);

    // Wait for 150 ms
    _delay_ms(150);
}

#define SSD_PORT DIO_PORTC // Define the port connected to the 7-segment display

void displayTemperature(char msb, char lsb) {
    char ssd[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, // 0-7
                    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71}; // 8-F
    char sign = 0;
    char display_value;

    lsb >>= 6;

    if (msb & 0x80) { // Check if the value is negative
        msb = (~msb) + 1;
        sign = 1;
        if (lsb != 0) lsb = 75 / lsb;
    } else {
        lsb *= 25;
    }

    // Display the sign (assuming '-' is represented by a specific pattern)
    if (sign) {
        // Implement sign display logic if needed
    }

    // Display the MSB and LSB on the 7-segment display
    display_value = ssd[msb % 16]; // Assuming `ssd` array holds the 7-segment encoding

    // Set the value to the 7-segment display (example for two digits display)
    DIO_VoidSetPortValue(SSD_PORT, display_value); // Set display value for MSB
    _delay_ms(5); // Short delay to allow display to update
    DIO_VoidSetPortValue(SSD_PORT, ssd[lsb % 16]); // Set display value for LSB
}

int main() {
    // Set all pins on port C as output
    DIO_VoidSetPortDirection(DIO_PORTC, DIO_PIN_OUTPUT);
    // Set all pins on port D as output
    DIO_VoidSetPortDirection(DIO_PORTD, DIO_PIN_OUTPUT);
    // Set all pins on port A as output
    DIO_VoidSetPortDirection(DIO_PORTA, DIO_PIN_OUTPUT);

    // Initialize SPI
    SPI_voidInit();

    // Initialize TC72 sensor
    tc72Init();
    _delay_ms(150);

    while (1) {
        // Set PB4 high
        DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);

        // Transmit 0x02 and 0x00 to the device
        SPI_VoidSendByte(0x02);
        SPI_VoidSendByte(0x00);

        // Set PB4 low
        DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);

        _delay_ms(1);

        // Receive MSB
        uint8_t msb = SPI_VoidRecByte();

        // Set PB4 high
        DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);

        // Transmit 0x01 and 0x00 to the device
        SPI_VoidSendByte(0x01);
        SPI_VoidSendByte(0x00);

        // Set PB4 low
        DIO_VoidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);

        _delay_ms(1);

        // Receive LSB
        uint8_t lsb = SPI_VoidRecByte();

        // Set PORTA to the value of LSB
        DIO_VoidSetPortValue(DIO_PORTA, lsb);

        // Display temperature
        displayTemperature(msb, lsb);
    }
}

