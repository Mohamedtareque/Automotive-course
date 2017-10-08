/*
 * main.c
 */
#include"gpioapp/gpio_app.h"

int main(void) {
	/*----------------- RunTime Clock Gating Enable------------------------*/
	gModuleName_t module ;
	module.name = GPIO ;
	enableClockGating(&module , GPIO_PORT_F,ENABLE);
	enableClockGating(&module , GPIO_PORT_A,ENABLE);
	module.name = UART ;
	enableClockGating(&module , UART_module0 ,ENABLE);
	/*----------------- GPIO PORTF Configuration------------------------*/
	gpio_t gpio ;
	gpio.base = PORTF_BASE ;
	gpio.pinNum = pin1;
	gpio.digital =HIGH ;
	gpio.dir = OUTPUT ;
	GPIO_pinInit(&gpio);
	gpio.pinNum = pin2;
		gpio.digital =HIGH ;
		gpio.dir = OUTPUT ;
		GPIO_pinInit(&gpio);
		gpio.pinNum = pin3;
			gpio.digital =HIGH ;
			gpio.dir = OUTPUT ;
			GPIO_pinInit(&gpio);
	/*----------------- GPIO PORTA Configuration------------------------*/
	gpio.base = PORTA_BASE ;
	gpio.pinNum = pin0;
	gpio.alternative = HIGH ;
	gpio.pctl = 1;
	gpio.digital =HIGH ;
	GPIO_pinInit(&gpio);


	gpio.pinNum = pin1;
	gpio.alternative = HIGH ;
	gpio.digital =HIGH ;
	gpio.pctl = 1;
	GPIO_pinInit(&gpio);
	/*----------------- UART Configuration------------------------*/
	UART_inIt( UART0 , 9600 ) ;

	while(1)
	{
		//char input_char = UART_readChar(UART0);
		UART_sendChar(UART0, "H");
		UART_readChar(UART0);
		//UART_printString(UART0, "H");
		/*switch(input_char)
		{
		case'r':
			GPIOPinWrite(PORTF_BASE,pin1,HIGH);
			break ;
		case'b':
			GPIOPinWrite(PORTF_BASE,pin2,HIGH);
			break ;
		case'g':
			GPIOPinWrite(PORTF_BASE,pin3,HIGH);
			break ;
		default :
			GPIOPinWrite(PORTF_BASE,pin1,LOW);
			GPIOPinWrite(PORTF_BASE,pin2,LOW);
			GPIOPinWrite(PORTF_BASE,pin3,LOW);
		}*/
	}
	return 0;
}





