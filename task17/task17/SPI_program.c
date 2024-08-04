/*
 * SPI_program.c
 *
 *  Created on: Aug 4, 2024
 *      Author: Merna Atef
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

#ifndef SPI_PROGRAM_C_
#define SPI_PROGRAM_C_


void SPI_voidInit(void){
     #if  (SPI_MODE==SPI_MASTER_MODE)
	    /*Data order=MSB First*/
       	CLR_BIT(SPCR,SPCR_DORD);
	   /*select master mode*/
	    SET_BIT(SPCR,SPCR_MSTR);
	  /*Choose CPOL and CPHA*/
	    SET_BIT(SPCR,SPCR_CPOL);
	    SET_BIT(SPCR,SPCR_CPHA);
	  /*Select CLK->FOSC/64*/
	    SET_BIT(SPCR,SPCR_SPR1);
	    CLR_BIT(SPCR,SPCR_SPR0);

     #elif (SPI_MODE==SPI_SLAVE_MODE)
	    /*Data order=MSB First*/
       	CLR_BIT(SPCR,SPCR_DORD);
	   /*select slave mode*/
	    CLR_BIT(SPCR,SPCR_MSTR);
	  /*Choose CPOL and CPHA*/
	    SET_BIT(SPCR,SPCR_CPOL);
	    SET_BIT(SPCR,SPCR_CPHA);
	  /*Select CLK->FOSC/64*/
	    SET_BIT(SPCR,SPCR_SPR1);
	    CLR_BIT(SPCR,SPCR_SPR0);

    #endif
	/*Enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}
u8 SPI_u8TransRecieve(u8 copy_u8TransmittedByte,u8 * copy_pu8RecievedByte){
	u8 Local_Error_State=NOK;
	if(copy_pu8RecievedByte != NULL){
		/*Send Byte*/
		SPDR=copy_u8TransmittedByte;
		/*Check if the Transmission is completed*/
		while((GET_BIT(SPSR,SPSR_SPIF))==0);
		/*Read Byte*/
		*copy_pu8RecievedByte =SPDR;

		Local_Error_State=OK;


	}
	return Local_Error_State;
}
void SPI_VoidSendByte(u8 copy_u8DataByte){
	SPDR=copy_u8DataByte;
}

u8 SPI_VoidRecByte(u8 *copy_pu8RecByte){
	u8 Local_Error_State=NOK;
		if(copy_pu8RecByte != NULL){
			/*Check if the Transmission is completed*/
			while((GET_BIT(SPSR,SPSR_SPIF))==0);
			/*Read Byte*/
			*copy_pu8RecByte =SPDR;

			Local_Error_State=OK;


		}
		return Local_Error_State;
}

#endif
