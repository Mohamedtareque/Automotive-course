/*
 * gpio.h
 *
 *  Created on: Aug 17, 2017
 *      Author: Mohamed
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "../HAL/hw_gpio.h"
#include "../HAL/system.h"
#include "../HAL/types.h"
#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/****************************************************************************************************
* Field Definition pins Macros
****************************************************************************************************/
#define 					pin0                   0
#define 					pin1               	   1
#define 					pin2                   2
#define 					pin3                   3
#define 					pin4                   4
#define 					pin5                   5
#define 					pin6                   6




/* ========================================================================== */
/*                           Structures and Enums                             */
/* ========================================================================== */

typedef enum intpri
{
	INTA  = 0 ,INTB,INTC,INTD ,
	PRIO0 = 0 ,
	PRIO1 ,
	PRIO2 ,
	PRIO3 ,
	PRIO4 ,
	PRIO5 ,
	PRIO6 ,
	PRIO7 ,
	PRIO8 ,
	PRIO9 ,
	PRIO10 ,
	PRIO11 ,
	PRIO12 ,
	PRIO13 ,
	PRIO14 ,
	PRIO15 ,
	PRIO16 ,
	PRIO17 ,
	PRIO18 ,
	PRIO19 ,
	PRIO20 ,
	PRIO21 ,
	PRIO22 ,
	PRIO23 ,
	PRIO24 ,
	PRIO25 ,
	PRIO26 ,
	PRIO27 ,
	PRIO28 ,
	PRIO29 ,
	PRIO30 ,
	PRIO31 ,
	PRIO32 ,
	PRIO33 ,
	PRIO34 ,

}intPri_t;




typedef enum gpioDirection
{
	 INPUT    ,
	 GPIO_DIRECTION_INPUT = 0 ,

 	/**< Input pin. */
	 GPIO_DIRECTION_OUTPUT  ,
	 OUTPUT = 1 ,
	/**< Output pin. */
}gpioDirection_t;

typedef enum gpioOutput
{
	GPIO_OUTPUT_LOW = LOW ,
	/** \brief GPIO pin is at logic low.*/
	GPIO_OUTPUT_HIGH = HIGH,
	/** \brief GPIO pin is at logic high.*/
}gpioOutput_t;



typedef enum gpioEnable
{
	ENABLE = 1 , enable = 1 , Enable = 1,
	/** \brief GPIO pin is at logic low.*/
	DISABLE = 0 , Disable = 0 , disable = 0
	/** \brief GPIO pin is at logic high.*/
}gpioEnable_t;



typedef enum gpioDigitalEn
{
	GPIO_DIGITAL_LOW ,
	/** \brief GPIO pin is at logic low.*/
	GPIO_DIGITAL_HIGH ,
	/** \brief GPIO pin is at logic high.*/
}gpioDigitalEn_t;


typedef enum gpioPort
{
	PORTA , porta =0 , PA =0 , pa =0 ,
	PORTB , portb =1 , PB =1 , pb =1 ,
	PORTC , portc =2 , PC =2 , pc =2 ,
	PORTD , portd =3 , PD =3 , pd =3 ,
	PORTE , porte =4 , PE =4 , pe =4 ,
	PORTF , portf =5 , PF =5 , pf =5 ,
}gpioPort_t;


typedef enum gpioPcm
{
	pcm0 , PCM0 =0 ,
	pcm1 , PCM1 =1 ,
	pcm2 , PCM2 =2 ,
	pcm3 , PCM3 =3 ,
	pcm4 , PCM4 =4 ,
	pcm5 , PCM5 =5 ,
	pcm6 , PCM6 =6 ,
}gpioPcm_t;


/** \brief Enumerates the possible GPIO Resistor type . */
typedef enum restype
{
	PULLUP , PULLDOWN , OPENDRAIN
}gpioResType_t;

/** \brief Enumerates the possible GPIO Current Value  . */

typedef enum currentval
{
	CURRENT_2MA , CURRENT_4MA , CURRENT_8MA
}gpioCurrentVal_t;

/** \brief Enumerates the possible GPIO Interrupt Sens  . */

