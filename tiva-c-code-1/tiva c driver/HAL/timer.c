/*
 * timer.c
 *
 *  Created on: Aug 22, 2017
 *      Author: Mohamed
 */
#if 0
#include"../HAL/timer.h"
#include"../HAL/hw_gpio.h"
#include"../HAL/gpio.h"
#include"../HAL/types.h"
#include"../HAL/hw_types.h"
void SysTick_Control(uint32_t val)
{
	HW_WR_REG32((CORE_PRE_BASE+STCTRL),val);
}

void SysTick_SetPeriod(uint32_t val)
{
	HW_WR_REG32((CORE_PRE_BASE+STRELOAD),val);
}
void SysTick_SetValue(uint32_t val)
{
	uint32_t regVal = HW_RD_REG32((CORE_PRE_BASE+STCURRENT));
	regVal |= val ;
	HW_WR_REG32((CORE_PRE_BASE+STCURRENT),regVal);
}

void SysTick_Delay_Mili(uint32_t delay_val)
{
	SysTick_Control(0x5);
	uint32_t reloadVal = ((delay_val*0.001)/0.0000000625) ;
	SysTick_SetPeriod(reloadVal-1);
	SysTick_SetValue(0);
}



void GPTM_TimerEnable(uint32_t timerBase, uint32_t timer)
{
	uint32_t regVal = HW_RD_REG32(timerBase+GPTMCTL);
	if(timer ==  TIMER_A )
	{
		regVal |= (1U<<0);
	}
	else if(timer ==  TIMER_B)
	{
		regVal |=(1U<<8);
	}
	else
	{
		regVal |=((1U<<8)|(1U<<0)) ;
	}
	HW_WR_REG32((timerBase+GPTMCTL),regVal);
}
void GPTM_TimerDisable(uint32_t timerBase, uint32_t timer)
{
	uint32_t regVal = HW_RD_REG32(timerBase+GPTMCTL);
	if(timer ==  TIMER_A )
	{
		regVal &= ~(1U<<0);
	}
	else if(timer ==  TIMER_B)
	{
		regVal &= ~(1U<<8);
	}
	else
	{
		regVal &= ~((1U<<8)|(1U<<0)) ;
	}
	HW_WR_REG32((timerBase+GPTMCTL),regVal);
}
// this fun deals with GPTMxMR (x --> [A-B])
#ifdef TIMER_BOTH
void GPTM_TimerConfigure(uint32_t timerBase, uint32_t config)
{
	switch(config)
		{

		case TIMER_CFG_ONE_SHOT :
			HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_32_64_WIDE);
			HW_WR_REG32((timerBase+GPTMTAMR),TIMER_CFG_A_ONE_SHOT);
			break ;
		case TIMER_CFG_ONE_SHOT_UP :
			HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_32_64_WIDE);
			HW_WR_REG32((timerBase+GPTMTAMR),TIMER_CFG_A_ONE_SHOT_UP);
			break ;
		case TIMER_CFG_PERIODIC :
			HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_32_64_WIDE);
			HW_WR_REG32((timerBase+GPTMTAMR),TIMER_CFG_A_PERIODIC);
			break ;
		case TIMER_CFG_PERIODIC_UP :
			HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_32_64_WIDE);
			HW_WR_REG32((timerBase+GPTMTAMR),TIMER_CFG_A_PERIODIC_UP);
			break ;
		}

}
#endif
#ifdef TIMER_A
void GPTM_TimerConfigure(uint32_t timerBase, uint32_t config)
{
	switch(config)
	{
	case TIMER_CFG_A_ONE_SHOT :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ONE_SHOT_UP :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_PERIODIC :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_PERIODIC_UP :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_CAP_COUNT :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_CAP_COUNT_UP :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_CAP_TIME :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_PWM :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ACT_TOINTD :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ACT_NONE :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ACT_TOGGLE :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ACT_CLRTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ACT_SETTOGTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ACT_SETTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ACT_CLRTOGTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ACT_SETCLRTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	case TIMER_CFG_A_ACT_CLRSETTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTAMR),config);
		break ;
	}
}
#endif

#ifdef TIMER_B
void GPTM_TimerConfigure(uint32_t timerBase, uint32_t config)
{
	switch(config){
	case TIMER_CFG_B_ONE_SHOT :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ONE_SHOT_UP :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_PERIODIC :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_PERIODIC_UP :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_CAP_COUNT :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_CAP_COUNT_UP :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_CAP_TIME :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_PWM :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ACT_TOINTD :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ACT_NONE :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ACT_TOGGLE :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ACT_CLRTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ACT_SETTOGTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ACT_SETTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ACT_CLRTOGTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ACT_SETCLRTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;
	case TIMER_CFG_B_ACT_CLRSETTO :
		HW_WR_REG32((timerBase+GPTMCFG),TIMER_CFG_16_32);
		HW_WR_REG32((timerBase+GPTMTBMR),config);
		break ;


	}
}
#endif



/*

void GPTM_Timer_A_Mode(uint32_t timerBase, uint8_t value)
{
	uint32_t regVal = HW_RD_REG32(timerBase+GPTMTAMR);
	regVal =(value<<0);
	HW_WR_REG32((timerBase+GPTMTAMR),regVal);
}
void GPTM_Timer_A_Count_Direction(uint32_t timerBase , uint8_t state)
{
	uint32_t regVal = HW_RD_REG32(timerBase+GPTMTAMR);
	if(state== COUNTS_UP)
	{
		regVal |= (1U<<4);
	}
	else
	{
		regVal &=~(1U<<4);
	}
	HW_WR_REG32((timerBase+GPTMTAMR),regVal);
}

void GPTM_Timer_B_Mode(uint32_t timerBase, uint8_t value)
{
	uint32_t regVal = HW_RD_REG32(timerBase+GPTMTBMR);
	regVal =(value<<0);
	HW_WR_REG32((timerBase+GPTMTBMR),regVal);
}
void GPTM_Timer_B_Count_Direction(uint32_t timerBase , uint8_t state)
{
	uint32_t regVal = HW_RD_REG32(timerBase+GPTMTBMR);
	if(state== COUNTS_UP)
	{
		regVal |= (1U<<4);
	}
	else
	{
		regVal &=~(1U<<4);
	}
	HW_WR_REG32((timerBase+GPTMTBMR),regVal);
}

uint8_t GPTM_Timer_A_Time_Out_Flage (uint32_t timerBase)
{
	uint32_t regVal = HW_RD_REG32(timerBase+GPTMRIS);
	uint32_t pinReading = ((regVal & (1<<0))>>0);
	if(pinReading == HIGH)
		return HIGH ;
	else
		return LOW ;
}

uint8_t GPTM_Timer_B_Time_Out_Flage (uint32_t timerBase)
{
	uint32_t regVal = HW_RD_REG32(timerBase+GPTMRIS);
	uint32_t pinReading = ((regVal & (1<<8))>>8);
	if(pinReading == HIGH)
		return HIGH ;
	else
		return LOW ;
}

*/
#endif
