/*
 * UART_program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Merna Atef
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void USART_voidInit      (void                    )
{
	u8 Local_u8UCSRCValue =0b10000000;
	u8 Local_u16BaudRate;
	//normal speed
	CLR_BIT(UCSA,UCSA_U2X);
	//disable MPCM
	CLR_BIT(UCSA,UCSA_MPCM);
	//enable RX,TX
	SET_BIT(UCSB,UCSRB_RXEN);
	SET_BIT(UCSB,UCSRB_TXEN);
	//Select 8 bit data
	CLR_BIT(UCSB,UCSRB_UCSZ2);
	//Select Asynch Mode
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
	//No Parity Bit
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
	//Enable 2 Stop Bits
	SET_BIT(UCSB,UCSRC_USBS);

	UCSC=Local_u8UCSRCValue;
	//baud rate =9600
	UBRRL=(u8)Local_u16BaudRate;
	UBRRH=(u8)(Local_u16BaudRate>>8);



}

void USART_u8SendData    (u8 Copy_u8Data          ){
	while(GET_BIT(UCSA,UCSA_UDRE)==0);
	UCSA_UDRE=Copy_u8Data;

}

u8   USART_u8RecevieData (u8 * Copy_u8ReceviedData){
	u8 Local_u8ErrorState = NOK;
	if(Copy_u8ReceviedData !=NULL){
		while(GET_BIT(UCSA,UCSA_RXC)==0);
		* Copy_u8ReceviedData =UDR;
		Local_u8ErrorState = OK;
	}
	return Local_u8ErrorState;

}
