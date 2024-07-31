/*
 * UART_interface.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Merna Atef
 */
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

void USART_voidInit      (void                    );

void USART_u8SendData    (u8 Copy_u8Data          );

u8   USART_u8RecevieData (u8 * Copy_u8ReceviedData);

#endif
