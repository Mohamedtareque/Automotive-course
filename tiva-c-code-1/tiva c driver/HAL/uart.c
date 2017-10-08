/*
 * uart.c
 *
 *  Created on: Aug 24, 2017
 *      Author: Mohamed
 */

#include"../HAL/hw_types.h"
#include"../HAL/types.h"
#include"uart.h"
void UART_parityEnable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTLCRH));
	regVal |= UART_LCRH_PEN ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_stickParityEnable(uint32_t uartBase )
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTLCRH));
	regVal |= UART_LCRH_SPS ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_stickParityDisable(uint32_t uartBase )
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTLCRH));
	regVal &= ~(UART_LCRH_SPS) ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_parityModeSet(uint32_t uartBase, parity_t parity)
{
	UART_parityEnable(uartBase);
	uint32_t regVal = HW_RD_REG32((uartBase+UARTLCRH));
	switch(parity)
	{
	case ODD :
		regVal &=~( UART_LCRH_EPS) ;
		break ;
	case EVEN :
		regVal |= ( UART_LCRH_EPS) ;
		break;
	}
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}

void UART_parityDisable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTLCRH));
	regVal &=~(UART_LCRH_PEN) ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UARTEnable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTCTL));
	regVal |= UART_CTL_UARTEN ;
	HW_WR_REG32((uartBase+UARTCTL),regVal);
}
void UARTDisable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTCTL));
	regVal &= ~(UART_CTL_UARTEN) ;
	HW_WR_REG32((uartBase+UARTCTL),regVal);
}

void UART_FIFO_RX_LevelSet( uint32_t uartBase,
							fifoLevel_t rxLevel)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTIFLS));
	switch(rxLevel)
	{
	case FIFO_1_8 :
		regVal |= UART_IFLS_RX1_8 ;
		break ;
	case FIFO_1_4 :
		regVal |= UART_IFLS_RX1_4 ;
		break ;
	case FIFO_1_2 :
		regVal |= UART_IFLS_RX1_2 ;
		break ;
	case FIFO_3_4 :
		regVal |= UART_IFLS_RX3_4 ;
		break ;
	case FIFO_7_8 :
		regVal |= UART_IFLS_RX7_8 ;
		break ;
	}
	HW_WR_REG32((uartBase+UARTIFLS),regVal);
}
void UART_FIFO_TX_LevelSet( uint32_t uartBase,
							fifoLevel_t rxLevel)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTIFLS));
	switch(rxLevel)
	{
	case FIFO_1_8 :
		regVal |= UART_IFLS_TX1_8 ;
		break ;
	case FIFO_1_4 :
		regVal |= UART_IFLS_TX1_4 ;
		break ;
	case FIFO_1_2 :
		regVal |= UART_IFLS_TX1_2 ;
		break ;
	case FIFO_3_4 :
		regVal |= UART_IFLS_TX3_4 ;
		break ;
	case FIFO_7_8 :
		regVal |= UART_IFLS_TX7_8 ;
		break ;
	}
	HW_WR_REG32((uartBase+UARTIFLS),regVal);
}
void UART_FIFO_Disable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTLCRH));
	regVal &= ~(UART_LCRH_FEN) ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_FIFO_Enable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTLCRH));
	regVal |= UART_LCRH_FEN ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_setBaudRate(uint32_t uartBase ,
					  uint32_t frequency ,
					  uint32_t baudRate	  )
{
	double totalNum = ((double)frequency /(16*baudRate));
	uint32_t intNum = totalNum ;

	uint32_t fNum = ((totalNum - intNum)*64);
	HW_WR_REG32((uartBase+UARTIBRD),intNum);
	HW_WR_REG32((uartBase+UARTFBRD),fNum);
}
void UART_SIR_Enable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTCTL));
	regVal |= UART_CTL_SIREN ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_SIR_Disable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTCTL));
	regVal &= ~(UART_CTL_SIREN) ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_SIR_Mode_Enable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTCTL));
	regVal |= (UART_CTL_SIRLP) ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_SIR_Mode_Disable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32((uartBase+UARTCTL));
	regVal &= ~(UART_CTL_SIRLP) ;
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}

boolean_t UART_charAvailable(uint32_t uartBase)
{
	return((HW_RD_REG32(uartBase + UARTFR) & UART_FR_RXFE) ? false : true);
}
boolean_t UART_spaceAvailable(uint32_t uartBase)
{
	return((HW_RD_REG32(uartBase + UARTFR) & UART_FR_TXFF) ? false : true);
}

