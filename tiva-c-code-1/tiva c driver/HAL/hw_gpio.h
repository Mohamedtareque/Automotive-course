/*
 * hw_gpio.h
 *
 *  Created on: Aug 17, 2017
 *      Author: Mohamed
 */

#ifndef HAL_RAL_HW_GPIO_H_
#define HAL_RAL_HW_GPIO_H_
#include"types.h"

/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define 					PORTA_BASE 					0x40004000			// PORT A BASE Address
#define 					PORTB_BASE 					0x40005000			// PORT B BASE Address
#define 					PORTC_BASE 					0x40006000			// PORT C BASE Address
#define 					PORTD_BASE 					0x40007000			// PORT D BASE Address
#define 					PORTE_BASE 					0x40024000			// PORT E BASE Address
#define 					PORTF_BASE 					0x40025000			// PORT F BASE Address
#define 					CORE_PRE_BASE 				0xE000E000			// NVIC BASE Address



/****************************************************************************************************
* Field Definition Offsets
****************************************************************************************************/

#define 					GPIODATA 					0x3FC				// GPIO DATA Register OFFSET
#define 					GPIODIR 					0x400				// GPIO Direction Register OFFSET
#define 					GPIOIS 						0x404				// GPIO interrupt Sense Register OFFSET
#define 					GPIOIBE						0x408				// GPIO Interrupt Both Edges  Register OFFSET
#define 					GPIOIEV 					0x40C				// GPIO Interrupt Event Register OFFSET
#define 					GPIOIM	 					0x410				// GPIO Interrupt Mask Register OFFSET
#define 					GPIORIS						0x414				// GPIO Raw Interrupt Status Register OFFSET
#define 					GPIOMIS						0x418				// GPIO Masked Interrupt Status Register OFFSET
#define 					GPIOICR 					0x41C				// GPIO Interrupt Clear Register OFFSET
#define 					GPIOAFSEL 					0x420				// GPIO Alternative Function Select Register OFFSET
#define 					GPIODR2R					0x500				// GPIO  2 m-A Drive select Register OFFSET
#define 					GPIODR4R					0x504				// GPIO  4 m-A Drive select Register OFFSET
#define 					GPIODR8R					0x508				// GPIO  8 m-A Drive select Register OFFSET
#define 					GPIOODR						0x50C				// GPIO Open Drain Register OFFSET
#define 					GPIOPUR						0x510				// GPIO Pull Up Resistor  Register OFFSET
#define 					GPIOPDR						0x514				// GPIO  Pull Down Resistor Register OFFSET
#define 					GPIOSLR						0x518				// GPIO  Slew rate control select Register OFFSET
#define 					GPIODEN						0x51C				// GPIO Digital Enable Register OFFSET
#define 					GPIOLOCK					0x520				// GPIO  Lock Register OFFSET
#define 					GPIOCR						0x524				// GPIO  Commit Register OFFSET
#define 					GPIOAMSEL					0x528				// GPIO  Analog Mode Select Register OFFSET
#define 					GPIOPCTL					0x52C				// GPIO  Port Control Register OFFSET
#define 					GPIOADCCTL					0x530				// GPIO  Analog Digital Converter Control Register OFFSET
#define 					GPIODMACTL					0x534				// GPIO  Direct Memory Access Control Register OFFSET
#define 					LOCKKEY						0x4C4F434B

/****************************************************************************************************
* Field Definition NVIC Offsets
****************************************************************************************************/

#define 					NVICEN0							0x100 				// Interrupt0-31 SetEnable(EN0)
#define 					NVICEN1							0x104 				// Interrupt32-63 SetEnable(EN1)
#define 					NVICEN2							0x108 				// Interrupt64-95 SetEnable(EN2)
#define 					NVICEN3							0x10C				// Interrupt96-127 SetEnable(EN3)
#define 					NVICEN4							0x110 				// Interrupt128-138 SetEnable(EN4)
#define 					NVICDIS0						0x180 				// Interrupt0-31 Clear Enable(EN0)
#define 					NVICDIS1						0x184 				// Interrupt32-63 Clear Enable(EN1)
#define 					NVICDIS2						0x188 				// Interrupt64-95 Clear Enable(EN2)
#define 					NVICDIS3						0x18C				// Interrupt96-127 Clear Enable(EN3)
#define 					NVICDIS4						0x190 				// Interrupt128-138 Clear Enable(EN4)

