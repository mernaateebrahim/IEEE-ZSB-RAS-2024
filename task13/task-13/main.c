/*

 * main.c
 *
 *  Created on: Jul 18, 2024
 *      Author: Merna Atef
 */
#include <avr/io.h>
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LED_interface.h"
#include "ADC_interface.h"

#define NUM_LEDS 8

int main(void)
{
    LED_Type leds[NUM_LEDS] = {
        {LED_PORTB, LED_PIN0, ACTIVE_HIGH},
        {LED_PORTB, LED_PIN1, ACTIVE_HIGH},
        {LED_PORTB, LED_PIN2, ACTIVE_HIGH},
        {LED_PORTB, LED_PIN3, ACTIVE_HIGH},
        {LED_PORTB, LED_PIN4, ACTIVE_HIGH},
        {LED_PORTB, LED_PIN5, ACTIVE_HIGH},
        {LED_PORTB, LED_PIN6, ACTIVE_HIGH},
        {LED_PORTB, LED_PIN7, ACTIVE_HIGH}
    };

    // Initialize LEDs
    for (u8 i = 0; i < NUM_LEDS; i++) {
        LED_voidInit(leds[i]);
    }

    // Initialize ADC
    ADC_voidInit();

    u16 ADCValue = 0;

    while (1)
    {
        // Read ADC value
        u8 result = ADC_u8GetResultSync(ADC_CHANNEL0, &ADCValue);

        if (result == OK)
        {
            // Calculate number of LEDs to turn on
            u8 numLedsOn = (ADCValue * NUM_LEDS) / 1023;

            // Debugging: Print ADCValue and numLedsOn to check correctness
            // Use a serial monitor or other debugging method to check these values if possible
            // In this code, we'll use LEDs as debug indicators

            // Map ADC value to LEDs
            for (u8 i = 0; i < NUM_LEDS; i++) {
                if (i < numLedsOn) {
                    LED_voidOn(leds[i]);
                } else {
                    LED_voidOff(leds[i]);
                }
            }

            // Small delay to make changes visible
            _delay_ms(100);
        }
        else
        {
            // Toggle one LED to indicate error
            LED_voidToggle(leds[0]);
            _delay_ms(1000);
        }
    }
}
