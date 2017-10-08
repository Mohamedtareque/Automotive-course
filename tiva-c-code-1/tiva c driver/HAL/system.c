/*
 * system.c
 *
 *  Created on: Aug 17, 2017
 *      Author: Mohamed
 */

#include"../HAL/system.h"
#include"../HAL/hw_gpio.h"
#include"../HAL/gpio.h"
#include"../HAL/types.h"
#include"../HAL/hw_types.h"
#include"../HAL/timer.h"
void enableClockGating(gModuleName_t *obj ,
					   uint8_t module_num ,
					   uint8_t Enable_Disable )
{
	switch (obj->name) {
		case WDT:

			    if ((module_num==0)||(module_num==1))
			    {
			    	//uint32_t regVal = HW_RD_REG32(RCGCWD);
					if (Enable_Disable==1 )
					{
						RCGCWD |= (1U << module_num ) ;
						//HW_WR_REG32((RCGCWD),regVal);
					}
					else if(Enable_Disable==0)
					{
						RCGCWD &=~ (1U << module_num ) ;
						//HW_WR_REG32((RCGCWD),regVal);
					}

			    }
			break;
		case GPT:

			    if (module_num<6)
			    {
			    	//uint32_t regVal = HW_RD_REG32(RCGCTIMER);
			    	if (Enable_Disable==1 )
					{
			    		RCGCTIMER |= (1U << module_num ) ;
						//HW_WR_REG32((RCGCTIMER),regVal);
					}
					else if(Enable_Disable==0)
					{
						RCGCTIMER &=~ (1U << module_num ) ;
						//HW_WR_REG32((RCGCTIMER),regVal);
					}

				}
			break;

		case GPIO:

			    if (module_num<6)
			    {
			    	//uint32_t regVal = HW_RD_REG32(RCGCGPIO);
			    	if (Enable_Disable==1 )
					{
			    		RCGCGPIO |= (1 << module_num ) ;
						//HW_WR_REG32((RCGCGPIO),regVal);
					}
					else if(Enable_Disable==0)
					{
						RCGCGPIO &=~ (1 << module_num ) ;
						//HW_WR_REG32((RCGCGPIO),regVal);
					}
				}
			break;
		case DMA:

			    if (module_num==0) {
			    	uint32_t regVal = HW_RD_REG32(RCGCDMA);
			    	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCDMA),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCDMA),regVal);
					}
				}
			break;
		case Hibernation:

			    if (module_num==0)
			    {
			    	uint32_t regVal = HW_RD_REG32(RCGCHIB);
			    	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCHIB),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCHIB),regVal);
					}
				}
			break;
		case UART:

			    if (module_num<8)
			    {
			    	//uint32_t regVal = HW_RD_REG32(RCGCUART);
			    	if (Enable_Disable==1 )
					{
			    		RCGCUART |= (1U << module_num ) ;
						//HW_WR_REG32((RCGCUART),regVal);
					}
					else if(Enable_Disable==0)
					{
						RCGCUART &=~ (1U << module_num ) ;
						//HW_WR_REG32((RCGCUART),regVal);
					}
				}
			break;
		case SSI:

			    if (module_num<4) {
			    	uint32_t regVal = HW_RD_REG32(RCGCSSI);
			    	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCSSI),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCSSI),regVal);
					}
				}
			break;
		case I2C:

			    if (module_num<4)
			    {
			    	uint32_t regVal = HW_RD_REG32(RCGCI2C);
			    	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCI2C),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCI2C),regVal);
					}
				}
			break;
		case USB:

			    if (module_num==0)
			    {
			    	uint32_t regVal = HW_RD_REG32(RCGCUSB);
			    	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCUSB),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCUSB),regVal);
					}
				}
			break;
		case CAN:

			    if ((module_num==0)||(module_num==1))
			    {
			    	uint32_t regVal = HW_RD_REG32(RCGCCAN);
			    	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCCAN),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCCAN),regVal);
					}
				}
			break;
		case ADC:

			      if ((module_num==0)||(module_num==1)) {
			    	  uint32_t regVal = HW_RD_REG32(RCGCADC);
			      	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCADC),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCADC),regVal);
					}
				}
			break;
		case ACMP:

			    if (module_num==0) {
			    	uint32_t regVal = HW_RD_REG32(RCGCACMP);
			      	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCACMP),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCACMP),regVal);
					}
				}
			break;
		case PWM:

			    if ((module_num==0)||(module_num==1)) {
			    	uint32_t regVal = HW_RD_REG32(RCGCPWM);
			      	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCPWM),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCPWM),regVal);
					}
				}
			break;
		case QEI:

			    if ((module_num==0)||(module_num==1)) {
			    	uint32_t regVal = HW_RD_REG32(RCGCQEI);
			      	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCQEI),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCQEI),regVal);
					}
				}
			break;
		case EEPROM:

			      if (module_num==0) {
			    	  uint32_t regVal = HW_RD_REG32(RCGCEEPROM);
			      	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCEEPROM),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCEEPROM),regVal);
					}
				}
			break;
		case WTIMER:

			    if (module_num<6)
			      {
			    	uint32_t regVal = HW_RD_REG32(RCGCWTIMER);
			      	if (Enable_Disable==1 )
					{
						regVal |= (1U << module_num ) ;
						HW_WR_REG32((RCGCWTIMER),regVal);
					}
					else if(Enable_Disable==0)
					{
						regVal &=~ (1U << module_num ) ;
						HW_WR_REG32((RCGCWTIMER),regVal);
					}
			break;
			}
		default:
			break;
		}
}



