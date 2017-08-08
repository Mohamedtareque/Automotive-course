/*
 * hw_gpio.h
 *
 *  Created on: Aug 7, 2017
 *      Author: Mohamed
 */

#ifndef HAL_RAL_HW_GPIO_H_
#define HAL_RAL_HW_GPIO_H_

#include"types.h"
#define 			PORTA_BASE 					0x40004000			// PORT A BASE Address
#define 			PORTB_BASE 					0x40005000			// PORT B BASE Address
#define 			PORTC_BASE 					0x40006000			// PORT C BASE Address
#define 			PORTD_BASE 					0x40007000			// PORT D BASE Address
#define 			PORTE_BASE 					0x40024000			// PORT E BASE Address
#define 			PORTF_BASE 					0x40025000			// PORT F BASE Address

#define 			GPIODATA 					0x3FC				// GPIO DATA Register OFFSET
#define 			GPIODIR 					0x400				// GPIO Direction Register OFFSET
#define 			GPIOIS 						0x404				// GPIO interrupt Sense Register OFFSET
#define 			GPIOIBE						0x408				// GPIO Interrupt Both Edges  Register OFFSET
#define 			GPIOIEV 					0x40C				// GPIO Interrupt Event Register OFFSET
#define 			GPIOIM	 					0x410				// GPIO Interrupt Mask Register OFFSET
#define 			GPIORIS						0x414				// GPIO Raw Interrupt Status Register OFFSET
#define 			GPIOMIS						0x418				// GPIO Masked Interrupt Status Register OFFSET
#define 			GPIOICR 					0x41C				// GPIO Interrupt Clear Register OFFSET
#define 			GPIOAFSEL 					0x420				// GPIO Alternative Function Select Register OFFSET
#define 			GPIODR2R					0x500				// GPIO  2 m-A Drive select Register OFFSET
#define 			GPIODR4R					0x504				// GPIO  4 m-A Drive select Register OFFSET
#define 			GPIODR8R					0x508				// GPIO  8 m-A Drive select Register OFFSET
#define 			GPIOODR						0x50C				// GPIO Open Drain Register OFFSET
#define 			GPIOPUR						0x510				// GPIO Pull Up Resistor  Register OFFSET
#define 			GPIOPDR						0x514				// GPIO  Pull Down Resistor Register OFFSET
#define 			GPIOSLR						0x518				// GPIO  Slew rate control select Register OFFSET
#define 			GPIODEN						0x51C				// GPIO Digital Enable Register OFFSET
#define 			GPIOLOCK					0x520				// GPIO  Lock Register OFFSET
#define 			GPIOCR						0x524				// GPIO  Commit Register OFFSET
#define 			GPIOAMSEL					0x528				// GPIO  Analog Mode Select Register OFFSET
#define 			GPIOPCTL					0x52C				// GPIO  Port Control Register OFFSET
#define 			GPIOADCCTL					0x530				// GPIO  Analog Digital Converter Control Register OFFSET
#define 			GPIODMACTL					0x534				// GPIO  Direct Memory Access Control Register OFFSET


#define 			PORTA 						0
#define 			PORTB 						1
#define 			PORTC 						2
#define 			PORTD 						3
#define 			PORTE 						4
#define 			PORTF 						5

#ifndef 			PA
#define 			PA 							PORTA
#endif
#ifndef 			PB
#define 			PB 							PORTB
#endif
#ifndef 			PC
#define 			PC 							PORTC
#endif
#ifndef 			PD
#define 			PD 							PORTD
#endif
#ifndef 			PE
#define 			PE 							PORTE
#endif
#ifndef 			PF
#define 			PF 							PORTF
#endif

#ifndef 			pa
#define 			pa 							PORTA
#endif
#ifndef 			pb
#define 			pb 							PORTB
#endif
#ifndef 			pc
#define 			PC 							PORTC
#endif
#ifndef 			pd
#define 			pd 							PORTD
#endif
#ifndef 			pe
#define 			pe 							PORTE
#endif
#ifndef 			pf
#define 			pf 							PORTF
#endif

#ifndef 			porta
#define 			porta 						PORTA
#endif
#ifndef 			portb
#define 			portb 						PORTB
#endif
#ifndef 			portc
#define 			portc 						PORTC
#endif
#ifndef 			portd
#define 			portd 						PORTD
#endif
#ifndef 			porte
#define 			porte 						PORTE
#endif
#ifndef 			portf
#define 			portf 						PORTF
#endif


#define 			PIN0 						0
#define 			PIN1					    1
#define 			PIN2 						2
#define 			PIN3 						3
#define 			PIN4 						4
#define 			PIN5 						5
#define 			PIN6 						6
#define 			PIN7 						7

#ifndef 			pin0
#define 			pin0 						PIN0
#endif
#ifndef 			pin1
#define 			pin1 						PIN1
#endif
#ifndef 			pin2
#define 			pin2 						PIN2
#endif
#ifndef 			pin3
#define 			pin3 						PIN3
#endif
#ifndef 			pin4
#define 			pin4						PIN4
#endif
#ifndef 			pin5
#define 			pin5 						PIN5
#endif
#ifndef 			pin6
#define 			pin6 						PIN6
#endif
#ifndef 			pin7
#define 			pin7 						PIN7
#endif

#define 			PCM0 						0
#define 			PCM1 						1
#define 			PCM2 						2
#define 			PCM3 						3
#define 			PCM4 						4
#define 			PCM5 						5
#define 			PCM6 						6
#define 			PCM7 						7

#ifndef 			pcm0
#define 			pcm0 						PCM0
#endif
#ifndef 			pcm1
#define 			pcm1 						PCM1
#endif
#ifndef 			pcm2
#define 			pcm2 						PCM2
#endif
#ifndef 			pcm3
#define 			pcm3 						PCM3
#endif
#ifndef 			pcm4
#define 			pcm4						PCM4
#endif
#ifndef 			pcm5
#define 			pcm5 						PCM5
#endif
#ifndef 			pcm6
#define 			pcm6 						PCM6
#endif
#ifndef 			pcm7
#define 			pcm7 						PCM7
#endif

#endif /* HAL_RAL_HW_GPIO_H_ */
