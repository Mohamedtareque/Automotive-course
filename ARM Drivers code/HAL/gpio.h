/*
 * gpio.h
 *
 *  Created on: Aug 7, 2017
 *      Author: Mohamed
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_
#include"RAL/hw_gpio.h"

typedef enum
{
    PASS,

} gpioerror_t;

typedef enum
{
	INPUT ,
	OUTPUT
}gpio_dir_status;

typedef enum
{
	LOW ,
	HIGH
}gpio_data_status;

typedef enum
{
    PULL_UP, PULL_DOWN, OPENDRAIN
} restype_t;

typedef enum
{
    CURRENT_2MA, CURRENT_4MA, CURRENT_8MA
} currentval_t;

gpioerror_t rcgc_init(uint8_t port);
gpioerror_t den_init(uint32_t base , uint8_t pin, uint8_t state) ;
gpioerror_t dir_init(uint32_t base , uint8_t pin, uint8_t state) ;
gpioerror_t data_rw_init(uint32_t base , uint8_t pin, uint8_t state) ;
gpioerror_t commit_init(uint32_t base , uint8_t pin) ;
gpioerror_t lock_init(uint32_t base) ;
uint32_t data_rd_init(uint32_t base , uint8_t pin);
gpioerror_t pur_init(uint32_t base , uint8_t pin);
gpioerror_t pdr_init(uint32_t base , uint8_t pin);
gpioerror_t odr_init(uint32_t base , uint8_t pin);
gpioerror_t afsel_init(uint32_t base , uint8_t pin) ;
gpioerror_t pctl_init(uint32_t base , uint8_t pcm,uint8_t pin );
gpioerror_t dr4r_init(uint32_t base , uint8_t pin);
gpioerror_t dr8r_init(uint32_t base , uint8_t pin);
gpioerror_t dr2r_init(uint32_t base , uint8_t pin);
gpioerror_t amsel_init(uint32_t base , uint8_t pin);
gpioerror_t adcctl_init(uint32_t base , uint8_t pin);

#endif /* HAL_GPIO_H_ */
