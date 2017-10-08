/*
 * gpio.c
 *
 *  Created on: Aug 17, 2017
 *      Author: Mohamed
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "../HAL/gpio.h"

#include "../HAL/hw_gpio.h"
#include "../HAL/system.h"
#include "../HAL/types.h"
#include "../HAL/hw_types.h"
#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */


/** None**/


/* ========================================================================== */
/*                             Structures and Enums                           */
/* ========================================================================== */

/** None **/


/* ========================================================================== */
/*                             Global Variables Declarations                  */
/* ========================================================================== */


/** None **/


/* ========================================================================== */
/*                              Function Definitions                    */
/* ========================================================================== */

/**   ----------------------------Set Direction -------------------- **/
void GPIOSetDirection(uint32_t baseAddr,
				uint32_t pinNumber,
				uint32_t pinDirection)
{
	uint32_t regVal = HW_RD_REG32(baseAddr+GPIODIR);
	if(GPIO_DIRECTION_OUTPUT == pinDirection)
	{
		regVal|= (1U<<pinNumber) ;
	}
	else if(GPIO_DIRECTION_INPUT == pinDirection)
	{
		regVal &= ~(1U<<pinNumber) ;
	}
	HW_WR_REG32((baseAddr+GPIODIR),regVal);
}

void GPIOSetDirection_field(uint32_t baseAddr,
					  uint32_t mask,
					  uint32_t value)
{
	HW_SET_REG32((baseAddr+GPIODIR),mask,value);
}

/**   ----------------------------Set Data on Pin -------------------- **/

void GPIOPinWrite(uint32_t baseAddr,
				  uint32_t pinNumber,
				  uint32_t pinValue)
{
	uint32_t regVal = HW_RD_REG32(baseAddr+GPIODATA);
	if(GPIO_OUTPUT_HIGH ==pinValue)
	{
		regVal|= (1U<<pinNumber);
	}
	else if(GPIO_OUTPUT_LOW ==pinValue)
	{
		regVal&=~(1U<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIODATA),regVal);
}

void GPIOPinWrite_field(uint32_t baseAddr,
						uint32_t mask,
						uint32_t value)
{
	HW_SET_REG32((baseAddr+GPIODATA),value,mask);
}

/**   ---------------------------- Read data from Pin -------------------- **/

uint8_t GPIOPinRead(uint32_t baseAddr,
					 uint32_t pinNumber)
{
	uint32_t regVal =HW_RD_REG32((baseAddr+GPIODATA));
	uint32_t pinReading = ((regVal & (1<<pinNumber))>>pinNumber);
	if(GPIO_OUTPUT_HIGH==pinReading)
	{
		return GPIO_OUTPUT_HIGH ;
	}
	else if(GPIO_OUTPUT_LOW==pinReading)
	{
		return GPIO_OUTPUT_LOW ;
	}
	return 0 ;
}


/**   ----------------------------Set lock  -------------------- **/
void GPIOlockInit(uint32_t baseAddr)
{
	uint32_t lockVal= LOCKKEY ;
	HW_WR_REG32((baseAddr+GPIOLOCK), lockVal);
}

/**   ----------------------------Set Commit  -------------------- **/

 void GPIOCommit(uint32_t baseAddr ,
 					 uint8_t pinNumber ,
 					 uint32_t value )
{
	uint32_t regVal = HW_RD_REG32(baseAddr+GPIOCR);
	if (ENABLE== value)
	{
		regVal |=(1U<<pinNumber);
	}
	else
	{
		regVal &=~(1U<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOCR),regVal);
}


 void GPIOCommit_field(uint32_t baseAddr ,
 					 	   uint8_t mask ,
 					 	   uint32_t value )
 {
 	HW_SET_REG32((baseAddr+GPIOCR),value,mask);
 }

/**   ----------------------------Set Digital pins  -------------------- **/

void GPIODigitalEnable(uint32_t baseAddr ,
						   uint8_t pinNumber,
						   uint8_t value)
{
	uint32_t regVal =HW_RD_REG32(baseAddr+GPIODEN);
	if (GPIO_DIGITAL_HIGH == value)
	{
		regVal |=(1U<<pinNumber);
	}
	else if (GPIO_DIGITAL_LOW == value)
	{
		regVal &=~(1U<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIODEN),regVal);
}

void GPIODigitalEnable_field(uint32_t baseAddr ,
						   	     uint8_t mask,
						   		 uint8_t value)
{
	HW_SET_REG32((baseAddr+GPIODEN),value,mask);
}

/**   ----------------------------Set Resistor Type  -------------------- **/

