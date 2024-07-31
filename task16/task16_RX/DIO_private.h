/*

 * DIO_private.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Merna Atef
 */
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_
/**********************************GroupA********************************/
#define PORTA *((volatile u8*)0x3B)
#define DDRA  *((volatile u8*)0x3A)
#define PINA  *((volatile u8*)0x39)

/**********************************GroupB********************************/
#define PORTB *((volatile u8*)0x3B)
#define DDRB  *((volatile u8*)0x3A)
#define PINB  *((volatile u8*)0x39)

/**********************************GroupC********************************/
#define PORTC *((volatile u8*)0x3B)
#define DDRC  *((volatile u8*)0x3A)
#define PINC  *((volatile u8*)0x39)

/**********************************GroupD********************************/
#define PORTD *((volatile u8*)0x3B)
#define DDRD  *((volatile u8*)0x3A)
#define PIND  *((volatile u8*)0x39)


#endif

