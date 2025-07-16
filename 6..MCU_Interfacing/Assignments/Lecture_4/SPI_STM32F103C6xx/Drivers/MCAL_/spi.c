#include "stm32f103xx_spi.h"
/*
*==================================================================================================
*										Generic Variables
*==================================================================================================
*/
SPI_Config* Glopal_SPI_Config[2] = {NULL,NULL};
/*
*==================================================================================================
*										Generic Macros
*==================================================================================================
*/
#define SPI1_Index					0U
#define SPI2_Index					1U

#define SPI_SR_TXE					((uint8_t)0x02)
#define SPI_SR_RXNE					((uint8_t)0x01)
#define SPI_SR_ERRI					((uint8_t)0x10)

/*
*==================================================================================================
*										Generic Function
*==================================================================================================
*/


void SPI_GPIO_SetPINs(SPIx_REG_typedef* SPIx)
{
	PIN_CFG_TypeDef GPIO_PIN_CFG;
	if(SPIx == SPI1)
	{
		// PA4 : SPI_NSS
		// PA5 : SPI_SCK
		// PA6 : SPI_MISO
		// PA7 : SPI_MOSI
		if(Glopal_SPI_Config[SPI1_Index]->Device_Mode == SPI_Device_Mode_MASTER)
		{
			// PA4 : SPI_NSS
			switch(Glopal_SPI_Config[SPI1_Index]->NSS)
			{
				case SPI_NSS_Hard_Master_IO_Disable:
					GPIO_PIN_CFG.PIN_NUMBER     = GPIO_PIN_4;
					GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
					GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
					GPIO_PIN_CFG.MODE_CASE      = Input_mode;
					MCAL_GPIO_INIT(GPIOA, &GPIO_PIN_CFG);
					break;
				case SPI_NSS_Hard_Master_IO_Enable:
					GPIO_PIN_CFG.PIN_NUMBER      = GPIO_PIN_4;
					GPIO_PIN_CFG.__PinMode       = OUTPUT_MODE;
					GPIO_PIN_CFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
					GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
					MCAL_GPIO_INIT(GPIOA, &GPIO_PIN_CFG);
					break;
			}
			
			// PA5 : SPI_SCK
			GPIO_PIN_CFG.PIN_NUMBER      = GPIO_PIN_5;
			GPIO_PIN_CFG.__PinMode       = OUTPUT_MODE;
			GPIO_PIN_CFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
			GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
			MCAL_GPIO_INIT(GPIOA, &GPIO_PIN_CFG);
			
			// PA6 : SPI_MISO
			GPIO_PIN_CFG.PIN_NUMBER     = GPIO_PIN_6;
			GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
			GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
			GPIO_PIN_CFG.MODE_CASE      = Input_mode;
			MCAL_GPIO_INIT(GPIOA, &GPIO_PIN_CFG);

			// PA7 : SPI_MOSI
			GPIO_PIN_CFG.PIN_NUMBER      = GPIO_PIN_7;
			GPIO_PIN_CFG.__PinMode       = OUTPUT_MODE;
			GPIO_PIN_CFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
			GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
			MCAL_GPIO_INIT(GPIOA, &GPIO_PIN_CFG);									
		}
		else // ----> SLAVE_Mode
		{
			// PA4 : SPI_NSS
			if(Glopal_SPI_Config[SPI1_Index]->NSS == SPI_NSS_Hard_Slave)
			{
				GPIO_PIN_CFG.PIN_NUMBER     = GPIO_PIN_4;
				GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
				GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
				GPIO_PIN_CFG.MODE_CASE      = Input_mode;
				MCAL_GPIO_INIT(GPIOA, &GPIO_PIN_CFG);				
			}

			// PA5 : SPI_SCK
			GPIO_PIN_CFG.PIN_NUMBER     = GPIO_PIN_5;
			GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
			GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
			GPIO_PIN_CFG.MODE_CASE      = Input_mode;
			MCAL_GPIO_INIT(GPIOA, &GPIO_PIN_CFG);
			
			// PA6 : SPI_MISO
			GPIO_PIN_CFG.PIN_NUMBER      = GPIO_PIN_6;
			GPIO_PIN_CFG.__PinMode       = OUTPUT_MODE;
			GPIO_PIN_CFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
			GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
			MCAL_GPIO_INIT(GPIOA, &GPIO_PIN_CFG);

			// PA7 : SPI_MOSI
			GPIO_PIN_CFG.PIN_NUMBER      = GPIO_PIN_7;
			GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
			GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
			GPIO_PIN_CFG.MODE_CASE      = Input_mode;
			MCAL_GPIO_INIT(GPIOA, &GPIO_PIN_CFG);			
		}
	}
	else if(SPIx == SPI2)
	{
		// PB12 : SPI_NSS
		// PB13 : SPI_SCK
		// PB14 : SPI_MISO
		// PB15 : SPI_MOSI
		if(Glopal_SPI_Config[SPI2_Index]->Device_Mode == SPI_Device_Mode_MASTER)
		{
			// PB12 : SPI_NSS
			switch(Glopal_SPI_Config[SPI2_Index]->NSS)
			{
				case SPI_NSS_Hard_Master_IO_Disable:
					GPIO_PIN_CFG.PIN_NUMBER     = GPIO_PIN_12;
					GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
					GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
					GPIO_PIN_CFG.MODE_CASE      = Input_mode;
					MCAL_GPIO_INIT(GPIOB, &GPIO_PIN_CFG);
					break;
				case SPI_NSS_Hard_Master_IO_Enable:
					GPIO_PIN_CFG.PIN_NUMBER      = GPIO_PIN_12;
					GPIO_PIN_CFG.__PinMode       = OUTPUT_MODE;
					GPIO_PIN_CFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
					GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
					MCAL_GPIO_INIT(GPIOB, &GPIO_PIN_CFG);
					break;
			}
			
			// PB13 : SPI_SCK
			GPIO_PIN_CFG.PIN_NUMBER      = GPIO_PIN_13;
			GPIO_PIN_CFG.__PinMode       = OUTPUT_MODE;
			GPIO_PIN_CFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
			GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
			MCAL_GPIO_INIT(GPIOB, &GPIO_PIN_CFG);
			
			// PB14 : SPI_MISO
			GPIO_PIN_CFG.PIN_NUMBER     = GPIO_PIN_14;
			GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
			GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
			GPIO_PIN_CFG.MODE_CASE      = Input_mode;
			MCAL_GPIO_INIT(GPIOB, &GPIO_PIN_CFG);

			// PB15 : SPI_MOSI
			GPIO_PIN_CFG.PIN_NUMBER      = GPIO_PIN_15;
			GPIO_PIN_CFG.__PinMode       = OUTPUT_MODE;
			GPIO_PIN_CFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
			GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
			MCAL_GPIO_INIT(GPIOB, &GPIO_PIN_CFG);									
		}
		else // ----> SLAVE_Mode
		{
			// PB12 : SPI_NSS
			if(Glopal_SPI_Config[SPI2_Index]->NSS == SPI_NSS_Hard_Slave)
			{
				GPIO_PIN_CFG.PIN_NUMBER     = GPIO_PIN_12;
				GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
				GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
				GPIO_PIN_CFG.MODE_CASE      = Input_mode;
				MCAL_GPIO_INIT(GPIOB, &GPIO_PIN_CFG);				
			}

			// PB13 : SPI_SCK
			GPIO_PIN_CFG.PIN_NUMBER     = GPIO_PIN_13;
			GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
			GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
			GPIO_PIN_CFG.MODE_CASE      = Input_mode;
			MCAL_GPIO_INIT(GPIOB, &GPIO_PIN_CFG);
			
			// PB14 : SPI_MISO
			GPIO_PIN_CFG.PIN_NUMBER      = GPIO_PIN_14;
			GPIO_PIN_CFG.__PinMode       = OUTPUT_MODE;
			GPIO_PIN_CFG.CNF_OUTPUT_CASE = AFOutput_Push_pull;
			GPIO_PIN_CFG.MODE_CASE       = Output_mode_max_speed_10MHz;
			MCAL_GPIO_INIT(GPIOB, &GPIO_PIN_CFG);

			// PB15 : SPI_MOSI
			GPIO_PIN_CFG.PIN_NUMBER     = GPIO_PIN_15;
			GPIO_PIN_CFG.__PinMode      = INPUT_MODE;
			GPIO_PIN_CFG.CNF_INPUT_CASE = Floating_input;
			GPIO_PIN_CFG.MODE_CASE      = Input_mode;
			MCAL_GPIO_INIT(GPIOB, &GPIO_PIN_CFG);			
		}		
		
	}	
}