void GPIOCurrentVal(uint32_t baseAddr ,
 			     	 uint8_t pinNumber ,
					 uint32_t current )
{
		if (current == CURRENT_2MA)
		{
			uint32_t regVal = HW_RD_REG32(baseAddr+GPIODR2R);
			regVal |=(1U<<pinNumber);
			HW_WR_REG32((baseAddr+GPIODR2R),regVal);
		}
		else if (current ==CURRENT_4MA)
		{
			uint32_t regVal = HW_RD_REG32(baseAddr+GPIODR4R);
			regVal |=(1U<<pinNumber);
			HW_WR_REG32((baseAddr+GPIODR4R),regVal);
		}
		else if (current ==CURRENT_8MA)
		{
			uint32_t regVal = HW_RD_REG32(baseAddr+GPIODR8R);
			regVal |=(1U<<pinNumber);
			HW_WR_REG32((baseAddr+GPIODR8R),regVal);
		}
}

/**   ----------------------------Set Resistor Type  -------------------- **/
void GPIOSetResistor(uint32_t baseAddr ,
					 uint8_t pinNumber ,
					 uint8_t resType)
{
	if(resType == PULLUP)
	{
		uint32_t regVal = HW_RD_REG32(baseAddr+GPIOPUR);
		regVal |=(1U<<pinNumber);
		HW_WR_REG32((baseAddr+GPIOPUR),regVal);
	}
	else if (resType == PULLDOWN)
	{
		uint32_t regVal = HW_RD_REG32(baseAddr+GPIOPDR);
		regVal |=(1U<<pinNumber);
		HW_WR_REG32((baseAddr+GPIOPDR),regVal);
	}
	else if (resType ==OPENDRAIN)
	{
		uint32_t regVal = HW_RD_REG32(baseAddr+GPIOODR);
		regVal |=(1U<<pinNumber);
		HW_WR_REG32((baseAddr+GPIOODR),regVal);
	}

}

/**   ----------------------------Set Pull up Resistor  -------------------- **/


void GPIOPullUpResistor(uint32_t baseAddr ,
 							uint8_t pinNumber ,
 							uint32_t value )
{
	uint32_t regVal =HW_RD_REG32(baseAddr+GPIOPUR);
	if (HIGH==value)
	{
		regVal|=(1U<<pinNumber);
	}
	else
	{
		regVal &=~(1<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOPUR),regVal);
}

void GPIOPullUpResistor_field(uint32_t baseAddr ,
 								  uint8_t mask ,
 								  uint32_t value )
{
	HW_SET_REG32((baseAddr+GPIOPUR),value,mask);
}

/**   ----------------------------Set Pull Down Resistor  -------------------- **/


void GPIOPullDownResistor(uint32_t baseAddr ,
 							  uint8_t pinNumber ,
 							  uint32_t value )
{
	uint32_t regVal =HW_RD_REG32(baseAddr+GPIOPDR);
	if (HIGH==value)
	{
		regVal|=(1U<<pinNumber);
	}
	else
	{
		regVal &=~(1<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOPDR),regVal);
}

void GPIOPullDownResistor_field(uint32_t baseAddr ,
 								    uint8_t mask ,
 								    uint32_t value )
{
	HW_SET_REG32((baseAddr+GPIOPDR),value,mask);
}

/**   ----------------------------Set Open Drain state  -------------------- **/


void GPIOOpenDrain(uint32_t baseAddr ,
 					   uint8_t pinNumber ,
 					   uint32_t value )
{
	uint32_t regVal =HW_RD_REG32(baseAddr+GPIOODR);
	if (HIGH==value)
	{
		regVal|=(1U<<pinNumber);
	}
	else
	{
		regVal &=~(1<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOODR),regVal);
}

void GPIOOpenDrain_field(uint32_t baseAddr ,
 							 uint8_t mask ,
 							 uint32_t value )
{
	HW_SET_REG32((baseAddr+GPIOODR),value,mask);
}

/**   ----------------------------Set Alternative Functions  -------------------- **/


void GPIOAlternativeFunction(uint32_t baseAddr ,
 							uint8_t pinNumber ,
 							uint32_t value )
{
	uint32_t regVal = HW_RD_REG32(baseAddr+GPIOAFSEL);
	if (HIGH==value)
	{
		regVal|=(1U<<pinNumber);
	}
	else
	{
		regVal &=~(1U<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOAFSEL),regVal);
}

void GPIOAlternativeFunction_field(uint32_t baseAddr ,
 								   uint8_t mask ,
 								   uint32_t value )
{
	HW_SET_REG32((GPIOAFSEL+baseAddr),value,mask);
}

/**   ----------------------------Set Port Control Register  -------------------- **/


