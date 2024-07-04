/*

 * main.c
 *
 *  Created on: Jul 4, 2024
 *      Author: Merna Atef
 */
#include <avr/io.h>

// Define pins switches
#define RIGHT_BUTTON PA0
#define LEFT_BUTTON PA1
#define FORWARD_BUTTON PA2
#define BACKWARD_BUTTON PA3
#define STOP_BUTTON PA4

// Define pins motors
#define MOTOR1_PIN1 PD0
#define MOTOR1_PIN2 PD1
#define MOTOR2_PIN1 PD2
#define MOTOR2_PIN2 PD3

void right() {
    PORTD &= ~(1 << MOTOR1_PIN1);
    PORTD |= (1 << MOTOR1_PIN2);
    PORTD |= (1 << MOTOR2_PIN1);
    PORTD &= ~(1 << MOTOR2_PIN2);
}

void left() {
    PORTD |= (1 << MOTOR1_PIN1);
    PORTD &= ~(1 << MOTOR1_PIN2);
    PORTD &= ~(1 << MOTOR2_PIN1);
    PORTD |= (1 << MOTOR2_PIN2);
}

void forward() {
    PORTD |= (1 << MOTOR1_PIN1);
    PORTD &= ~(1 << MOTOR1_PIN2);
    PORTD |= (1 << MOTOR2_PIN1);
    PORTD &= ~(1 << MOTOR2_PIN2);
}

void backward() {
    PORTD &= ~(1 << MOTOR1_PIN1);
    PORTD |= (1 << MOTOR1_PIN2);
    PORTD &= ~(1 << MOTOR2_PIN1);
    PORTD |= (1 << MOTOR2_PIN2);
}

void stop() {
    PORTD &= ~(1 << MOTOR1_PIN1);
    PORTD &= ~(1 << MOTOR1_PIN2);
    PORTD &= ~(1 << MOTOR2_PIN1);
    PORTD &= ~(1 << MOTOR2_PIN2);
}

int main(void) {
    // Configure Port A as input for switches
    DDRA = 0x00; // All pins in Port A as input
    // Enable pull-up resistors for switches
    PORTA = (1 << RIGHT_BUTTON) | (1 << LEFT_BUTTON) | (1 << FORWARD_BUTTON) | (1 << BACKWARD_BUTTON) | (1 << STOP_BUTTON);

    // Configure Port D as output for motors
    DDRD = (1 << MOTOR1_PIN1) | (1 << MOTOR1_PIN2) | (1 << MOTOR2_PIN1) | (1 << MOTOR2_PIN2);

    while (1) {
        // Check button states
        if ((PINA & (1 << RIGHT_BUTTON)) == 0) {
            right();
        } else if ((PINA & (1 << LEFT_BUTTON)) == 0) {
            left();
        } else if ((PINA & (1 << FORWARD_BUTTON)) == 0) {
            forward();
        } else if ((PINA & (1 << BACKWARD_BUTTON)) == 0) {
            backward();
        } else if ((PINA & (1 << STOP_BUTTON)) == 0) {
            stop();
        }
    }

    return 0;
}
