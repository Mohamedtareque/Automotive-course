/*
 * uart.h
 *
 *  Created on: Aug 24, 2017
 *      Author: Mohamed
 */

#ifndef HAL_UART_H_
#define HAL_UART_H_
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include"types.h"
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */


//*****************************************************************************
// The following are defines for the UART Bases
//*****************************************************************************
#define			 UART0	                	0x4000C000   // UART0 BASE
#define			 UART1	                	0x4000D000   // UART1 BASE
#define			 UART2	                	0x4000E000   // UART2 BASE
#define			 UART3	                	0x4000F000   // UART3 BASE
#define			 UART4	                	0x40010000   // UART4 BASE
#define			 UART5	                	0x40011000   // UART5 BASE
#define			 UART6	                	0x40012000   // UART6 BASE
#define			 UART7	                	0x40013000   // UART7 BASE


//*****************************************************************************
// The following are defines for the UART register offsets.
//*****************************************************************************
#define			 UARTDR	                	0x00000000  // UART Data
#define 		 UARTRSR                	0x00000004  // UART Receive Status/Error Clear
#define 		 UARTECR	                0x00000004  // UART Receive Status/Error Clear
#define 		 UARTFR		               	0x00000018  // UART Flag
#define 		 UARTILPR	             	0x00000020  // UART IrDA Low-Power Register
#define 		 UARTIBRD	             	0x00000024  // UART Integer Baud-Rate Divisor
#define 		 UARTFBRD	             	0x00000028  // UART Fractional Baud-Rate
														// Divisor
#define 		 UARTLCRH            	  	0x0000002C  // UART Line Control
#define 		 UARTCTL	              	0x00000030  // UART Control
#define 		 UARTIFLS			        0x00000034  // UART Interrupt FIFO Level Select
#define 		 UARTIM			            0x00000038  // UART Interrupt Mask
#define			 UARTRIS	          	    0x0000003C  // UART Raw Interrupt Status
#define			 UARTMIS	          	    0x00000040  // UART Masked Interrupt Status
#define			 UARTICR	          	    0x00000044  // UART Interrupt Clear
#define			 UARTDMACTL		       	    0x00000048  // UART DMA Control
#define			 UART9BITADDR	     	    0x000000A4  // UART 9-Bit Self Address
#define			 UART9BITAMASK	     	    0x000000A8  // UART 9-Bit Self Address Mask
#define			 UARTPP	            	    0x00000FC0  // UART Peripheral Properties
#define 		 UARTCC	            	    0x00000FC8  // UART Clock Configuration

//*****************************************************************************
// The following are defines for the bit fields in the UARTDR register.
//*****************************************************************************
#define 		UART_DR_OE              	0x00000800  // UART Overrun Error
#define 		UART_DR_BE              	0x00000400  // UART Break Error
#define 		UART_DR_PE              	0x00000200  // UART Parity Error
#define 		UART_DR_FE              	0x00000100  // UART Framing Error
#define 		UART_DR_DATA_M          	0x000000FF  // Data Transmitted or Received
#define 		UART_DR_DATA_S         	 	0

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTRSR register.
//
//*****************************************************************************
#define 		UART_RSR_OE             	0x00000008  // UART Overrun Error
#define 		UART_RSR_BE             	0x00000004  // UART Break Error
#define 		UART_RSR_PE             	0x00000002  // UART Parity Error
#define 		UART_RSR_FE            		0x00000001  // UART Framing Error

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTECR register.
//
//*****************************************************************************
#define 		UART_ECR_DATA_M         	0x000000FF  // Error Clear
#define 		UART_ECR_DATA_S         	0

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTFR register.
//
//*****************************************************************************
#define 		UART_FR_RI              	0x00000100  // Ring Indicator
#define 		UART_FR_TXFE            	0x00000080  // UART Transmit FIFO Empty
#define 		UART_FR_RXFF            	0x00000040  // UART Receive FIFO Full
#define 		UART_FR_TXFF            	0x00000020  // UART Transmit FIFO Full
#define 		UART_FR_RXFE            	0x00000010  // UART Receive FIFO Empty
#define 		UART_FR_BUSY            	0x00000008  // UART Busy
#define 		UART_FR_DCD             	0x00000004  // Data Carrier Detect
#define 		UART_FR_DSR             	0x00000002  // Data Set Ready
#define 		UART_FR_CTS             	0x00000001  // Clear To Send

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTILPR register.
//
//*****************************************************************************
#define 		UART_ILPR_ILPDVSR_M     	0x000000FF  // IrDA Low-Power Divisor
#define 		UART_ILPR_ILPDVSR_S     	0

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTIBRD register.
//
//*****************************************************************************
#define 		UART_IBRD_DIVINT_M      	0x0000FFFF  // Integer Baud-Rate Divisor
#define 		UART_IBRD_DIVINT_S      	0

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTFBRD register.
//
//*****************************************************************************
#define 		UART_FBRD_DIVFRAC_M     	0x0000003F  // Fractional Baud-Rate Divisor
#define 		UART_FBRD_DIVFRAC_S     	0

