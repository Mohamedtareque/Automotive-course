/*
 * hw_types.h
 *
 *  Created on: Aug 17, 2017
 *      Author: Mohamed
 */

#ifndef HW_TYPES_H_
#define HW_TYPES_H_
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                           Structures and Enums                             */
/* ========================================================================== */


/* ========================================================================== */
/*                           Variables Declarations                           */
/* ========================================================================== */




/* ========================================================================== */
/*                           Function Declarations                            */
/* ========================================================================== */
static inline uint32_t HW_RD_REG32(uint32_t addr);

static inline uint32_t HW_WR_REG32(uint32_t addr,
								   uint32_t value);

static inline uint32_t HW_SET_REG32(uint32_t addr,
									uint32_t value,
									uint32_t mask);
/* ========================================================================== */
/*                           Static Function Definitions                      */
/* ========================================================================== */
static inline uint32_t HW_RD_REG32(uint32_t addr)
{
	//uint32_t regVal = (*((volatile uint32_t *) addr)) ;
	return (*((volatile uint32_t *) addr)) ;
	//return regVal ;
}

static inline uint32_t HW_WR_REG32(uint32_t addr,uint32_t value )
{
	//uint32_t regVal = (*((volatile uint32_t *) addr)) ;
	(*((volatile uint32_t *) addr)) = value ;
	//regVal = value ;
	return 0;
}


static inline uint32_t HW_SET_REG32(uint32_t addr,uint32_t value , uint32_t mask )
{
	uint32_t regVal = (*((volatile uint32_t *) addr)) ;
	regVal &= ~(mask);
	regVal |=  value ;
	return 0;
}



#endif