uint8_t ISReady(gModuleName_t *obj, uint8_t module_num )
{
	switch (obj->name) {
		case WDT:
			    if ((module_num==0)||(module_num==1))
			    {
					return(HW_RD_REG32(PRWD));
				}
			break;
		case GPT:
			      if (module_num<6) {
			    	  return(HW_RD_REG32(PRTIMER));
					}
			break;

		case GPIO:
			      if (module_num<6) {
			    	  return(HW_RD_REG32(PRGPIO));
			    	}
			break;
		case DMA:
			      if (module_num==0) {
			    	  return(HW_RD_REG32(PRDMA));
			    	}
			break;
		case Hibernation:
			      if (module_num==0) {
			    	  return(HW_RD_REG32(PRHIB));
			    	}
			break;
		case UART:
			      if (module_num<8) {
			    	  return(HW_RD_REG32(PRUART));
					}
			break;
		case SSI:
			      if (module_num<4) {
			    	  return(HW_RD_REG32(PRSSI));
			    	}
			break;
		case I2C:
			      if (module_num<4) {
			    	  return(HW_RD_REG32(PRI2C));
			    	}
			break;
		case USB:
			      if (module_num==0) {
			    	  return(HW_RD_REG32(PRUSB));
			    	}
			break;
		case CAN:
			      if ((module_num==0)||(module_num==1)) {
			    	  return(HW_RD_REG32(PRCAN));
			    	};
			break;
		case ADC:
			      if ((module_num==0)||(module_num==1)) {
			    	  return(HW_RD_REG32(PRADC));
			    	}
			break;
		case ACMP:
			      if (module_num==0) {
				    	  return(HW_RD_REG32(PRACMP));
			    	}
			break;
		case PWM:
			      if ((module_num==0)||(module_num==1)) {
				    	  return(HW_RD_REG32(PRPWM));
			    	}
			break;
		case QEI:
			      if ((module_num==0)||(module_num==1)) {
				    	  return(HW_RD_REG32(PRQEI));
			    	}
			break;
		case EEPROM:
			      if (module_num==0) {
				    	  return(HW_RD_REG32(PREEPROM));
			    	}
			break;
		case WTIMER:
			      if (module_num<6) {
				    	  return(HW_RD_REG32(PRWTIMER));
			    	}
			break;

		default:
			break;
	}
	return 0 ;
}

void NVIC_EnableIRQ(g_IRQn_t  IRQn)
{
	if( IRQn <= 31 )
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICEN0);
		regVal |= (1U<<IRQn);
		HW_WR_REG32(CORE_PRE_BASE+NVICEN0,regVal);
	}else if( (IRQn >= 32) && (IRQn <= 63))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICEN1);
		regVal |= (1U<<(IRQn-32));
		HW_WR_REG32(CORE_PRE_BASE+NVICEN1,regVal);
	}else if( (IRQn >= 64) && (IRQn <= 95))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICEN2);
		regVal |= (1U<<(IRQn-64));
		HW_WR_REG32(CORE_PRE_BASE+NVICEN2,regVal);
	}else if( (IRQn >= 96) && (IRQn <= 127))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICEN3);
		regVal |= (1U<<(IRQn-96));
		HW_WR_REG32(CORE_PRE_BASE+NVICEN3,regVal);
	}else if( (IRQn >= 128) && (IRQn <= 138))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICEN4);
		regVal |= (1U<<(IRQn-128));
		HW_WR_REG32(CORE_PRE_BASE+NVICEN4,regVal);
	}
}