//*****************************************************************************
// The following are defines for the bit fields in the UARTLCRH register.
//*****************************************************************************
#define 		UART_LCRH_SPS           	0x00000080  // UART Stick Parity Select
#define 		UART_LCRH_WLEN_M        	0x00000060  // UART Word Length
#define 		UART_LCRH_WLEN_5        	0x00000000  // 5 bits (default)
#define 		UART_LCRH_WLEN_6        	0x00000020  // 6 bits
#define 		UART_LCRH_WLEN_7        	0x00000040  // 7 bits
#define 		UART_LCRH_WLEN_8        	0x00000060  // 8 bits
#define 		UART_LCRH_FEN           	0x00000010  // UART Enable FIFOs
#define 		UART_LCRH_STP2          	0x00000008  // UART Two Stop Bits Select
#define 		UART_LCRH_EPS           	0x00000004  // UART Even Parity Select
#define 		UART_LCRH_PEN           	0x00000002  // UART Parity Enable
#define 		UART_LCRH_BRK           	0x00000001  // UART Send Break

//*****************************************************************************
// The following are defines for the bit fields in the UARTCTL register.
//*****************************************************************************
#define 		UART_CTL_CTSEN          	0x00008000  // Enable Clear To Send
#define 		UART_CTL_RTSEN          	0x00004000  // Enable Request to Send
#define 		UART_CTL_RTS            	0x00000800  // Request to Send
//#define 		UART_CTL_DTR            	0x00000400  // Data Terminal Ready
#define 		UART_CTL_RXEN            	0x00000200  // UART Receive Enable
#define 		UART_CTL_TXEN            	0x00000100  // UART Transmit Enable
#define 		UART_CTL_LBE            	0x00000080  // UART Loop Back Enable
#define 		UART_CTL_HSE            	0x00000020  // High-Speed Enable
#define 		UART_CTL_EOT            	0x00000010  // End of Transmission
#define 		UART_CTL_SMART          	0x00000008  // ISO 7816 Smart Card Support
#define 		UART_CTL_SIRLP         		0x00000004  // UART SIR Low-Power Mode
#define 		UART_CTL_SIREN          	0x00000002  // UART SIR Enable
#define 		UART_CTL_UARTEN         	0x00000001  // UART Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTIFLS register.
//
//*****************************************************************************
#define 		UART_IFLS_RX_M          	0x00000038  // UART Receive Interrupt FIFO
                                            			// Level Select
#define 		UART_IFLS_RX1_8         	0x00000000  // RX FIFO >= 1/8 full
#define 		UART_IFLS_RX1_4         	0x00000008  // RX FIFO >= 1/4 full
#define 		UART_IFLS_RX1_2         	0x00000010  // RX FIFO >= 1/2 full (default)
#define 		UART_IFLS_RX3_4         	0x00000018  // RX FIFO >= 3/4 full
#define 		UART_IFLS_RX7_8         	0x00000020  // RX FIFO >= 7/8 full
#define 		UART_IFLS_TX_M          	0x00000007  // UART Transmit Interrupt FIFO
														// Level Select
