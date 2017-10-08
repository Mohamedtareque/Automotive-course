/*
 * system.h
 *
 *  Created on: Aug 17, 2017
 *      Author: Mohamed
 */

#ifndef HAL_SYSTEM_H_
#define HAL_SYSTEM_H_
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
//#include "../HAL/types.h"

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
//NONE
/* ========================================================================== */
/*                           Structures and Enums                             */
/* ========================================================================== */
typedef enum timercount{
	COUNTS_DOWN,
	COUNTS_UP
}gTmerCount_t;

typedef enum ModuleName{
	 WDT,
	 GPT,
	 GPIO,
	 DMA,
	 Hibernation,
	 UART,
	 SSI,
	 I2C,
	 USB,
	 CAN,
	 ADC,
	 ACMP,
	 PWM,
	 QEI,
	 EEPROM,
	 WTIMER
}gModuleName;

typedef enum WDT{
	WDT_module0,
	WDT_module1
}gWDT_t;

typedef enum Timer{
	T_module0,
	T_module1,
	T_module2,
	T_module3,
	T_module4,
	T_module5
}gTimer_t;

typedef enum GPIO{
	GPIO_PORT_A,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_D,
	GPIO_PORT_E,
	GPIO_PORT_F
}gGPIO_t;

typedef enum DMA{
	DMA_module0,
}gDMA_t;

typedef enum HIB{
	HIB_module0,
}gHIB_t;

typedef enum UART{
	UART_module0,
	UART_module1,
	UART_module2,
	UART_module3,
	UART_module4,
	UART_module5,
	UART_module6,
	UART_module7
}gUART_t;

typedef enum SSI{
	SSI_module0,
	SSI_module1,
	SSI_module2,
	SSI_module3,
}gSSI_t;

typedef enum I2C{
	I2C_module0,
	I2C_module1,
	I2C_module2,
	I2C_module3,
}gI2C_t;

typedef enum USB{
	USB_module0,
}gUSB_t;


typedef enum CAN{
	CAN_module0,
	CAN_module1
}gCAN_t;

typedef enum ADC{
	ADC_module0,
	ADC_module1
}gADC_t;

typedef enum ACMP{
	ACMP_module0,
}gACMP_t;

typedef enum PWM{
	PWM_module0,
	PWM_module1
}gPWM_t;

typedef enum QEI{
	QEI_module0,
	QEI_module1
}gQEI_t;

typedef enum EEPROM{
	EEPROM_module0,
}gEEPROM_t;

typedef enum W_TIMER{
	W_TIMER_module0,
	W_TIMER_module1,
	W_TIMER_module2,
	W_TIMER_module3,
	W_TIMER_module4,
	W_TIMER_module5
}gWTIMER_t;

typedef enum State{
	Disable_CLOCK,
	Enable_CLOCK
}gState_t;


typedef struct CfgModuleName{
	gModuleName name;
}gModuleName_t;


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
	  PWM1_FAULT_IRQn               = 138               /*!< 138  PWM1_FAULT                                                       */
} g_IRQn_t;

/* ========================================================================== */
/*                           Variables Declarations                           */
/* ========================================================================== */

/*   None  */
/**************************************************************************************
*********************************** System Functions *********************************
***************************************************************************************/
/**
 * \brief  This API configures the Run Clock Gate of a specified Prepherial
 * \param  pModNam      is pointer to struct which contains prepherials Names
 * \param  module_num   is related to each prepherial features (Various num)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
void enableClockGating(gModuleName_t *pModNam ,
						unsigned char module_num ,
					   unsigned char state ) ;
/**
 * \brief  This API returns the Run Clock Gate state of a specified Prepherial
 * \param  pModNam      is pointer to struct which contains prepherials Names
 * \param  module_num   is related to each prepherial features (Various num)
 */
unsigned char ISReady(gModuleName_t *obj,
			  unsigned char module_num) ;


/**************************************************************************************
********************************** NVIC Functions ***********************************
***************************************************************************************/
/**
 * \brief  This API configures Interrupt Enable of a specified bit
 * \param  IRQn      is object from enumerate which carry num of int from NVIC table
 */


void NVIC_EnableIRQ(g_IRQn_t  IRQn);

/**
 * \brief  This API configures Interrupt Disable of a specified bit
 * \param  IRQn      is object from enumerate which carry num of int from NVIC table
 */
void NVIC_DisableIRQ(g_IRQn_t  IRQn) ;

/**
 * \brief  This API return Interrupt pending status of a specified int
 * \param  IRQn      is object from enumerate which carry num of int from NVIC table
 */
unsigned int NVIC_GetPendingIRQ(g_IRQn_t  IRQn);
/**
 * \brief  This API Configures Interrupt pending status of a specified int
 * \param  IRQn      is object from enumerate which carry num of int from NVIC table
 */
void NVIC_SetPendingIRQ(g_IRQn_t  IRQn);
/**
 * \brief  This API Clearing Interrupt pending status of a specified int
 * \param  IRQn      is object from enumerate which carry num of int from NVIC table
 */
void NVIC_ClearPendingIRQ(g_IRQn_t  IRQn);
/**
 * \brief  This API Clearing Interrupt pending status of a specified int
 * \param  IRQn      is object from enumerate which carry num of int from NVIC table
 */
unsigned int NVIC_GetActive(g_IRQn_t  IRQn);
/**
 * \brief  This API Clearing Interrupt pending status of a specified int
 * \param  IRQn      is object from enumerate which carry num of int from NVIC table
 * \param  priority    select the priority of int
 */
void NVIC_SetPriority(g_IRQn_t  IRQn, unsigned char priority);

/**********************************************************************************************
*********************************** System Timer Functions ***********************************
***********************************************************************************************/
/**
 * \brief  This API Enable System Timer
 * \param	NONE
 */

void SysTick_SetPeriod(unsigned int val) ;

void SysTick_Control(unsigned int val);

void SysTick_Delay_Mili(unsigned int delay_val);

#endif /* HAL_SYSTEM_H_ */