typedef enum intSens
{
	GPIO_INTERRUPT_EDGE ,EGDE= 0,
	GPIO_INTERRUPT_LEVEL ,LEVEL = 1 ,
}gpioIntSens_t;

/** \brief Enumerates the possible GPIO Interrupt Both Edges . */

typedef enum intIbe
{
	GPIO_INTERRUPT_EVENT   ,
	GPIO_INTERRUPT_SINGLE_EDGE = 0 ,
	GPIO_INTERRUPT_BOTH_EDGES
}gpioIntIbe_t;

/** \brief Enumerates the possible GPIO Interrupt Event type . */

typedef enum intIev
{
	GPIO_INTERRUPT_EDGE_FALLING ,
	GPIO_INTERRUPT_LEVEL_LOW =0  ,
	GPIO_INTERRUPT_EDGE_RISING  ,
	GPIO_INTERRUPT_LEVEL_HIGH= 1
}gpioIntIev_t;

/** \brief Enumerates the possible GPIO Interrupt Masked pin . */

typedef enum intIm
{
	MASKED , UNMASKED
}gpioIntIm_t;

/** \brief Enumerates the possible GPIO Interrupt  Clear . */

typedef enum intClear
{
	CLEAR = 1
}gpioIntClear_t;

typedef struct gpioConfig
{
    gpioDirection_t gpiodir;
    /**< GPIO direction control register value. */
    //gpioOutput_t gpiodata;
    /**< GPIO pin value register. */
    gpioResType_t resType ;
    /**< GPIO PUR / PDR  value register. */
    gpioGeneralStatus_t gpioodr;
    /**< GPIO open drain  value register. */
    gpioIntSens_t gpiois;
    /**< GPIO interrupt sense value register. */
    gpioIntIbe_t gpioibe;
    /**< GPIO interrupt both edges value register. */
    gpioIntIev_t gpioiev;
    /**< GPIO interrupt event value register. */
    gpioIntIm_t gpioim;
    /**< GPIO interrupt mask value register. */
    uint8_t gpioris;
    /**< GPIO raw interrupt status value register. */
    uint8_t gpiomis;
    /**< GPIO masked interrupt status value register. */
    gpioIntClear_t gpioicr;
    /**< GPIO interrupt clear value register. */
    gpioGeneralStatus_t gpioafsel;
    /**< GPIO alternative function select value register. */
    gpioCurrentVal_t currentVal ;
    /**< GPIO 2-mA , 4-mA , 8-mA value register. */
    gpioGeneralStatus_t gpioslr;
    /**< GPIO slew rate value register. */
    gpioEnable_t gpioden;
    /**< GPIO digital enable value register. */
    uint32_t gpiolock;
    /**< GPIO lock value register. */
    gpioGeneralStatus_t gpiocr;
    /**< GPIO commit value register. */
    gpioGeneralStatus_t gpioamsel;
    /**< GPIO analog mode select value register. */
    gpioGeneralStatus_t gpiopctl;
    /**< GPIO port control value register. */
    gpioGeneralStatus_t gpioadcctl;
    /**< GPIO analog digital converter control value register. */
    gpioGeneralStatus_t damctl;
    /**< GPIO direct acceses memory control value register. */
}gpioPinCfg_t;


/* ========================================================================== */
/*                           Variables Declarations                           */
/* ========================================================================== */

/*   None  */

/* ========================================================================== */
/*                           Function Declarations                            */
/* ========================================================================== */


/**
 * \brief  This API configures the direction of a specified GPIO pin as being
 *         either input or output.
 *
 * \param  baseAddr      The memory address of the GPIO instance being used GPIODIR.
 * \param  pinNumber     The number of the pin in the GPIO instance.
 *         'pinNumber' can take one of the following values:
 *         (0 <= pinNumber <= 7).
 * \param  pinDirection  The required direction for the GPIO pin.
 *         pinDirection' can take one of the value from the following enum:
 *         - #gpioDirection_t.
 */
void GPIOSetDirection(uint32_t baseAddr,
                uint32_t pinNumber,
                uint32_t pinDirection);
// field maskable version
void GPIOSetDirection_field(uint32_t baseAddr,
                	  uint32_t mask,
                	  uint32_t value);