#define 		UART_IFLS_TX1_8         	0x00000000  // TX FIFO <= 1/8 full
#define 		UART_IFLS_TX1_4         	0x00000001  // TX FIFO <= 1/4 full
#define 		UART_IFLS_TX1_2         	0x00000002  // TX FIFO <= 1/2 full (default)
#define 		UART_IFLS_TX3_4         	0x00000003  // TX FIFO <= 3/4 full
#define 		UART_IFLS_TX7_8         	0x00000004  // TX FIFO <= 7/8 full

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTIM register.
//
//*****************************************************************************
#define 		UART_IM_DMATXIM         0x00020000  // Transmit DMA Interrupt Mask
#define 		UART_IM_DMARXIM         0x00010000  // Receive DMA Interrupt Mask
#define 		UART_IM_9BITIM          0x00001000  // 9-Bit Mode Interrupt Mask
#define 		UART_IM_EOTIM           0x00000800  // End of Transmission Interrupt
                                            		// Mask
#define 		UART_IM_OEIM            0x00000400  // UART Overrun Error Interrupt
                                            		// Mask
#define 		UART_IM_BEIM            0x00000200  // UART Break Error Interrupt Mask
#define 		UART_IM_PEIM            0x00000100  // UART Parity Error Interrupt Mask
#define 		UART_IM_FEIM            0x00000080  // UART Framing Error Interrupt
                                            		// Mask
#define 		UART_IM_RTIM            0x00000040  // UART Receive Time-Out Interrupt
                                            		// Mask
#define 		UART_IM_TXIM            0x00000020  // UART Transmit Interrupt Mask
#define 		UART_IM_RXIM            0x00000010  // UART Receive Interrupt Mask
#define 		UART_IM_DSRMIM          0x00000008  // UART Data Set Ready Modem
                                            		// Interrupt Mask
#define 		UART_IM_DCDMIM          0x00000004  // UART Data Carrier Detect Modem
                                            		// Interrupt Mask
#define 		UART_IM_CTSMIM          0x00000002  // UART Clear to Send Modem
                                            		// Interrupt Mask
#define 		UART_IM_RIMIM           0x00000001  // UART Ring Indicator Modem
                                            		// Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTRIS register.
//
//*****************************************************************************
#define 		UART_RIS_DMATXRIS       0x00020000  // Transmit DMA Raw Interrupt
                                            // Status
#define 		UART_RIS_DMARXRIS       0x00010000  // Receive DMA Raw Interrupt Status
#define 		UART_RIS_9BITRIS        0x00001000  // 9-Bit Mode Raw Interrupt Status
#define 		UART_RIS_EOTRIS         0x00000800  // End of Transmission Raw
                                            // Interrupt Status
#define 		UART_RIS_OERIS          0x00000400  // UART Overrun Error Raw Interrupt
                                            // Status
#define 		UART_RIS_BERIS          0x00000200  // UART Break Error Raw Interrupt
                                            // Status
#define 		UART_RIS_PERIS          0x00000100  // UART Parity Error Raw Interrupt
                                            // Status
#define 		UART_RIS_FERIS          0x00000080  // UART Framing Error Raw Interrupt
                                            // Status
#define 		UART_RIS_RTRIS          0x00000040  // UART Receive Time-Out Raw
                                            // Interrupt Status
#define 		UART_RIS_TXRIS          0x00000020  // UART Transmit Raw Interrupt
                                            // Status
#define 		UART_RIS_RXRIS          0x00000010  // UART Receive Raw Interrupt
                                            // Status
#define 		UART_RIS_DSRRIS         0x00000008  // UART Data Set Ready Modem Raw
                                            // Interrupt Status
#define 		UART_RIS_DCDRIS         0x00000004  // UART Data Carrier Detect Modem
                                            // Raw Interrupt Status
#define 		UART_RIS_CTSRIS         0x00000002  // UART Clear to Send Modem Raw
                                            // Interrupt Status
#define 		UART_RIS_RIRIS          0x00000001  // UART Ring Indicator Modem Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTMIS register.
//
//*****************************************************************************
#define 		UART_MIS_DMATXMIS       0x00020000  // Transmit DMA Masked Interrupt
                                            // Status
