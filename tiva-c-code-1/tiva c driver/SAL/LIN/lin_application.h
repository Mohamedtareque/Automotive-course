/*
 * lin_application.h
 *
 *  Created on: Sep 3, 2017
 *      Author: Mohamed
 */

#ifndef SAL_LIN_LIN_APPLICATION_H_
#define SAL_LIN_LIN_APPLICATION_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "lin_protocol.h"

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
/*
 * description	     : this function set id and function which contain data to /
 * 							table
 * parm 	 	ptrf : pointer to function which has a pointer to array of chars
 * parm         pid  : Protected ID of message
 * return 			 : void
 *  */
void lin_set_data(void(*ptrf)(uint8_t *) , uint8_t pid ) ;

/*
 * description	    			 : this function set direction of node (RX or TX)
 * parm 			   direction : TX = 0  / RX = 1
 * parm   			        pid  : Protected ID of message
 * return 						 : void
 *  */
void lin_set_direction(linDir_t direction ,uint8_t pid);

void linInit();



#endif /* SAL_LIN_LIN_APPLICATION_H_ */
