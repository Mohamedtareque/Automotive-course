#ifndef GPIO_APP_C_
#define GPIO_APP_C_
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* Application header files */
#include "../gpioapp/gpio_app.h"
/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

void GPIO_pinInit(gpio_t *pGpio)
{
	gpioPinCfg_t obj ;
	obj.gpiodir = pGpio->dir ;
	obj.gpioden = pGpio->digital ;
	obj.gpioafsel = pGpio->alternative ;
	obj.gpioamsel = pGpio->analog ;
	obj.gpiopctl  = pGpio->pctl ;
	obj.gpiocr    = HIGH ;
	//obj.gpiodata = pGpio->write;
	obj.currentVal = pGpio->current ;
	obj.resType	  = pGpio->res ;
	GPIOConfig(pGpio->base,  pGpio->pinNum , &obj);
}

void GPIO_intInit(gpio_t *pGpio)
{
	gpioPinCfg_t obj ;
	if(pGpio->enableInt == 1 )
	{
		obj.gpioim = UNMASKED ;
		obj.gpiois = pGpio->intSens ;
		obj.gpioibe = pGpio->intBothEdges ;
		obj.gpioiev = pGpio->intEvent ;
		obj.gpioicr = pGpio->intClear ;

	}
	GPIOIntConfig(pGpio->base ,pGpio->pinNum ,&obj);

}


#endif