#define 		UART_MIS_DMARXMIS       0x00010000  // Receive DMA Masked Interrupt
                                            // Status
#define 		UART_MIS_9BITMIS        0x00001000  // 9-Bit Mode Masked Interrupt
                                            // Status
#define 		UART_MIS_EOTMIS         0x00000800  // End of Transmission Masked
                                            // Interrupt Status
#define 		UART_MIS_OEMIS          0x00000400  // UART Overrun Error Masked
                                            // Interrupt Status
#define 		UART_MIS_BEMIS          0x00000200  // UART Break Error Masked
                                            // Interrupt Status
#define 		UART_MIS_PEMIS          0x00000100  // UART Parity Error Masked
                                            // Interrupt Status
#define 		UART_MIS_FEMIS          0x00000080  // UART Framing Error Masked
                                            // Interrupt Status
#define 		UART_MIS_RTMIS          0x00000040  // UART Receive Time-Out Masked
                                            // Interrupt Status
#define 		UART_MIS_TXMIS          0x00000020  // UART Transmit Masked Interrupt
                                            // Status
#define 		UART_MIS_RXMIS          0x00000010  // UART Receive Masked Interrupt
                                            // Status
#define 		UART_MIS_DSRMIS         0x00000008  // UART Data Set Ready Modem Masked
                                            // Interrupt Status
#define 		UART_MIS_DCDMIS         0x00000004  // UART Data Carrier Detect Modem
                                            // Masked Interrupt Status
#define 		UART_MIS_CTSMIS         0x00000002  // UART Clear to Send Modem Masked
                                            // Interrupt Status
#define 		UART_MIS_RIMIS          0x00000001  // UART Ring Indicator Modem Masked
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTICR register.
//
//*****************************************************************************
#define 		UART_ICR_DMATXIC        0x00020000  // Transmit DMA Interrupt Clear
#define 		UART_ICR_DMARXIC        0x00010000  // Receive DMA Interrupt Clear
#define 		UART_ICR_9BITIC         0x00001000  // 9-Bit Mode Interrupt Clear
#define 		UART_ICR_EOTIC          0x00000800  // End of Transmission Interrupt
                                            // Clear
#define 		UART_ICR_OEIC           0x00000400  // Overrun Error Interrupt Clear
#define 		UART_ICR_BEIC           0x00000200  // Break Error Interrupt Clear
#define 		UART_ICR_PEIC           0x00000100  // Parity Error Interrupt Clear
#define 		UART_ICR_FEIC           0x00000080  // Framing Error Interrupt Clear
#define 		UART_ICR_RTIC           0x00000040  // Receive Time-Out Interrupt Clear
#define 		UART_ICR_TXIC           0x00000020  // Transmit Interrupt Clear
#define 		UART_ICR_RXIC           0x00000010  // Receive Interrupt Clear
#define 		UART_ICR_DSRMIC         0x00000008  // UART Data Set Ready Modem
                                            // Interrupt Clear
#define 		UART_ICR_DCDMIC         0x00000004  // UART Data Carrier Detect Modem
                                            // Interrupt Clear
#define 		UART_ICR_CTSMIC         0x00000002  // UART Clear to Send Modem
                                            // Interrupt Clear
#define 		UART_ICR_RIMIC          0x00000001  // UART Ring Indicator Modem
                                            // Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTDMACTL register.
//
//*****************************************************************************
#define 		UART_DMACTL_DMAERR      0x00000004  // DMA on Error
#define 		UART_DMACTL_TXDMAE      0x00000002  // Transmit DMA Enable
#define 		UART_DMACTL_RXDMAE      0x00000001  // Receive DMA Enable

//*****************************************************************************
// The following are defines for the bit fields in the UART9BITADDR register.
//*****************************************************************************
#define 		UART_9BITADDR_9BITEN    0x00008000  // Enable 9-Bit Mode
#define 		UART_9BITADDR_ADDR_M    0x000000FF  // Self Address for 9-Bit Mode
#define 		UART_9BITADDR_ADDR_S    0