/**
 * \brief  This API drives an output GPIO pin to a logic HIGH or a logic LOW
 *         state.
 *
 * \param  baseAddr    The memory address of the GPIO instance being used GPIODATA .
 * \param  pinNumber   The number of the pin in the GPIO instance
 *         'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7).
 * \param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
void GPIOPinWrite(uint32_t baseAddr,
                  uint32_t pinNumber,
                  uint32_t pinValue);
// field maskable version
void GPIOPinWrite_field(uint32_t baseAddr,
                  		uint32_t mask,
                  		uint32_t value);
/**
 * \brief   This API determines the logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *
 * \retval  LOW  - indicating to drive a logic LOW(0) on the pin.
 * \retval  HIGH - indicating to drive a logic HIGH(1) on the pin.
 */
uint8_t GPIOPinRead(uint32_t baseAddr,
					 uint32_t pinNumber);

/**
 * \brief   This API determines the clock on  a specified
 *          GPIO port .
 *
 * \param   baseAddr   The number of the port in the GPIO instance
 *          'port' can take one of the following values:
 *          (0 <= pinNumber <= 5)
 *
 */
void GPIOlockInit(uint32_t baseAddr) ;
/**
 * \brief  This API drives an digital enable GPIO pin to a logic HIGH or a logic LOW
 *         state.
 *
 * \param  baseAddr    The memory address of the GPIO instance being used GPIODEN .
 * \param  pinNumber   The number of the pin in the GPIO instance
 *         'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7).
 * \param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
void GPIODigitalEnable(uint32_t baseAddr ,
						   uint8_t pinNumber,
						   uint8_t pinValue) ;
// field maskable version
void GPIODigitalEnable_field(uint32_t baseAddr ,
						   	     uint8_t mask,
						   		 uint8_t value) ;
/**
 * \brief  This API determines GPIOCR to be unlocked with value
 *			0x4C4F434B
 *
 * \param  baseAddr    The memory address of the GPIO instance being used GPIODATA .
 *
 * \ note : reading the GPIOLOCK register returns 0x00000001.
 *			When write accesses are enabled, or unlocked,
 *			reading the GPIOLOCK register returns 0x00000000.
 */
void GPIOLock(uint32_t baseAddr) ;
/**
 * \brief   This API determines the logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOCR
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
 void GPIOCommit(uint32_t baseAddr ,
 			     uint8_t pinNumber ,
 				 uint32_t pinValue );
// field maskable version
 void GPIOCommit_field(uint32_t baseAddr ,
 					   uint8_t mask ,
 					   uint32_t value );


 /**
  * \brief   This API determines the logic level(value) on a specified
  *          GPIO pin.
  *
  * \param   baseAddr    The memory address of the GPIO instance being used GPIOPUR
  * \param   pinNumber   The number of the pin in the GPIO instance
  *          'pinNumber' can take one of the following values:
  *          (0 <= pinNumber <= 7)
  *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
  *         should be driven on the output pin.
  *         'pinValue' can take one of the value from the following enum:
  *         - #gpioOutput_t. (HIGH or LOW)
  */

 void GPIOSetCurrentVal(uint32_t baseAddr ,
 			     	 uint8_t pinNumber ,
					 uint32_t pinValue );
/**
 * \brief   This API determines the logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOPUR
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
void GPIOPullUpResistor(uint32_t baseAddr ,
 					    uint8_t pinNumber ,
 						uint32_t pinValue );
// field maskable version
void GPIOPullUpResistor_field(uint32_t baseAddr ,
 							  uint8_t mask ,
 							  uint32_t value );
 /**
 * \brief   This API determines the logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOPDR
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  void GPIOPullDownResistor(uint32_t baseAddr ,
 							uint8_t pinNumber ,
 							uint32_t pinValue );
  // field maskable version
  void GPIOPullDownResistor_field(uint32_t baseAddr ,
 							 	  uint8_t mask ,
 							 	  uint32_t value );

  void GPIOSetResistor(uint32_t baseAddr ,
					   uint8_t pinNumber ,
					   uint8_t resType) ;
  /**
 * \brief   This API determines the logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOODR
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  void GPIOOpenDrain(uint32_t baseAddr ,
 						 uint8_t pinNumber ,
 						 uint32_t pinValue );
  // field maskable version
  void GPIOOpenDrain_field(uint32_t baseAddr ,
 							   uint8_t mask ,
 							   uint32_t value );
 /**
 * \brief   This API determines the logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOAFSEL
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  void GPIOAlternativeFunction(uint32_t baseAddr ,
 							   uint8_t pinNumber ,
 							   uint32_t pinValue );
  // field maskable version
  void GPIOAlternativeFunction_field(uint32_t baseAddr ,
 									 uint8_t mask ,
 									 uint32_t value );
   /**
 * \brief   This API determines the logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOPCTL
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 3)
 * \param   pcm   The number of the Port Control Mux in the GPIOPCTL instance
 *          'pcm' can take one of the following values:
 *          (0 <= pcm <= 7)
  *         'pcm' can take one of the value from the following enum:
 *         - #gpioPcm_t. (0 to 7)
 */
  void GPIOPortControl(uint32_t baseAddr ,
 					   uint8_t pcm ,
 					   uint32_t pinNumber );