void NVIC_DisableIRQ(g_IRQn_t  IRQn)
{
	if( IRQn <= 31 )
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICDIS0);
		regVal &=~ (1U<<IRQn);
		HW_WR_REG32(CORE_PRE_BASE+NVICDIS0,regVal);
	}else if( (IRQn >= 32) && (IRQn <= 63))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICDIS1);
		regVal &=~(1U<<(IRQn-32));
		HW_WR_REG32(CORE_PRE_BASE+NVICDIS1,regVal);
	}else if( (IRQn >= 64) && (IRQn <= 95))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICDIS2);
		regVal &=~ (1U<<(IRQn-64));
		HW_WR_REG32(CORE_PRE_BASE+NVICDIS2,regVal);
	}else if( (IRQn >= 96) && (IRQn <= 127))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICDIS3);
		regVal &=~ (1U<<(IRQn-96));
		HW_WR_REG32(CORE_PRE_BASE+NVICDIS3,regVal);
	}else if( (IRQn >= 128) && (IRQn <= 138))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICDIS4);
		regVal &=~(1U<<(IRQn-128));
		HW_WR_REG32(CORE_PRE_BASE+NVICDIS4,regVal);
	}
}

uint32_t NVIC_GetPendingIRQ(g_IRQn_t  IRQn)
{
 	if( IRQn <= 31 )
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICPEN0);

	}else if( (IRQn >= 32) && (IRQn <= 63))
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICPEN1);
	}else if( (IRQn >= 64) && (IRQn <= 95))
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICPEN2);
	}else if( (IRQn >= 96) && (IRQn <= 127))
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICPEN3);
	}else if( (IRQn >= 128) && (IRQn <= 138))
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICPEN4);
	}
 	return 0 ;
}
void NVIC_SetPendingIRQ(g_IRQn_t  IRQn)
{
	if( IRQn <= 31 )
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN0);
		regVal |= (1U<<IRQn);
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN0,regVal);
	}else if( (IRQn >= 32) && (IRQn <= 63))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN1);
		regVal |= (1U<<(IRQn-32));
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN1,regVal);
	}else if( (IRQn >= 64) && (IRQn <= 95))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN2);
		regVal |= (1U<<(IRQn-64));
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN2,regVal);
	}else if( (IRQn >= 96) && (IRQn <= 127))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN3);
		regVal |= (1U<<(IRQn-96));
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN3,regVal);
	}else if( (IRQn >= 128) && (IRQn <= 138))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN4);
		regVal |= (1U<<(IRQn-128));
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN4,regVal);
	}
}

void NVIC_ClearPendingIRQ(g_IRQn_t  IRQn)
{
	if( IRQn <= 31 )
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN0);
		regVal &=~ (1U<<IRQn);
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN0,regVal);
	}else if( (IRQn >= 32) && (IRQn <= 63))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN1);
		regVal &=~ (1U<<(IRQn-32));
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN1,regVal);
	}else if( (IRQn >= 64) && (IRQn <= 95))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN2);
		regVal &=~ (1U<<(IRQn-64));
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN2,regVal);
	}else if( (IRQn >= 96) && (IRQn <= 127))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN3);
		regVal &=~ (1U<<(IRQn-96));
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN3,regVal);
	}else if( (IRQn >= 128) && (IRQn <= 138))
	{
		uint32_t regVal = HW_RD_REG32(CORE_PRE_BASE+NVICPEN4);
		regVal &=~ (1U<<(IRQn-128));
		HW_WR_REG32(CORE_PRE_BASE+NVICPEN4,regVal);
	}
}

uint32_t NVIC_GetActive(g_IRQn_t  IRQn)
{
	if( IRQn <= 31 )
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICACTIVE0);

	}else if( (IRQn >= 32) && (IRQn <= 63))
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICACTIVE1);
	}else if( (IRQn >= 64) && (IRQn <= 95))
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICACTIVE2);
	}else if( (IRQn >= 96) && (IRQn <= 127))
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICACTIVE3);
	}else if( (IRQn >= 128) && (IRQn <= 138))
	{
		return HW_RD_REG32(CORE_PRE_BASE+NVICACTIVE4);
	}
	return 0 ;
}

