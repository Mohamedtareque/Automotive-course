/*
 * nvicInterruptHandler.h
 *
 *  Created on: Aug 17, 2017
 *      Author: Mohamed
 */
#ifndef NIVCINTERUPTHANDLER_H_
#define NIVCINTERUPTHANDLER_H_
#include"../HAL/system.h"
#if 0
typedef enum
{
	 GPIOA_IRQn                    =   0,              /*!<   0  GPIOA                                                            */
		  GPIOB_IRQn                    =   1,              /*!<   1  GPIOB                                                            */
		  GPIOC_IRQn                    =   2,              /*!<   2  GPIOC                                                            */
		  GPIOD_IRQn                    =   3,              /*!<   3  GPIOD                                                            */
		  GPIOE_IRQn                    =   4,              /*!<   4  GPIOE                                                            */
		  UART0_IRQn                    =   5,              /*!<   5  UART0                                                            */
		  UART1_IRQn                    =   6,              /*!<   6  UART1                                                            */
		  SSI0_IRQn                     =   7,              /*!<   7  SSI0                                                             */
		  I2C0_IRQn                     =   8,              /*!<   8  I2C0                                                             */
		  PWM0_FAULT_IRQn               =   9,              /*!<   9  PWM0_FAULT                                                       */
		  PWM0_0_IRQn                   =  10,              /*!<  10  PWM0_0                                                           */
		  PWM0_1_IRQn                   =  11,              /*!<  11  PWM0_1                                                           */
		  PWM0_2_IRQn                   =  12,              /*!<  12  PWM0_2                                                           */
		  QEI0_IRQn                     =  13,              /*!<  13  QEI0                                                             */
		  ADC0SS0_IRQn                  =  14,              /*!<  14  ADC0SS0                                                          */
		  ADC0SS1_IRQn                  =  15,              /*!<  15  ADC0SS1                                                          */
		  ADC0SS2_IRQn                  =  16,              /*!<  16  ADC0SS2                                                          */
		  ADC0SS3_IRQn                  =  17,              /*!<  17  ADC0SS3                                                          */
		  WATCHDOG0_IRQn                =  18,              /*!<  18  WATCHDOG0                                                        */
		  TIMER0A_IRQn                  =  19,              /*!<  19  TIMER0A                                                          */
		  TIMER0B_IRQn                  =  20,              /*!<  20  TIMER0B                                                          */
		  TIMER1A_IRQn                  =  21,              /*!<  21  TIMER1A                                                          */
		  TIMER1B_IRQn                  =  22,              /*!<  22  TIMER1B                                                          */
		  TIMER2A_IRQn                  =  23,              /*!<  23  TIMER2A                                                          */
		  TIMER2B_IRQn                  =  24,              /*!<  24  TIMER2B                                                          */
		  COMP0_IRQn                    =  25,              /*!<  25  COMP0                                                            */
		  COMP1_IRQn                    =  26,              /*!<  26  COMP1                                                            */
		  SYSCTL_IRQn                   =  28,              /*!<  28  SYSCTL                                                           */
		  FLASH_CTRL_IRQn               =  29,              /*!<  29  FLASH_CTRL                                                       */
		  GPIOF_IRQn                    =  30,              /*!<  30  GPIOF                                                            */
		  UART2_IRQn                    =  33,              /*!<  33  UART2                                                            */
		  SSI1_IRQn                     =  34,              /*!<  34  SSI1                                                             */
		  TIMER3A_IRQn                  =  35,              /*!<  35  TIMER3A                                                          */
		  TIMER3B_IRQn                  =  36,              /*!<  36  TIMER3B                                                          */
		  I2C1_IRQn                     =  37,              /*!<  37  I2C1                                                             */
		  QEI1_IRQn                     =  38,              /*!<  38  QEI1                                                             */
		  CAN0_IRQn                     =  39,              /*!<  39  CAN0                                                             */
		  CAN1_IRQn                     =  40,              /*!<  40  CAN1                                                             */
		  HIB_IRQn                      =  43,              /*!<  43  HIB                                                              */
		  USB0_IRQn                     =  44,              /*!<  44  USB0                                                             */
		  PWM0_3_IRQn                   =  45,              /*!<  45  PWM0_3                                                           */
		  UDMA_IRQn                     =  46,              /*!<  46  UDMA                                                             */
		  UDMAERR_IRQn                  =  47,              /*!<  47  UDMAERR                                                          */
		  ADC1SS0_IRQn                  =  48,              /*!<  48  ADC1SS0                                                          */
		  ADC1SS1_IRQn                  =  49,              /*!<  49  ADC1SS1                                                          */
		  ADC1SS2_IRQn                  =  50,              /*!<  50  ADC1SS2                                                          */
		  ADC1SS3_IRQn                  =  51,              /*!<  51  ADC1SS3                                                          */
		  SSI2_IRQn                     =  57,              /*!<  57  SSI2                                                             */
		  SSI3_IRQn                     =  58,              /*!<  58  SSI3                                                             */
		  UART3_IRQn                    =  59,              /*!<  59  UART3                                                            */
		  UART4_IRQn                    =  60,              /*!<  60  UART4                                                            */
		  UART5_IRQn                    =  61,              /*!<  61  UART5                                                            */
		  UART6_IRQn                    =  62,              /*!<  62  UART6                                                            */
		  UART7_IRQn                    =  63,              /*!<  63  UART7                                                            */
		  I2C2_IRQn                     =  68,              /*!<  68  I2C2                                                             */
		  I2C3_IRQn                     =  69,              /*!<  69  I2C3                                                             */
		  TIMER4A_IRQn                  =  70,              /*!<  70  TIMER4A                                                          */
		  TIMER4B_IRQn                  =  71,              /*!<  71  TIMER4B                                                          */
		  TIMER5A_IRQn                  =  92,              /*!<  92  TIMER5A                                                          */
		  TIMER5B_IRQn                  =  93,              /*!<  93  TIMER5B                                                          */
		  WTIMER0A_IRQn                 =  94,              /*!<  94  WTIMER0A                                                         */
		  WTIMER0B_IRQn                 =  95,              /*!<  95  WTIMER0B                                                         */
		  WTIMER1A_IRQn                 =  96,              /*!<  96  WTIMER1A                                                         */
		  WTIMER1B_IRQn                 =  97,              /*!<  97  WTIMER1B                                                         */
		  WTIMER2A_IRQn                 =  98,              /*!<  98  WTIMER2A                                                         */
		  WTIMER2B_IRQn                 =  99,              /*!<  99  WTIMER2B                                                         */
		  WTIMER3A_IRQn                 = 100,              /*!< 100  WTIMER3A                                                         */
		  WTIMER3B_IRQn                 = 101,              /*!< 101  WTIMER3B                                                         */
		  WTIMER4A_IRQn                 = 102,              /*!< 102  WTIMER4A                                                         */
		  WTIMER4B_IRQn                 = 103,              /*!< 103  WTIMER4B                                                         */
		  WTIMER5A_IRQn                 = 104,              /*!< 104  WTIMER5A                                                         */
		  WTIMER5B_IRQn                 = 105,              /*!< 105  WTIMER5B                                                         */
		  SYSEXC_IRQn                   = 106,              /*!< 106  SYSEXC                                                           */
		  PWM1_0_IRQn                   = 134,              /*!< 134  PWM1_0                                                           */
		  PWM1_1_IRQn                   = 135,              /*!< 135  PWM1_1                                                           */
		  PWM1_2_IRQn                   = 136,              /*!< 136  PWM1_2                                                           */
		  PWM1_3_IRQn                   = 137,              /*!< 137  PWM1_3                                                           */
		  PWM1_FAULT_IRQn               = 138
} g_ISRVirIdx_t;
#endif

void installNIVCISRFunction(g_IRQn_t idx, void (*isr)(void));
void deInstallNIVCISRFunction(g_IRQn_t idx, void (*isr)(void));

void IntVirDefaultFun(void);
void PortAISRHandler(void);
void PortBISRHandler(void);
void PortCISRHandler(void);
void PortDISRHandler(void);
void PortEISRHandler(void);
void PortFISRHandler(void);

#endif/* SAL_NVICINTERRUPTHANDLER_H_ */
