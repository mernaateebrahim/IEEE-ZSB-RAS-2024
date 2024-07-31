/*
 * UART_private.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Merna Atef
 */
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_
#define UDR   *((volatile u8*)0x2C)

#define UCSA  *((volatile u8*)0x2B)
#define UCSA_RXC  7
#define UCSA_TXC  6
#define UCSA_UDRE 5
#define UCSA_FE   4
#define UCSA_DOR  3
#define UCSA_PE   2
#define UCSA_U2X  1
#define UCSA_MPCM 0

#define UCSB  *((volatile u8*)0x2A)

#define UCSRB_RXCIE		7
#define UCSRB_TXCIE		6
#define UCSRB_UDRIE		5
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3
#define UCSRB_UCSZ2		2
#define UCSRB_RXB8		1
#define UCSRB_TXB8		0

#define UCSC  *((volatile u8*)0x40)

#define UCSRC_URSEL 	7
#define UCSRC_UMSEL		6
#define UCSRC_UPM1		5
#define UCSRC_UPM0		4
#define UCSRC_USBS		3
#define UCSRC_UCSZ1		2
#define UCSRC_UCSZ0		1
#define UCSRC_UCPOL		0

#define UBRRH *((volatile u8*)0X40)

#define UBRRL *((volatile u8*)0x29)
#endif