/*
*==================================================================================================
*												APIs
*==================================================================================================
*/
void MCAL_SPI_Init(SPIx_REG_typedef* SPIx, SPI_Config* SPI_Config)
{
	//Saft for registers
	uint16_t TempReg_CR1 = 0;
	uint16_t TempReg_CR2 = 0;

	if(SPIx == SPI1)
	{
		Glopal_SPI_Config[SPI1_Index] = SPI_Config;
		SPI1_CLOCK_ENABLE();
	}
	else if(SPIx == SPI2)
	{
		Glopal_SPI_Config[SPI2_Index] = SPI_Config;
		SPI2_CLOCK_ENABLE();
	}

	//Enable SPI CR1:BIT 6 SPE: SPI enable.
	TempReg_CR1 = SPI_ENABLE;

	//Master Or Slave
	TempReg_CR1 |= SPI_Config->Device_Mode;

	//SPI_Communication_Mode
	TempReg_CR1 |= SPI_Config->Communication_Mode;

	//SPI_Frame_Format
	TempReg_CR1 |= SPI_Config->Frame_Format;

	//SPI_DataSize
	TempReg_CR1 |= SPI_Config->DataSize;

	//SPI_CLKPolarity
	TempReg_CR1 |= SPI_Config->CLKPolarity;

	//SPI_CLKPhase
	TempReg_CR1 |= SPI_Config->CLKPhase;

	//SPI_NSS
	if(SPI_Config->NSS == SPI_NSS_Hard_Master_IO_Enable)
		TempReg_CR2 |= SPI_Config->NSS;
	else if(SPI_Config->NSS == SPI_NSS_Hard_Master_IO_Disable)
		TempReg_CR2 &= SPI_Config->NSS;
	else
		TempReg_CR1 |= SPI_Config->NSS;

	//SPI_BaudRatePrescaler
	TempReg_CR1 |= SPI_Config->SPI_BaudRatePrescaler;


	//SPI_IRQ_Enable
	if(SPI_Config->IRQ_Enable != SPI_IRQ_Enable_None)
	{
		TempReg_CR2 |= SPI_Config->IRQ_Enable;
		if(SPIx == SPI1)
		{
			NVIC_SPI1_IRQ_ENABLE();
		}
		else if(SPIx == SPI2)
		{
			NVIC_SPI2_IRQ_ENABLE();
		}
	}
	else{}
	SPIx->CR1 = TempReg_CR1;
	SPIx->CR2 = TempReg_CR2;
	SPI_GPIO_SetPINs(SPIx);
}

