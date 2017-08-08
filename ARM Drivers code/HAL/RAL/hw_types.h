/*
 * hw_types.h
 *
 *  Created on: Aug 8, 2017
 *      Author: Mohamed
 */
#if 0
#ifndef HAL_RAL_HW_TYPES_H_
#define HAL_RAL_HW_TYPES_H_

#define WRITE_REG_32BIT (add,value) (*((volatile uint32_t *)add))=value
#define READ_REG_32BIT (add) (*((volatile uint32_t *)add))


void WRITE_HW_BIT(uint32_t add,pin , value)
{
	if(value==1)
	{
		READ_REG_32BIT(add) |= value <<
	}
}

#endif /* HAL_RAL_HW_TYPES_H_ */