//*****************************************************************************
// The following are defines for the bit fields in the UART9BITAMASK register.
//*****************************************************************************
#define UART_9BITAMASK_MASK_M   0x000000FF  // Self Address Mask for 9-Bit Mode
#define UART_9BITAMASK_MASK_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTPP register.
//
//*****************************************************************************
#define 		UART_PP_MSE             0x00000008  // Modem Support Extended
#define 		UART_PP_MS              0x00000004  // Modem Support
#define 		UART_PP_NB              0x00000002  // 9-Bit Support
#define 		UART_PP_SC              0x00000001  // Smart Card Support

//*****************************************************************************
//
// The following are defines for the bit fields in the UARTCC register.
//
//*****************************************************************************
#define 		UART_CC_CS_M            0x0000000F  // UART Baud Clock Source
#define 		UART_CC_CS_SYSCLK       0x00000000  // System clock (based on clock
                                            		// source and divisor factor)
#define 		UART_CC_CS_PIOSC        0x00000005  // PIOSC

/* ========================================================================== */
/*                           Structures and Enums                             */
/* ========================================================================== */

typedef enum parity
{
ODD ,
EVEN,
}parity_t ;

typedef enum fifoLevel
{
FIFO_1_8,
FIFO_1_4,
FIFO_1_2,
FIFO_3_4,
FIFO_7_8,
DEFAULT = 2 ,
}fifoLevel_t ;
typedef enum wordlength
{
five_bits,
six_bits,
seven_bits,
eight_bits,

}wordLength_t ;

typedef enum clockSource
{
system_clock,
piosc = 5 ,

}clockSource_t ;
/* ========================================================================== */
/*                           Function Declarations                            */
/* ========================================================================== */

void UART_parityModeSet(uint32_t uartBase, parity_t parity);
void UART_stickParityEnable(uint32_t uartBase );
void UART_stickParityDisable(uint32_t uartBase ) ;

void UART_parityEnable(uint32_t uartBase) ;
void UART_parityDisable(uint32_t uartBase);

void UARTEnable(uint32_t uartBase);
void UARTDisable(uint32_t uartBase);

void UART_txEnable(uint32_t uartBase);
void UART_RxEnable(uint32_t uartBase);

void UART_FIFO_RX_LevelSet( uint32_t uartBase,
							fifoLevel_t rxLevel);
void UART_FIFO_TX_LevelSet( uint32_t uartBase,
							fifoLevel_t rxLevel) ;
void UART_FIFO_Enable(uint32_t uartBase) ;
void UART_FIFO_Disable(uint32_t uartBase) ;

void UART_setBaudRate(uint32_t uartBase ,
					  uint32_t frequency ,
					  uint32_t baudRate	  );

void UART_SIR_Mode_Disable(uint32_t uartBase) ;
void UART_SIR_Mode_Enable(uint32_t uartBase) ;

void UART_SIR_Disable(uint32_t uartBase);
void UART_SIR_Enable(uint32_t uartBase);

boolean_t UART_SpaceAvailable(uint32_t ui32Base) ;
boolean_t UART_CharsAvailable(uint32_t uartBase) ;

uint32_t UART_readChar(uint32_t uartBase) ;
void UART_sendChar(uint32_t uartBase,uint8_t data) ;
void UART_printString(uint32_t uartBase,uint8_t * data) ;


void UART_breakControl(uint32_t uartBase , boolean_t state) ;
boolean_t UART_busy(uint32_t uartBase) ;
void UART_rxClearError(uint32_t uartBase) ;
void UART_wordLength(uint32_t uartBase , wordLength_t wordLength) ;
uint32_t UART_rxGetError(uint32_t uartBase) ;
void UART_loopBackEnable(uint32_t uartBase);
void UART_smartCard_Enable(uint32_t uartBase);
void UART_smartCard_Disable(uint32_t uartBase);
void UART_clockConfiguration(uint32_t uartBase);
void UART_inIt(uint32_t uartBase,uint32_t baudRate ) ;
#endif /* HAL_UART_H_ */