#define 					NVICPEN0						0x200 				// Interrupt0-31 Set Pending(EN0)
#define 					NVICPEN1						0x204 				// Interrupt32-63 Set Pending(EN1)
#define 					NVICPEN2						0x208 				// Interrupt64-95 Set Pending(EN2)
#define 					NVICPEN3						0x20C				// Interrupt96-127 Set Pending(EN3)
#define 					NVICPEN4						0x210 				// Interrupt128-138 Set Pending(EN4)

#define 					NVICUNPEN0						0x280 				// Interrupt0-31 Clear Pending(EN0)
#define 					NVICUNPEN1						0x284 				// Interrupt32-63 Clear Pending(EN1)
#define 					NVICUNPEN2						0x288 				// Interrupt64-95 Clear Pending(EN2)
#define 					NVICUNPEN3						0x28C				// Interrupt96-127 Clear Pending(EN3)
#define 					NVICUNPEN4						0x290 				// Interrupt128-138 Clear Pending(EN4)

#define 					NVICACTIVE0						0x300 				// Interrupt 0-31 ActiveBit(ACTIVE0)
#define 					NVICACTIVE1						0x304 				// Interrupt 32-63 ActiveBit(ACTIVE1)
#define 					NVICACTIVE2						0x308 				// Interrupt 64-95 ActiveBit(ACTIVE2)
#define 					NVICACTIVE3						0x30C				// Interrupt 96-127 ActiveBit(ACTIVE3)
#define 					NVICACTIVE4						0x310 				// Interrupt 128-138 ActiveBit(ACTIVE4)


#define						NVICPRI0						0x400 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI1						0x404 				//Interrupt 4-7 Priority(PRI0)
#define						NVICPRI2						0x408 				//Interrupt 12-15 Priority(PRI0)
#define						NVICPRI3						0x40C 				//Interrupt 16-19 Priority(PRI0)
#define						NVICPRI4						0x410 				//Interrupt 20-23 Priority(PRI0)
#define						NVICPRI5						0x414 				//Interrupt 24-27 Priority(PRI0)
#define						NVICPRI6						0x418 				//Interrupt 28-31 Priority(PRI0)
#define						NVICPRI7						0x41C 				//Interrupt 32-35 Priority(PRI0)
#define						NVICPRI8						0x420 				//Interrupt 36-39 Priority(PRI0)
#define						NVICPRI9						0x424 				//Interrupt 40-43 Priority(PRI0)
#define						NVICPRI10						0x428 				//Interrupt 44-47 Priority(PRI0)
#define						NVICPRI11						0x42C 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI12						0x430 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI13						0x434 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI14						0x438 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI15						0x43C 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI16						0x440 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI17						0x444 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI18						0x448 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI19						0x44C 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI20						0x450 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI21						0x454 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI22						0x458 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI23						0x45C 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI24						0x460 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI25						0x464 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI26						0x468 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI27						0x46C 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI28						0x470 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI29						0x474 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI30						0x478 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI31						0x47C 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI32						0x480 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI33						0x484 				//Interrupt 0-3 Priority(PRI0)
#define						NVICPRI34						0x488 				//Interrupt 0-3 Priority(PRI0)

#define				APINT						0xD0C				//ApplicationInterruptandResetControl



/****************************************************************************************************
* Field Definition PeripheralReady Offsets
****************************************************************************************************/

#define 					PRWD                   0x400FEA00UL
#define 					PRTIMER                0x400FEA04UL
#define 					PRGPIO                 0x400FEA08UL
#define 					PRDMA                  0x400FEA0CUL
#define 					PRHIB                  0x400FEA14UL
#define 					PRUART                 0x400FEA18UL
#define 					PRSSI                  0x400FEA1CUL
#define 					PRI2C                  0x400FEA20UL
#define 					PRUSB                  0x400FEA28UL
#define 					PRCAN                  0x400FEA34UL
#define 					PRADC                  0x400FEA38UL
#define 					PRACMP                 0x400FEA3CUL
#define 					PRPWM                  0x400FEA40UL
#define 					PRQEI                  0x400FEA44UL
#define 					PREEPROM               0x400FEA58UL
#define 					PRWTIMER               0x400FEA5CUL






#endif