uint32_t UART_readChar(uint32_t uartBase)
{
	while((HW_RD_REG32(uartBase + UARTFR) & UART_FR_RXFE) != 0);
	return (HW_RD_REG32(uartBase + UARTDR) );
}
void UART_breakControl(uint32_t uartBase , boolean_t state)
{
	uint32_t regVal = HW_RD_REG32(uartBase+UARTLCRH);
	if(state == HIGH)
	{
		regVal |= UART_LCRH_BRK ;
	}
	else
	{
		regVal &= ~( UART_LCRH_BRK) ;
	}
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_sendChar(uint32_t uartBase,uint8_t data)
{
	while((HW_RD_REG32(uartBase + UARTFR) & UART_FR_TXFF));
	 HW_WR_REG32((uartBase + UARTDR),data) ;
}
void UART_printString(uint32_t uartBase,uint8_t *data)
{
	while((HW_RD_REG32(uartBase + UARTFR) & UART_FR_TXFF) != 0);
	HW_WR_REG32((uartBase + UARTDR), *data) ;
	data++ ;
}
boolean_t UART_busy(uint32_t uartBase)
{
	return((HW_RD_REG32(uartBase+UARTFR)&UART_FR_BUSY)? true : false);
}
/*Interrupt section*/
/*DMA Section*/
uint32_t UART_rxGetError(uint32_t uartBase)
{
	return(HW_RD_REG32(uartBase+UARTRSR)& 0x0000000F) ;
}
void UART_rxClearError(uint32_t uartBase)
{
	HW_WR_REG32((uartBase+UARTRSR), 0x0000000F) ;
}

void UART_wordLength(uint32_t uartBase , wordLength_t wordLength)
{
	uint32_t regVal = HW_RD_REG32(uartBase+UARTLCRH) ;
	switch(wordLength)
	{
	case five_bits:
		regVal |= UART_LCRH_WLEN_5 ;
		break;
	case six_bits:
		regVal |= UART_LCRH_WLEN_6 ;
		break;
	case seven_bits:
		regVal |= UART_LCRH_WLEN_7 ;
		break;
	case eight_bits:
		regVal |= UART_LCRH_WLEN_8 ;
		break;
	}
	HW_WR_REG32((uartBase+UARTLCRH),regVal);
}
void UART_smartCard_Enable(uint32_t uartBase)
{
	UART_wordLength( uartBase , eight_bits ) ;
	UART_parityEnable(uartBase) ;
	UART_parityModeSet( uartBase,  EVEN);
	UART_stickParityDisable( uartBase  ) ;
	uint32_t regVal = HW_RD_REG32(uartBase+UARTCTL) ;
	regVal |= UART_CTL_SMART ;
	HW_WR_REG32((uartBase+UARTCTL),regVal);
}
void UART_clockSourceSet(uint32_t uartBase, clockSource_t source)
{
	uint32_t regVal = HW_RD_REG32(uartBase+UARTCC) ;
	switch(source)
	{
	case system_clock :
		regVal |= UART_CC_CS_SYSCLK ;
		break ;
	case piosc :
		regVal |= UART_CC_CS_PIOSC ;
		break ;

	}
	HW_WR_REG32((uartBase+UARTCC),regVal);
}
void UART_txEnable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32(uartBase+UARTCTL) ;
	regVal |= UART_CTL_TXEN ;
	HW_WR_REG32((uartBase+UARTCTL),regVal);
}
void UART_rxEnable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32(uartBase+UARTCTL) ;
	regVal |= UART_CTL_RXEN ;
	HW_WR_REG32((uartBase+UARTCTL),regVal);
}
void UART_loopBackEnable(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32(uartBase+UARTCTL) ;
	regVal |= UART_CTL_LBE ;
	HW_WR_REG32((uartBase+UARTCTL),regVal);
}

void UART_clockConfiguration(uint32_t uartBase)
{
	uint32_t regVal = HW_RD_REG32(uartBase+UARTCC) ;
		regVal |= UART_CC_CS_SYSCLK ;
		HW_WR_REG32((uartBase+UARTCC),regVal);
}
void UART_inIt(uint32_t uartBase, uint32_t baudRate )
{

	UARTDisable( uartBase);
	UART_parityDisable(uartBase);
	UART_stickParityDisable (uartBase) ;
	//UART_rxEnable( uartBase);
	//UART_txEnable( uartBase);
	UART_setBaudRate( uartBase ,16000000 , baudRate	);
	UART_wordLength( uartBase , eight_bits );
	UART_clockConfiguration( uartBase );

}

void UARTRead(){


}
void UARTWrite(uint8_t data)
{

}
