/*
 * SPI_interface.h
 *
 *  Created on: Aug 4, 2024
 *      Author: Merna Atef
 */
#ifndef SPI_INTERFACE_H_
#define SOI_INTERFACE_H_

void SPI_voidInit(void);
u8 SPI_u8TransRecieve(u8 copy_u8TransmittedByte,u8 * copy_pu8RecievedByte);
void SPI_VoidSendByte(u8 copy_u8DataByte);
u8 SPI_VoidRecByte(u8 *copy_pu8RecByte);



#endif
