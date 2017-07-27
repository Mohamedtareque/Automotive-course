#ifndef 		DIO_H
#define 		DIO_H 

typedef enum DIRDIO
{
	INPUT = 0 , OUTPUT = 1
}gDIRDIO_t;

typedef enum STATDIO
{
	HIGH = 1 , LOW = 0 
}gSTATDIO_t;

typedef struct objdio
{
	gDIRDIO_t dir ;
	uint8_t pin ;
	uint8_t base ;
}OBJDIO_t;

typedef unsigned char uint8_t ;
typedef unsigned int uint16_t ;
typedef unsigned double uint32_t ;

#define SET_REG8_BIT (reg,pin) *(volatile uint8_t*) reg |=1 << pin
#define SET_REG16_BIT(reg,pin) *(volatile uint16_t*)reg |=1 << pin 

#define BASE_A 0x39
#define BASE_B 0x36
#define BASE_C 0x33
#define BASE_D 0x30

#define INPUT_OFFSET 0x00
#define DIR_OFFSET 	 0x01
#define PORT_OFFSET  0x02

void init_dio_pin(OBJDIO_t *);

#endif