void GPIOPortControl(uint32_t baseAddr ,
 					 uint8_t pinNumber ,
 					 uint32_t value )
{
	uint32_t regVal=HW_RD_REG32(baseAddr + GPIOPCTL);
	uint8_t num  = (pinNumber * 4) ;
	regVal =(1<<0)|(1<<4);
	HW_WR_REG32((baseAddr+GPIOPCTL),regVal);
}
/*
void GPIOPortControl(uint32_t baseAddr, uint8_t pinNumber, uint32_t value)
{
	uint32_t regVal = HW_RD_REG32(baseAddr+GPIOPCTL);
	switch(pinNumber)
	{
		case 0 :
			HW_WR_REG32((baseAddr+GPIOPCTL),value) ;
			regVal = (regVal<<0);
			HW_WR_REG32((baseAddr+GPIOPCTL),regVal);
			break ;
		case 1 :
			HW_WR_REG32((baseAddr+GPIOPCTL),value) ;
			regVal = (regVal<<4);
			HW_WR_REG32((baseAddr+GPIOPCTL),regVal);
		case 2 :
			HW_WR_REG32((baseAddr+GPIOPCTL),value) ;
			regVal = (regVal<<8);
			HW_WR_REG32((baseAddr+GPIOPCTL),regVal);
			break ;
		case 3 :
			HW_WR_REG32((baseAddr+GPIOPCTL),value) ;
			regVal = (regVal<<12);
			HW_WR_REG32((baseAddr+GPIOPCTL),regVal);
			break ;
		case 4 :
			HW_WR_REG32((baseAddr+GPIOPCTL),value) ;
			regVal = (regVal<<16);
			HW_WR_REG32((baseAddr+GPIOPCTL),regVal);
			break ;
		case 5 :
			HW_WR_REG32((baseAddr+GPIOPCTL),value) ;
			regVal = (regVal<<20);
			HW_WR_REG32((baseAddr+GPIOPCTL),regVal);
			break ;
		case 6 :
			HW_WR_REG32((baseAddr+GPIOPCTL),value) ;
			regVal = (regVal<<24);
			HW_WR_REG32((baseAddr+GPIOPCTL),regVal);
			break ;
		case 7 :
			HW_WR_REG32((baseAddr+GPIOPCTL),value) ;
			regVal = (regVal<<28);
			HW_WR_REG32((baseAddr+GPIOPCTL),regVal);
			break ;
	}
}
*/

/**   ----------------------------Set Analog Mode Selection  -------------------- **/


  void GPIOAnalogModeSelect(uint32_t baseAddr ,
 								uint8_t pinNumber ,
 								uint32_t value )
  {
  	uint32_t regVal = HW_RD_REG32(baseAddr+GPIOAMSEL) ;
  	if(ENABLE==value)
  	{
  		regVal|=(1U<<pinNumber);
  	}
  	else
  	{
  		regVal &=~(1U<<pinNumber);
  	}
  	HW_WR_REG32((baseAddr+GPIOAMSEL),regVal);
  }

  void GPIOAnalogModeSelect_field(uint32_t baseAddr ,
 									  uint8_t mask ,
 									  uint32_t value )
  {
  	HW_SET_REG32((baseAddr+GPIOAMSEL),value,mask);
  }

/**   ----------------------------Set Clock  -------------------- **/

/*void GPIOClockInit(uint8_t port)
{
	uint32_t regVal = HW_RD_REG32(RCGCGPIO);
	regVal|=(1U<<port);
	HW_WR_REG32(RCGCGPIO,regVal);
}
*/
/**   ----------------------------Set Interrupt Sens  -------------------- **/

void GPIOInterruptSense(uint32_t baseAddr ,
 						uint8_t pinNumber ,
 						uint32_t value )
{
	uint32_t regVal = HW_RD_REG32(baseAddr+GPIOIS);
	if (GPIO_INTERRUPT_LEVEL == value)
	{
		regVal|=(1<<pinNumber);
	}
	else if (GPIO_INTERRUPT_EDGE == value)
	{
		regVal&=~(1<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOIS),regVal);
}

void GPIOInterruptSense_field(uint32_t baseAddr ,
 							  		uint8_t mask ,
 							  		uint32_t value )
{
	HW_SET_REG32((baseAddr+GPIOIS),value,mask);
}

/**   ----------------------------Set Interrupt Both Edges  -------------------- **/

void GPIOInterruptBothEdges(uint32_t baseAddr ,
 							uint8_t pinNumber ,
 							uint32_t value )
{
	uint32_t regVal = HW_RD_REG32(baseAddr+GPIOIBE);
	if (GPIO_INTERRUPT_BOTH_EDGES == value)
	{
		regVal|=(1<<pinNumber);
	}
	else if (GPIO_INTERRUPT_EVENT == value)
	{
		regVal&=~(1<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOIBE),regVal);
}

void GPIOInterruptBothEdges_field(uint32_t baseAddr ,
 							  		uint8_t mask ,
 							  		uint32_t value )
{
	HW_SET_REG32((baseAddr+GPIOIBE),value,mask);
}

/**   ----------------------------Set Interrupt Event  -------------------- **/