void MCAL_SPI_DeInit(SPIx_REG_typedef* SPIx)
{
	if(SPIx == SPI1)
	{
		SPI1_CLOCK_DISABLE();
		NVIC_SPI1_IRQ_DISABLE();
	}
	else if(SPIx == SPI2)
	{
		SPI2_CLOCK_DISABLE();
		NVIC_SPI2_IRQ_DISABLE();
	}
}

void MCAL_SPI_Transmit(SPIx_REG_typedef* SPIx, uint16_t* pTxBuffer, enum PollinMechanism PollingMech)
{
	if(PollingMech == Polling_Enable)
		while(!(SPIx->SR & SPI_SR_TXE));
	SPIx->DR = *pTxBuffer;
}

void MCAL_SPI_Recieve(SPIx_REG_typedef* SPIx, uint16_t* pRxBuffer, enum PollinMechanism PollingMech)
{
	if(PollingMech == Polling_Enable)
		while(!(SPIx->SR & SPI_SR_RXNE));
	*pRxBuffer = SPIx->DR;
}

void MCAL_SPI_Tx_Rx(SPIx_REG_typedef* SPIx, uint16_t* pTxRxBuffer, enum PollinMechanism PollingMech)
{
	if(PollingMech == Polling_Enable)
		while(!(SPIx->SR & SPI_SR_TXE));
	SPIx->DR = *pTxRxBuffer;
	if(PollingMech == Polling_Enable)
		while(!(SPIx->SR & SPI_SR_RXNE));
	*pTxRxBuffer = SPIx->DR;
}

/*
*==================================================================================================
*												IRQ
*==================================================================================================
*/
void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;
	irq_src.TXE  = (((SPI1->SR & SPI_SR_TXE) >> 1));
	irq_src.RXNE = (((SPI1->SR & SPI_SR_RXNE) >> 0));
	irq_src.ERRI = (((SPI1->SR & SPI_SR_ERRI) >> 4));
	Glopal_SPI_Config[SPI1_Index]->P_IRQ_CallBack(irq_src);
}

void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;
	irq_src.TXE  = (((SPI2->SR & SPI_SR_TXE) >> 1));
	irq_src.RXNE = (((SPI2->SR & SPI_SR_RXNE) >> 0));
	irq_src.ERRI = (((SPI2->SR & SPI_SR_ERRI) >> 4));	
	Glopal_SPI_Config[SPI2_Index]->P_IRQ_CallBack(irq_src);
}

//==================================================================================================
