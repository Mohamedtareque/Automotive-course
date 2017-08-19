/*
 * gpio.c
 *
 *  Created on: Aug 7, 2017
 *      Author: Mohamed
 */


#include"gpio.h"
#include"RAL/system.h"
gpioerror_t rcgc_init(uint8_t port)
{
	RCGCGPIO |=(1<<port) ;
	return PASS;
}

gpioerror_t den_init(uint32_t base , uint8_t pin, uint8_t state)
{
	if(state == 1)
		(*(volatile uint32_t *)(base+GPIODEN)) |=(state<<pin );
	else if(state == 0)
		*(volatile uint32_t *)(base+GPIODEN) &=(state<<pin );
	return PASS;
}


gpioerror_t is_init(uint32_t base , uint8_t pin, uint8_t state)
{
	if(state == 1)
		(*(volatile uint32_t *)(base+GPIOIS)) |=(state<<pin );
	else if(state == 0)
		*(volatile uint32_t *)(base+GPIOIS) &=(state<<pin );
	return PASS;
}


gpioerror_t iBE_init(uint32_t base , uint8_t pin, uint8_t state)
{
	if(state == 1)
		(*(volatile uint32_t *)(base+GPIOIBE)) |=(state<<pin );
	else if(state == 0)
		*(volatile uint32_t *)(base+GPIOIBE) &=(state<<pin );
	return PASS;
}


gpioerror_t iEV_init(uint32_t base , uint8_t pin, uint8_t state)
{
	if(state == 1)
		(*(volatile uint32_t *)(base+GPIOIEV)) |=(state<<pin );
	else if(state == 0)
		*(volatile uint32_t *)(base+GPIOIEV) &=(state<<pin );
	return PASS;
}


gpioerror_t iM_init(uint32_t base , uint8_t pin, uint8_t state)
{
	if(state == 1)
		(*(volatile uint32_t *)(base+GPIOIM)) |=(state<<pin );
	else if(state == 0)
		*(volatile uint32_t *)(base+GPIOIM) &=(state<<pin );
	return PASS;
}



gpioerror_t dir_init(uint32_t base , uint8_t pin, uint8_t state)
{


	if(state == 1)
		*(volatile uint32_t *)(base+GPIODIR)|=state<<pin;
	else if(state == 0)
		*(volatile uint32_t *)(base+GPIODIR)&=~(1<<pin );
	return PASS;
}
gpioerror_t data_rw_init(uint32_t base , uint8_t pin, uint8_t state)
{
	if(state == 1)
		(*(volatile uint32_t *)(base+GPIODATA))|=(1<<pin );
	else if(state == 0)
		(*(volatile uint32_t *)(base+GPIODATA)) &=~(1<<pin );
	return PASS;
}

uint32_t data_rd_init(uint32_t base , uint8_t pin)
{

	return (((*(volatile uint32_t*)(base+GPIODATA))&=(1<<pin))>>pin);
}

gpioerror_t lock_init(uint32_t base)
{
	(*(volatile uint32_t *)(base+GPIOLOCK)) = 0x4C4F434B ;
	return PASS;
}

gpioerror_t commit_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIOCR)) |= 1<<pin ;
	return PASS;
}

gpioerror_t pur_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIOPUR)) |= 1<<pin ;
	return PASS;
}

gpioerror_t pdr_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIOPDR)) |= 1<<pin ;
	return PASS;
}
gpioerror_t odr_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIOODR)) |= 1<<pin ;
	return PASS;
}

gpioerror_t afsel_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIOAFSEL)) |= 1<<pin ;
	return PASS;
}

gpioerror_t pctl_init(uint32_t base , uint8_t pcm,uint8_t pin )//pcm from 0 to 7 , pin from 0 to 4
{
	pin = pcm*4 + pin ;
	(*(volatile uint32_t *)(base+GPIOPCTL)) |= 1<<pin ;
	return PASS;
}

gpioerror_t dr4r_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIODR4R)) |= 1<<pin ;
	return PASS;
}
gpioerror_t dr8r_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIODR8R)) |= 1<<pin ;
	return PASS;
}
gpioerror_t dr2r_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIODR2R)) |= 1<<pin ;
	return PASS;
}
gpioerror_t amsel_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIOAMSEL)) |= 1<<pin ;
	return PASS;
}
gpioerror_t adcctl_init(uint32_t base , uint8_t pin)
{
	(*(volatile uint32_t *)(base+GPIOADCCTL)) |= 1<<pin ;
	return PASS;
}

void systick_init(uint32_t val,uint32_t ctrl)
{
	uint32_t regVal_ctrl = (*((volatile uint32_t *)(SYSTICK_BASE+STCTRL)));
	uint32_t regVal =(*((volatile uint32_t *)(SYSTICK_BASE+STRELOAD)));
	regVal_ctrl |= ctrl;
	regVal |= val ;
}


gpioerror_t INT_SET_ENABLE( uint8_t enx ,uint8_t pin )//pcm from 0 to 7 , pin from 0 to 4
{
	pin = enx*31 + pin ;
	(*(volatile uint32_t *)(NVIC_BASE+ISENABLE)) |= 1<<pin ;
	return PASS;
}

gpioerror_t INT_CLEAR_ENABLE( uint8_t enx ,uint8_t pin )//pcm from 0 to 7 , pin from 0 to 4
{
	pin = enx*31 + pin ;
	(*(volatile uint32_t *)(NVIC_BASE+ICENABLE)) |= 1<<pin ;
	return PASS;
}


gpioerror_t INT_SET_PENDING( uint8_t enx ,uint8_t pin )//pcm from 0 to 7 , pin from 0 to 4
{
	pin = enx*31 + pin ;
	(*(volatile uint32_t *)(NVIC_BASE+ISPENDING)) |= 1<<pin ;
	return PASS;
}


gpioerror_t INT_CLEAR_PENDING( uint8_t enx ,uint8_t pin )//pcm from 0 to 7 , pin from 0 to 4
{
	pin = enx*31 + pin ;
	(*(volatile uint32_t *)(NVIC_BASE+ICPENDING)) |= 1<<pin ;
	return PASS;
}


gpioerror_t INT_ACTIVE_BIT( uint8_t enx ,uint8_t pin )//pcm from 0 to 7 , pin from 0 to 4
{
	pin = enx*31 + pin ;
	(*(volatile uint32_t *)(NVIC_BASE+IABIT)) |= 1<<pin ;
	return PASS;
}