void GPIOInterruptEvent(uint32_t baseAddr ,
 							 uint8_t pinNumber ,
 							 uint32_t value )
{
	uint32_t regVal = HW_RD_REG32(baseAddr+GPIOIEV);
	if ((GPIO_INTERRUPT_LEVEL_HIGH||GPIO_INTERRUPT_EDGE_RISING) == value)
	{
		regVal|=(1<<pinNumber);
	}
	else if ((GPIO_INTERRUPT_EDGE_FALLING||GPIO_INTERRUPT_LEVEL_LOW) == value)
	{
		regVal&=~(1<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOIEV),regVal);
}


void GPIOInterruptGetMaskedStatus(uint32_t baseAddr ,
								  uint8_t pinNumber ,
								  uint32_t value )
{
	uint32_t regVal = HW_RD_REG32(baseAddr+GPIOMIS);
	if ((GPIO_INTERRUPT_LEVEL_HIGH||GPIO_INTERRUPT_EDGE_RISING) == value)
	{
		regVal|=(1<<pinNumber);
	}
	else if ((GPIO_INTERRUPT_EDGE_FALLING||GPIO_INTERRUPT_LEVEL_LOW) == value)
	{
		regVal&=~(1<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOIEV),regVal);
}

void GPIOInterruptEvent_field(uint32_t baseAddr ,
 							  		uint8_t mask ,
 							  		uint32_t value )
{
	HW_SET_REG32((baseAddr+GPIOIEV),value,mask);
}

/**   ----------------------------Set Interrupt Mask  -------------------- **/


void GPIOInterruptMask(uint32_t baseAddr ,
 							  uint8_t pinNumber ,
 							  uint32_t value )
{
	uint32_t regVal = HW_RD_REG32(baseAddr + GPIOIM) ;
	if (value == ENABLE)
	{
		regVal|=(1U<<pinNumber);
	}
	else
	{
		regVal &=~(1U<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOIM),regVal);
}

/**   ----------------------------read Interrupt Raw flage status  -------------------- **/

uint32_t GPIORawInterruptStatus(uint32_t baseAddr )
{
	return HW_RD_REG32((baseAddr+GPIORIS)) ;
}
/**   ----------------------------read Interrupt masked flage status  -------------------- **/


uint32_t GPIOMaskedInterruptStatus(uint32_t baseAddr)
{
	return HW_RD_REG32((baseAddr+GPIORIS));

}
/**   ----------------------------set Interrupt clear  -------------------- **/
void GPIOInterruptClear(uint32_t baseAddr ,
 							  uint8_t pinNumber ,
 							  uint32_t value )
{
	uint32_t regVal = HW_RD_REG32(baseAddr + GPIOICR) ;
	if (value == ENABLE)
	{
		regVal|=(1U<<pinNumber);
	}
	else
	{
		regVal &=~(1U<<pinNumber);
	}
	HW_WR_REG32((baseAddr+GPIOICR),regVal);
}



/**-------------------------------Set Context ----------------------------**/

void GPIOConfig(uint32_t baseAddr ,
				uint8_t pinNumber ,
				gpioPinCfg_t *pCtx)
{
	GPIOlockInit(baseAddr);
	GPIOCommit(baseAddr,pinNumber,pCtx->gpiocr) ;
	GPIOSetDirection(baseAddr,pinNumber,pCtx->gpiodir) ;
	GPIOAlternativeFunction(baseAddr,pinNumber,pCtx->gpioafsel);
	GPIODigitalEnable(baseAddr,pinNumber,pCtx->gpioden);
	GPIOAnalogModeSelect(baseAddr,pinNumber,pCtx->gpioamsel);
	GPIOCurrentVal( baseAddr , pinNumber , pCtx->currentVal );
	GPIOPortControl(baseAddr,pinNumber,pCtx->gpiopctl);
	//GPIOPinWrite(baseAddr,pinNumber,pCtx->gpiodata);
	if(pCtx->gpiodir == GPIO_DIRECTION_INPUT)
	{
		GPIOSetResistor(baseAddr,pinNumber,pCtx->resType);
	}
}

void GPIOIntConfig(uint32_t baseAddr ,
		uint8_t pinNumber ,
		gpioPinCfg_t *pCtx)
{
	GPIOPortControl(baseAddr,pinNumber,pCtx->gpiopctl);
	GPIOInterruptSense(baseAddr,pinNumber,pCtx->gpiois);
	GPIOInterruptBothEdges(baseAddr,pinNumber,pCtx->gpioibe);
	GPIOInterruptEvent(baseAddr,pinNumber,pCtx->gpioiev);
	GPIOInterruptMask(baseAddr,pinNumber,pCtx->gpioim);
	GPIOInterruptClear(baseAddr,pinNumber,pCtx->gpioicr);
}