void NVIC_SetPriority(g_IRQn_t  IRQn, uint8_t priority)
{
	if(IRQn < 4 && IRQn >= 0)
	{
		uint32_t regVal =  HW_RD_REG32(CORE_PRE_BASE+NVICPRI0);
		if(IRQn == (INTA+PRIO0))
		{
			regVal |=(priority<<5);
			HW_WR_REG32((CORE_PRE_BASE+NVICPRI0),regVal);
		}
		else if(IRQn == (INTB+PRIO0))
		{
			regVal |=(priority<<13);
			HW_WR_REG32((CORE_PRE_BASE+NVICPRI0),regVal);
		}else if(IRQn == (INTC+PRIO0))
		{
			regVal |=(priority<<21);
			HW_WR_REG32((CORE_PRE_BASE+NVICPRI0),regVal);
		}else if(IRQn == (INTD+PRIO0))
		{
			regVal |=(priority<<29);
			HW_WR_REG32((CORE_PRE_BASE+NVICPRI0),regVal);
		}
	}
	else if(IRQn < 8 && IRQn >= 4)
		{
			uint32_t regVal =  HW_RD_REG32(CORE_PRE_BASE+NVICPRI1);
			if(IRQn == (INTA+PRIO1))
			{
				regVal |=(priority<<5);
				HW_WR_REG32((CORE_PRE_BASE+NVICPRI1),regVal);
			}
			else if(IRQn == (INTB+PRIO1))
			{
				regVal |=(priority<<13);
				HW_WR_REG32((CORE_PRE_BASE+NVICPRI1),regVal);
			}else if(IRQn == (INTC+PRIO1))
			{
				regVal |=(priority<<21);
				HW_WR_REG32((CORE_PRE_BASE+NVICPRI1),regVal);
			}else if(IRQn == (INTD+PRIO1))
			{
				regVal |=(priority<<29);
				HW_WR_REG32((CORE_PRE_BASE+NVICPRI1),regVal);
			}
		}
	else if(IRQn < 12 && IRQn >= 8)
			{
				uint32_t regVal =  HW_RD_REG32(CORE_PRE_BASE+NVICPRI2);
				if(IRQn == (INTA+PRIO2))
				{
					regVal |=(priority<<5);
					HW_WR_REG32((CORE_PRE_BASE+NVICPRI2),regVal);
				}
				else if(IRQn == (INTB+PRIO2))
				{
					regVal |=(priority<<13);
					HW_WR_REG32((CORE_PRE_BASE+NVICPRI2),regVal);
				}else if(IRQn == (INTC+PRIO2))
				{
					regVal |=(priority<<21);
					HW_WR_REG32((CORE_PRE_BASE+NVICPRI2),regVal);
				}else if(IRQn == (INTD+PRIO2))
				{
					regVal |=(priority<<29);
					HW_WR_REG32((CORE_PRE_BASE+NVICPRI2),regVal);
				}
			}
	else if(IRQn < 16 && IRQn >= 12)
				{
					uint32_t regVal =  HW_RD_REG32(CORE_PRE_BASE+NVICPRI3);
					if(IRQn == (INTA+PRIO3))
					{
						regVal |=(priority<<5);
						HW_WR_REG32((CORE_PRE_BASE+NVICPRI3),regVal);
					}
					else if(IRQn == (INTB+PRIO3))
					{
						regVal |=(priority<<13);
						HW_WR_REG32((CORE_PRE_BASE+NVICPRI3),regVal);
					}else if(IRQn == (INTC+PRIO3))
					{
						regVal |=(priority<<21);
						HW_WR_REG32((CORE_PRE_BASE+NVICPRI3),regVal);
					}else if(IRQn == (INTD+PRIO3))
					{
						regVal |=(priority<<29);
						HW_WR_REG32((CORE_PRE_BASE+NVICPRI3),regVal);
					}
				}
	else if(IRQn < 20 && IRQn >= 16)
					{
						uint32_t regVal =  HW_RD_REG32(CORE_PRE_BASE+NVICPRI4);
						if(IRQn == (INTA+PRIO4))
						{
							regVal |=(priority<<5);
							HW_WR_REG32((CORE_PRE_BASE+NVICPRI4),regVal);
						}
						else if(IRQn == (INTB+PRIO4))
						{
							regVal |=(priority<<13);
							HW_WR_REG32((CORE_PRE_BASE+NVICPRI4),regVal);
						}else if(IRQn == (INTC+PRIO4))
						{
							regVal |=(priority<<21);
							HW_WR_REG32((CORE_PRE_BASE+NVICPRI4),regVal);
						}else if(IRQn == (INTD+PRIO4))
						{
							regVal |=(priority<<29);
							HW_WR_REG32((CORE_PRE_BASE+NVICPRI4),regVal);
						}
					}
	else if(IRQn < 32 && IRQn >= 28)
						{
							uint32_t regVal =  HW_RD_REG32(CORE_PRE_BASE+NVICPRI7);
							if(IRQn == (INTA+PRIO7))
							{
								regVal |=(priority<<5);
								HW_WR_REG32((CORE_PRE_BASE+NVICPRI7),regVal);
							}
							else if(IRQn == (INTB+PRIO7))
							{
								regVal |=(priority<<13);
								HW_WR_REG32((CORE_PRE_BASE+NVICPRI7),regVal);
							}else if(IRQn == (INTC+PRIO7))
							{
								regVal |=(priority<<21);
								HW_WR_REG32((CORE_PRE_BASE+NVICPRI7),regVal);
							}else if(IRQn == (INTD+PRIO7))
							{
								regVal |=(priority<<29);
								HW_WR_REG32((CORE_PRE_BASE+NVICPRI7),regVal);
							}
						}
}


