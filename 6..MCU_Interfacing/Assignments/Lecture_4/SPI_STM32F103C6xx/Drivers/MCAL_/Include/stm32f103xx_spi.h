/*
 * uart.h
 *
 *  Created on: Jul 1, 2025
 *      Author: Abdulrhman
 */

#ifndef MCAL__INCLUDE_STM32F103XX_SPI_H_
#define MCAL__INCLUDE_STM32F103XX_SPI_H_

#include "stm32f103x6_gpio.h"
#include "stddef.h"


struct S_IRQ_SRC
{
	uint8_t TXE       		:1;
	uint8_t RXNE			:1;
	uint8_t ERRI			:1;
	uint8_t RESERVED		:5;
};

//Configuration Structure
typedef struct 
{
	uint16_t Device_Mode;      						//@ref SPI_Device_Mode
	uint16_t Communication_Mode;      				//@ref SPI_Communication_Mode
	uint16_t Frame_Format;      					//@ref SPI_Frame_Format
	uint16_t DataSize;								//@ref SPI_DataSize
	uint16_t CLKPolarity;							//@ref SPI_CLKPolarity
	uint16_t CLKPhase;								//@ref SPI_CLKPhase
	uint16_t SPI_BaudRatePrescaler;					//@ref SPI_BaudRatePrescaler
	uint16_t NSS;									//@ref SPI_NSS
	uint16_t IRQ_Enable;							//@ref SPI_IRQ_Enable
	void(*P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);
}SPI_Config;


//==================================================================================================
//Reference Macros
//==================================================================================================

#define SPI_ENABLE 											(0x1U << 6)

//@ref SPI_Device_Mode
#define SPI_Device_Mode_SLAVE 								(0x00000000U)
#define SPI_Device_Mode_MASTER 								(0x1U << 2)

//@ref SPI_Communication_Mode
#define SPI_Directional_2Lines 								(0x00000000U)
#define SPI_Directional_2Lines_RxOnly 						(0x1U << 10)
#define SPI_Directional_1Lines_RxOnly 						(0x1U << 15)
#define SPI_Directional_1Lines_TxOnly 						((0x1U << 15) | (0x1U << 14))

//@ref SPI_Frame_Format
#define SPI_Frame_Format_MSB								(0x00000000U)
#define SPI_Frame_Format_LSB								(0x1U << 7)

//@ref SPI_DataSize
#define SPI_DataSize_8BIT									(0x00000000U)
#define SPI_DataSize_16BIT									(0x1U << 11)

//@ref SPI_CLKPolarity
#define SPI_CLKPolarity_LOW_When_idle						(0x00000000U)
#define SPI_CLKPolarity_HIGH_When_idle						(0x1U << 1)

//@ref SPI_CLKPhase
#define SPI_CLKPhase_1stEdge_capture						(0x00000000U)
#define SPI_CLKPhase_2ndEdge_capture						(0x1U << 0)

//@ref SPI_NSS
//Hardware
#define SPI_NSS_Hard_Slave 									(0x00000000U)
#define SPI_NSS_Hard_Master_IO_Enable 						(0x1U << 2)
#define SPI_NSS_Hard_Master_IO_Disable 					    (~(0x1U << 2))
//Software (Master/Slave)
#define SPI_NSS_Software_SSI_Reset 							(0x1U << 2)
#define SPI_NSS_Software_SSI_Set							((0x1U << 8) | (0x1U << 9))

//@ref SPI_BaudRatePrescaler
#define SPI_BaudRatePrescaler_2 							(0x00000000U)
#define SPI_BaudRatePrescaler_4								(0b001U << 3)
#define SPI_BaudRatePrescaler_8								(0b010U << 3)
#define SPI_BaudRatePrescaler_16							(0b011U << 3)
#define SPI_BaudRatePrescaler_32							(0b100U << 3)
#define SPI_BaudRatePrescaler_64							(0b101U << 3)
#define SPI_BaudRatePrescaler_128							(0b110U << 3)
#define SPI_BaudRatePrescaler_256							(0b111U << 3)

//@ref SPI_IRQ_Enable
#define SPI_IRQ_Enable_None		 							(0x00000000U)
#define SPI_IRQ_Enable_TXEIE		 						(0x1U << 7)
#define SPI_IRQ_Enable_RXNEIE		 						(0x1U << 6)
#define SPI_IRQ_Enable_ERRIE		 						(0x1U << 5)
//==================================================================================================
enum PollinMechanism
{
	Polling_Disable,
	Polling_Enable
};


//==================================================================================================
/*
*                      	  ============================================
* 								APIs Supported by "MCAL SPI DRIVER"
*                         ============================================
*/
//==================================================================================================

void MCAL_SPI_Init(SPIx_REG_typedef* SPIx, SPI_Config* SPI_Config);
void MCAL_SPI_DeInit(SPIx_REG_typedef* SPIx);

void MCAL_SPI_Transmit(SPIx_REG_typedef* SPIx, uint16_t* pTxBuffer, enum PollinMechanism PollingMech);

void MCAL_SPI_Recieve(SPIx_REG_typedef* SPIx, uint16_t* pRxBuffer, enum PollinMechanism PollingMech);

void MCAL_SPI_Tx_Rx(SPIx_REG_typedef* SPIx, uint16_t* pTxRxBuffer, enum PollinMechanism PollingMech);











#endif /* MCAL__INCLUDE_STM32F103XX_SPI_H_ */