/**
 * \brief   This API determines the logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOAMSEL
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  void GPIOAnalogModeSelect(uint32_t baseAddr ,
 							uint8_t pinNumber ,
 							uint32_t pinValue );
  // field maskable version
  void GPIOAnalogModeSelect_field(uint32_t baseAddr ,
 								  uint8_t mask ,
 								  uint32_t value );

/**
 * \brief   This API determines the sensetive of interrupt(Level -Edge) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOIS
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  void GPIOInterruptSense(uint32_t baseAddr ,
 						  uint8_t pinNumber ,
 						  uint32_t value );


  void GPIOInterruptSense_field(uint32_t baseAddr ,
 							  	uint8_t mask ,
 							  	uint32_t value );

/**
 * \brief   This API determines the sensetive of interrupt(Level -Edge) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOIS
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  void GPIOInterruptBothEdges(uint32_t baseAddr ,
 							  uint8_t pinNumber ,
 							  uint32_t value );


  void GPIOInterruptBothEdges_field(uint32_t baseAddr ,
 							  	    uint8_t mask ,
 							  	  	uint32_t value );

/**
 * \brief   This API determines the sensetive of interrupt(Level -Edge) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOIS
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  void GPIOInterruptEvent(uint32_t baseAddr ,
 						  uint8_t pinNumber ,
 						  uint32_t value );

  void GPIOInterruptEvent_field(uint32_t baseAddr ,
 							    uint8_t mask ,
 							  	uint32_t value );

/**
 * \brief   This API determines the sensetive of interrupt(Level -Edge) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOIS
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  void GPIOInterruptMask(uint32_t baseAddr ,
 						 uint8_t pinNumber ,
 						 uint32_t value );
  /**
 * \brief   This API determines the sensetive of interrupt(Level -Edge) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOIS
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  uint32_t GPIORawInterruptStatus(uint32_t baseAddr);

  /**
 * \brief   This API determines the sensetive of interrupt(Level -Edge) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOIS
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  uint32_t GPIOMaskedInterruptStatus(uint32_t baseAddr );

  /**
 * \brief   This API determines the sensetive of interrupt(Level -Edge) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOIS
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the value from the following enum:
 *         - #gpioOutput_t. (HIGH or LOW)
 */
  void GPIOInterruptClear(uint32_t baseAddr ,
 						  uint8_t pinNumber ,
 						  uint32_t value );


 uint32_t GPIOMaskedInterruptStatus(uint32_t baseAddr) ;

  /**
 * \brief   This API configure all functions on port  on a specified
 *          GPIO pin.
 * \param   baseAddr    The memory address of the GPIO instance being used GPIOIS
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 7)
 *\param  pCfg    This is a pointer to config_t struct whether determine reg
 * 						which i work with
 */
void GPIOConfig(uint32_t baseAddr ,
				uint8_t pinNumber ,
				gpioPinCfg_t *pGpioPinCfg) ;
void GPIOIntConfig(uint32_t baseAddr ,
				   uint8_t pinNumber ,
				   gpioPinCfg_t *pCtx) ;
/* ========================================================================== */
/*                           Static Function Definitions                      */
/* ========================================================================== */
/*   None  */

#endif
