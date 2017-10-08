#ifndef GPIO_APP_H_
#define GPIO_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "../HAL/gpio.h"
#include "../HAL/uart.h"
#include "../HAL/system.h"
#include"../SAL/NVICInterruptHandler.h"

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

#define 		Enable			1
#define 		Disable			0


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
typedef struct gpio
{
	uint8_t pinNum ;
	/**< GPIO pin number. */
	uint32_t base ;
	uint8_t dir ;
	uint8_t res ;
	uint8_t current ;
	uint8_t alternative ;
	uint8_t pctl ;
	uint8_t analog ;
	uint8_t digital ;
	//uint8_t write ;
	uint8_t enableInt ;
	uint8_t intSens ;
	uint8_t intBothEdges ;
	uint8_t intEvent ;
	uint8_t intClear ;
	gpioPinCfg_t pinCfg;
}gpio_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/**NONE***/

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

void GPIO_pinInit(gpio_t *pGpio);
void GPIO_intInit(gpio_t *pGpio);

#endif
