/*
 * timer.h
 *
 *  Created on: Aug 22, 2017
 *      Author: Mohamed
 */

#ifndef HAL_TIMER_H_
#define HAL_TIMER_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include"types.h"
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */



/****************************************************************************************************
* Field Definition  Timers Bases
****************************************************************************************************/

#define 					TIMER0 						0x40030000 			// Timer-0  BASE Address
#define 					TIMER1						0x40031000			// Timer-1  BASE Address
#define 					TIMER2 						0x40032000			// Timer-2  BASE Address
#define 					TIMER3 						0x40033000			// Timer-3  BASE Address
#define 					TIMER4 						0x40034000			// Timer-4  BASE Address
#define 					TIMER5 						0x40035000			// Timer-5  BASE Address

#define 					WIDE_TIMER0 				0x40036000 			// Wide Timer-0  BASE Address
#define 					WIDE_TIMER1					0x40037000			// Wide Timer-1  BASE Address
#define 					WIDE_TIMER2 				0x4003C000			// Wide Timer-2  BASE Address
#define 					WIDE_TIMER3 				0x4003D000			// Wide Timer-3  BASE Address
#define 					WIDE_TIMER4 				0x4003E000			// Wide Timer-4  BASE Address
#define 					WIDE_TIMER5 				0x4003F000			// Wide Timer-5  BASE Address


/****************************************************************************************************
* Field Definition Timers Offsets
****************************************************************************************************/

#define 					RCGCWD                  (*((volatile uint32_t *)0x400FE600UL))
#define 					RCGCTIMER               (*((volatile uint32_t *)0x400FE604UL))
#define 					RCGCGPIO                (*((volatile uint32_t *)0x400FE608UL))
#define 					RCGCDMA                 (*((volatile uint32_t *)0x400FE60CUL))
#define 					RCGCHIB                 (*((volatile uint32_t *)0x400FE614UL))
#define  					RCGCUART                (*((volatile uint32_t *)0x400FE618UL))
#define  					RCGCSSI                 (*((volatile uint32_t *)0x400FE61CUL))
#define  					RCGCI2C                 (*((volatile uint32_t *)0x400FE620UL))
#define  					RCGCUSB                 (*((volatile uint32_t *)0x400FE628UL))
#define  					RCGCCAN                 (*((volatile uint32_t *)0x400FE634UL))
#define  					RCGCADC                 (*((volatile uint32_t *)0x400FE638UL))
#define  					RCGCACMP                (*((volatile uint32_t *)0x400FE63CUL))
#define  					RCGCPWM                 (*((volatile uint32_t *)0x400FE640UL))
#define  					RCGCQEI                 (*((volatile uint32_t *)0x400FE644UL))
#define  					RCGCEEPROM              (*((volatile uint32_t *)0x400FE658UL))
#define  					RCGCWTIMER              (*((volatile uint32_t *)0x400FE65CUL))

/****************************************************************************************************
* Field Definition  General Purpose Timers Modules Offsets
****************************************************************************************************/

#define						GPTMCFG					0X000			// Configuration Register
#define						GPTMTAMR				0X004			// Timer A Mode Register
#define						GPTMTBMR				0X008			// Timer B Mode Register
#define						GPTMCTL					0X00C			// Control Register
#define						GPTMSYNC				0X010			// Synchronize Register
#define						GPTMIMR					0X018			// Interrupt Mask Register
#define						GPTMRIS					0X01C			// Raw Interrupt Register
#define						GPTMMIS					0X020			// Masked Interrupt Status
#define						GPTMICR					0X024			// Interrupt Clear
#define						GPTMTAILR				0X028			// Timer A interval Load
#define						GPTMTBILR				0X02C			// Timer B Interval Load
#define						GPTMTAMATCHR			0X030			// Timer A Matcher
#define						GPTMTBMATCHR			0X034			// Timer B Matcher
#define						GPTMTAPR				0X038			// Timer A Prescale
#define						GPTMTBPR				0X03C			// Timer B Prescale
#define						GPTMTAPMR				0X040			// Timer A Prescale Matcher
#define						GPTMTBPMR				0X044			// Timer B Prescale Matcher
#define						GPTMTAR					0X048			// Timer A
#define						GPTMTBR					0X04C			// Timer B
#define						GPTMTAV					0X050			// Timer A Value
#define						GPTMTBV					0X054			// Timer B Value
#define						GPTMRTCPD				0X058			// RTC Predivide
#define						GPTMTAPS				0X05C			// Timer A Prescale Snapshot
#define						GPTMTBPS				0X060			// Timer B Prescale Snapshot
#define						GPTMTAPV				0X064			// Timer A Prescaler Value
#define						GPTMTBPV				0X068			// Timer B Prescaler Value
#define						GPTMPP					0XFC0			// PeripheralProperties

//*****************************************************************************
//
// Values that can be passed to TimerConfigure as the config parameter.
//
//*****************************************************************************
#define TIMER_CFG_32_64_WIDE      0x00000000
#define TIMER_CFG_RTC_32_64_WIDE  0x00000001
#define TIMER_CFG_16_32		      0x00000004

#define TIMER_CFG_ONE_SHOT       0x00000021  // Full-width one-shot timer
#define TIMER_CFG_ONE_SHOT_UP    0x00000031  // Full-width one-shot up-count
                                            // timer
#define TIMER_CFG_PERIODIC       0x00000022  // Full-width periodic timer
#define TIMER_CFG_PERIODIC_UP    0x00000032  // Full-width periodic up-count
                                            // timer
#define TIMER_CFG_RTC            0x01000000  // Full-width RTC timer
#define TIMER_CFG_SPLIT_PAIR     0x04000000  // Two half-width timers

#define TIMER_CFG_A_ONE_SHOT     0x00000021  // Timer A one-shot timer
#define TIMER_CFG_A_ONE_SHOT_UP  0x00000031  // Timer A one-shot up-count timer

#define TIMER_CFG_A_PERIODIC     0x00000022  // Timer A periodic timer
#define TIMER_CFG_A_PERIODIC_UP  0x00000032  // Timer A periodic up-count timer

#define TIMER_CFG_A_CAP_COUNT    0x00000003  // Timer A event counter
#define TIMER_CFG_A_CAP_COUNT_UP 0x00000013  // Timer A event up-counter

#define TIMER_CFG_A_CAP_TIME     0x00000007  // Timer A event timer
#define TIMER_CFG_A_CAP_TIME_UP  0x00000017  // Timer A event up-count timer

#define TIMER_CFG_A_PWM          0x0000000A  // Timer A PWM output

#define TIMER_CFG_B_ONE_SHOT     0x00002100  // Timer B one-shot timer
#define TIMER_CFG_B_ONE_SHOT_UP  0x00003100  // Timer B one-shot up-count timer

#define TIMER_CFG_B_PERIODIC     0x00002200  // Timer B periodic timer
#define TIMER_CFG_B_PERIODIC_UP  0x00003200  // Timer B periodic up-count timer

#define TIMER_CFG_B_CAP_COUNT    0x00000300  // Timer B event counter
#define TIMER_CFG_B_CAP_COUNT_UP 0x00001300  // Timer B event up-counter

#define TIMER_CFG_B_CAP_TIME     0x00000700  // Timer B event timer
#define TIMER_CFG_B_CAP_TIME_UP  0x00001700  // Timer B event up-count timer

#define TIMER_CFG_B_PWM          0x00000A00  // Timer B PWM output


#define TIMER_CFG_A_ACT_TOINTD   0x00001000  // Timer A compare action disable                                             // time-out interrupt.
#define TIMER_CFG_A_ACT_NONE     0x00000000  // Timer A compare action none.
#define TIMER_CFG_A_ACT_TOGGLE   0x00002000  // Timer A compare action toggle.
#define TIMER_CFG_A_ACT_CLRTO    0x00004000  // Timer A compare action CCP                                           // clear on time-out.
#define TIMER_CFG_A_ACT_SETTO    0x00006000  // Timer A compare action CCP set                                             // on time-out.
#define TIMER_CFG_A_ACT_SETTOGTO 0x00008000  // Timer A compare action set CCP                                           // toggle on time-out.
#define TIMER_CFG_A_ACT_CLRTOGTO 0x0000A000  // Timer A compare action clear                                            // CCP toggle on time-out.
#define TIMER_CFG_A_ACT_SETCLRTO 0x0000C000  // Timer A compare action set CCP                                            // clear on time-out.
#define TIMER_CFG_A_ACT_CLRSETTO 0x0000E000  // Timer A compare action clear

#define TIMER_CFG_B_ACT_TOINTD   0x00001000  // Timer B compare action disable                                            // time-out interrupt.
#define TIMER_CFG_B_ACT_NONE     0x00000000  // Timer A compare action none.
#define TIMER_CFG_B_ACT_TOGGLE   0x00002000  // Timer A compare action toggle.
#define TIMER_CFG_B_ACT_CLRTO    0x00004000  // Timer A compare action CCP                                          // clear on time-out.
#define TIMER_CFG_B_ACT_SETTO    0x00006000  // Timer A compare action CCP set                                             // on time-out.
#define TIMER_CFG_B_ACT_SETTOGTO 0x00008000  // Timer A compare action set CCP                                             // toggle on time-out.
#define TIMER_CFG_B_ACT_CLRTOGTO 0x0000A000  // Timer A compare action clear                                            // CCP toggle on time-out.
#define TIMER_CFG_B_ACT_SETCLRTO 0x0000C000  // Timer A compare action set CCP                                            // clear on time-out.
#define TIMER_CFG_B_ACT_CLRSETTO 0x0000E000  // Timer A compare action clear
                                             // CCP set on time-out.
//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CTL register.
//
//*****************************************************************************
#define TIMER_CTL_TBPWML        0x00004000  // GPTM Timer B PWM Output Level
#define TIMER_CTL_TBOTE         0x00002000  // GPTM Timer B Output Trigger       // Enable
#define TIMER_CTL_TBEVENT_M     0x00000C00  // GPTM Timer B Event Mode
#define TIMER_CTL_TBEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TBEVENT_NEG   0x00000400  // Negative edge
#define TIMER_CTL_TBEVENT_BOTH  0x00000C00  // Both edges
#define TIMER_CTL_TBSTALL       0x00000200  // GPTM Timer B Stall Enable
#define TIMER_CTL_TBEN          0x00000100  // GPTM Timer B Enable

#define TIMER_CTL_TAPWML        0x00000040  // GPTM Timer A PWM Output Level
#define TIMER_CTL_TAOTE         0x00000020  // GPTM Timer A Output Trigger     // Enable
#define TIMER_CTL_RTCEN         0x00000010  // GPTM RTC Stall Enable
#define TIMER_CTL_TAEVENT_M     0x0000000C  // GPTM Timer A Event Mode
#define TIMER_CTL_TAEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TAEVENT_NEG   0x00000004  // Negative edge
#define TIMER_CTL_TAEVENT_BOTH  0x0000000C  // Both edges
#define TIMER_CTL_TASTALL       0x00000002  // GPTM Timer A Stall Enable
#define TIMER_CTL_TAEN          0x00000001  // GPTM Timer A Enable

//*****************************************************************************
//
// Values that can be passed to TimerIntEnable, TimerIntDisable, and
// TimerIntClear as the ui32IntFlags parameter, and returned from
// TimerIntStatus.
//
//*****************************************************************************
#define TIMER_TIMB_DMA          0x00002000 // TimerB DMA Complete Interrupt.
#define TIMER_TIMB_MATCH        0x00000800  // TimerB match interrupt
#define TIMER_CAPB_EVENT        0x00000400  // CaptureB event interrupt
#define TIMER_CAPB_MATCH        0x00000200  // CaptureB match interrupt
#define TIMER_TIMB_TIMEOUT      0x00000100  // TimerB time out interrupt
#define TIMER_TIMA_DMA          0x00000020 // TimerA DMA Complete Interrupt.
#define TIMER_TIMA_MATCH        0x00000010  // TimerA match interrupt
#define TIMER_RTC_MATCH         0x00000008  // RTC interrupt mask
#define TIMER_CAPA_EVENT        0x00000004  // CaptureA event interrupt
#define TIMER_CAPA_MATCH        0x00000002  // CaptureA match interrupt
#define TIMER_TIMA_TIMEOUT      0x00000001  // TimerA time out interrupt

//*****************************************************************************
//
// Values that can be passed to TimerControlEvent as the ui32Event parameter.
//
//*****************************************************************************
#define TIMER_EVENT_POS_EDGE    0x00000000  // Count positive edges
#define TIMER_EVENT_NEG_EDGE    0x00000404  // Count negative edges
#define TIMER_EVENT_BOTH_EDGES  0x00000C0C  // Count both edges

//*****************************************************************************
//
// Values that can be passed to most of the timer APIs as the ui32Timer
// parameter.
//
//*****************************************************************************
#define TIMER_A                 0x000000ff  // Timer A
#define TIMER_B                 0x0000ff00  // Timer B
#define TIMER_BOTH              0x0000ffff  // Timer Both

//*****************************************************************************
//
// Values that can be passed to TimerSynchronize as the ui32Timers parameter.
//
//*****************************************************************************
#define TIMER_0A_SYNC           0x00000001  // Synchronize Timer 0A
#define TIMER_0B_SYNC           0x00000002  // Synchronize Timer 0B
#define TIMER_1A_SYNC           0x00000004  // Synchronize Timer 1A
#define TIMER_1B_SYNC           0x00000008  // Synchronize Timer 1B
#define TIMER_2A_SYNC           0x00000010  // Synchronize Timer 2A
#define TIMER_2B_SYNC           0x00000020  // Synchronize Timer 2B
#define TIMER_3A_SYNC           0x00000040  // Synchronize Timer 3A
#define TIMER_3B_SYNC           0x00000080  // Synchronize Timer 3B
#define TIMER_4A_SYNC           0x00000100  // Synchronize Timer 4A
#define TIMER_4B_SYNC           0x00000200  // Synchronize Timer 4B
#define TIMER_5A_SYNC           0x00000400  // Synchronize Timer 5A
#define TIMER_5B_SYNC           0x00000800  // Synchronize Timer 5B
#define WTIMER_0A_SYNC          0x00001000  // Synchronize Wide Timer 0A
#define WTIMER_0B_SYNC          0x00002000  // Synchronize Wide Timer 0B
#define WTIMER_1A_SYNC          0x00004000  // Synchronize Wide Timer 1A
#define WTIMER_1B_SYNC          0x00008000  // Synchronize Wide Timer 1B
#define WTIMER_2A_SYNC          0x00010000  // Synchronize Wide Timer 2A
#define WTIMER_2B_SYNC          0x00020000  // Synchronize Wide Timer 2B
#define WTIMER_3A_SYNC          0x00040000  // Synchronize Wide Timer 3A
#define WTIMER_3B_SYNC          0x00080000  // Synchronize Wide Timer 3B
#define WTIMER_4A_SYNC          0x00100000  // Synchronize Wide Timer 4A
#define WTIMER_4B_SYNC          0x00200000  // Synchronize Wide Timer 4B
#define WTIMER_5A_SYNC          0x00400000  // Synchronize Wide Timer 5A
#define WTIMER_5B_SYNC          0x00800000  // Synchronize Wide Timer 5B

//*****************************************************************************
//
// Values that can be passed to TimerClockSourceSet() or returned from
// TimerClockSourceGet().
//
//*****************************************************************************
#define TIMER_CLOCK_SYSTEM      0x00000000
#define TIMER_CLOCK_PIOSC       0x00000001

//*****************************************************************************
//
// Values that can be passed to TimerDMAEventSet() or returned from
// TimerDMAEventGet().
//
//*****************************************************************************
#define TIMER_DMA_MODEMATCH_B   0x00000800
#define TIMER_DMA_CAPEVENT_B    0x00000400
#define TIMER_DMA_CAPMATCH_B    0x00000200
#define TIMER_DMA_TIMEOUT_B     0x00000100
#define TIMER_DMA_MODEMATCH_A   0x00000010
#define TIMER_DMA_RTC_A         0x00000008
#define TIMER_DMA_CAPEVENT_A    0x00000004
#define TIMER_DMA_CAPMATCH_A    0x00000002
#define TIMER_DMA_TIMEOUT_A     0x00000001

//*****************************************************************************
//
// Values that can be passed to TimerADCEventSet() or returned from
// TimerADCEventGet().
//
//*****************************************************************************
#define TIMER_ADC_MODEMATCH_B   0x00000800
#define TIMER_ADC_CAPEVENT_B    0x00000400
#define TIMER_ADC_CAPMATCH_B    0x00000200
#define TIMER_ADC_TIMEOUT_B     0x00000100
#define TIMER_ADC_MODEMATCH_A   0x00000010
#define TIMER_ADC_RTC_A         0x00000008
#define TIMER_ADC_CAPEVENT_A    0x00000004
#define TIMER_ADC_CAPMATCH_A    0x00000002
#define TIMER_ADC_TIMEOUT_A     0x00000001

//*****************************************************************************
//
// Values that can be passed to TimerUpdateMode().
//
//*****************************************************************************
#define TIMER_UP_LOAD_IMMEDIATE 0x00000000
#define TIMER_UP_LOAD_TIMEOUT   0x00000100
#define TIMER_UP_MATCH_IMMEDIATE                                              \
                                0x00000000
#define TIMER_UP_MATCH_TIMEOUT  0x00000400

/****************************************************************************************************
* Field Definition system Timer offsets
****************************************************************************************************/
#define						STCTRL					0X010
#define						STRELOAD				0X014
#define						STCURRENT				0X018
/* ========================================================================== */
/*                           Structures and Enums                             */
/* ========================================================================== */




/* ========================================================================== */
/*                           Function Declarations                            */
/* ========================================================================== */





/**************************************************************************************
********************************* Timers Functions ***********************************
***************************************************************************************/
/**
 * \brief  				This API Enable timer A
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
void GPTM_TimerEnable(uint32_t timerBase, uint32_t timer);
/**
 * \brief  				This API Disable timer A
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  timer		TIMER_A , TIMER_B , BOTH
 */
void GPTM_TimerDisable(uint32_t timerBase, uint32_t timer);
/**
 * \brief  				This API Config timer
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  config		TIMER_A , TIMER_B , BOTH
 */
void GPTM_TimerConfigure(uint32_t timerBase, uint32_t config) ;
/**
 * \brief  				This API Enable timer A
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_B_Enable(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API configures GPTM Timer B PWM Output Level
 * \param  timerBase	select timer (0->5) or wide timer (0->5)
 */
//void GPTM_Timer_B_PWM_Output_Level(uint32_t timerBase);
/**
 * \brief  				This API configures GPTM Timer B Output Trigger Enable
 * \param  timerBase	select timer (0->5) or wide timer (0->5)
 * \param  state		Enable or Disable
 * 						0 The output Timer B ADC trigger is disabled.
 * 						1 The output Timer B ADC trigger is enabled.
 */
//void GPTM_Timer_B_Output_Trigger_Enable(uint32_t timerBase, uint8_t state);
/**
 * \brief  				This API configures GPTM  Timer B Event Mode
 * \param  timerBase	select timer (0->5) or wide timer (0->5)
 * \param  Value		are defined as follows
 * 						0x0 Positive edge
 * 						0x1 Negative edge
 * 						0x2	Reserved
 * 						0x3 Both edges
 */

//void GPTM_Timer_B_Event_Mode(uint32_t timerBase, uint8_t value);
/**
 * \brief  				This API configures GPTM Timer B PWM Output Level
 * \param  timerBase	select timer (0->5) or wide timer (0->5)
 */
//void GPTM_Timer_A_PWM_Output_Level (uint32_t timerBase);
/**
 * \brief  				This API configures GPTM Timer A Output Trigger Enable
 * \param  timerBase	select timer (0->5) or wide timer (0->5)
 * \param  state		Enable or Disable
 * 						0 The output Timer B ADC trigger is disabled.
 * 						1 The output Timer B ADC trigger is enabled.
 */
//void GPTM_Timer_A_Output_Trigger_Enable(uint32_t timerBase, uint8_t state);
/**
 * \brief  				This API configures GPTM  Timer B Event Mode
 * \param  timerBase	select timer (0->5) or wide timer (0->5)
 * \param  Value		are defined as follows
 * 						0x0 Positive edge
 * 						0x1 Negative edge
 * 						0x2	Reserved
 * 						0x3 Both edges
 */

//void GPTM_Timer_A_Event_Mode(uint32_t timerBase, uint8_t value);

/**
 * \brief  				ThisregisterconfigurestheglobaloperationoftheGPTMmodule.
 * 						The value written to this register determines whether the
 * 						GPTM is in 32- or 64-bit mode (concatenated timers) or
 * 						in 16- or 32-bit mode (individual, split timers).
 * \param  timerBase	select timer (0->5) or wide timer (0->5)
 * \param  Value		are defined as follows
 * 						0x0	 	(16/32-bit timer - selects the 32-bit timer configuration -
 * 								 32/64-bit wide timer  selects the 64-bit timer configuration. )
 *
 * 						0x1 	(16/32-bit timer - selects the 32-bit real-time clock -
 * 								 32/64-bit wide timer selects the 64-bit real-time clock )
 *
 * 						0x4 	(16/32-bit timer -  selects the 16-bit timer configuration.  -
 * 							 	 32/64-bit wide timer  selects the 32-bit timer configuration. )
 */

//void GPTM_Configration(uint32_t timerBase, uint8_t value);


/*********************************** Timer A Mode Register **************************************************/

/**
 * \brief  				This API configures GPTM  Modes
 * \param  timerBase	select timer (0->5) or wide timer (0->5)
 * \param  Value		are defined as follows
 * 						0x1  One-Shot Timer mode
 * 						0x2	Periodic Timer mode
 * 						0x3 Capture mode
 */

//void GPTM_Timer_A_Mode(uint32_t timerBase, uint8_t value);
/**
 * \brief  				This API Enable Timer A PWM Legacy Operation
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_A_PWM_Legacy_Operation(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable Timer A  Match Register Update
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_A_Match_Register_Update(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A   PWM Interrupt Enable
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_A_PWM_Interrupt_Enable(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A  Interval Load Write
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_A_Interval_Load_Write(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A  Snap-Shot Mode
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_A_SnapShot_Mode(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A  Wait-on-Trigger
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_A_Wait_on_Trigger(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A Match Interrupt Enable
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_A_Match_Interrupt_Enable(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A Count Direction
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		0 The timer counts down.
 * 						1 The timer counts up
 */
//void GPTM_Timer_A_Count_Direction(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A  Alternate Mode Select
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		0 Capture or compare mode is enabled
 * 						1 PWM mode is enabled
 */
//void GPTM_Timer_A_Alternate_Mode_Select (uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A   Capture Mode
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		0 Edge-Count mode
 * 						1 Edge-Time mode
 */
//void GPTM_Timer_A_Capture_Mode (uint32_t timerBase , uint8_t state);

/*********************************** Timer B Mode Register **************************************************/

/**
 * \brief  				This API configures GPTM  Modes
 * \param  timerBase	select timer (0->5) or wide timer (0->5)
 * \param  Value		are defined as follows
 * 						0x1  One-Shot Timer mode
 * 						0x2	Periodic Timer mode
 * 						0x3 Capture mode
 */
//void GPTM_Timer_B_Mode(uint32_t timerBase, uint8_t value);
/**
 * \brief  				This API Enable Timer B PWM Legacy Operation
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_B_PWM_Legacy_Operation(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable Timer A  Match Register Update
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_B_Match_Register_Update(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A   PWM Interrupt Enable
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_B_PWM_Interrupt_Enable(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A  Interval Load Write
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_B_Interval_Load_Write(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A  Snap-Shot Mode
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_B_SnapShot_Mode(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A  Wait-on-Trigger
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_B_Wait_on_Trigger(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A Match Interrupt Enable
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		ENABLE / DISABLE (1/0)
 */
//void GPTM_Timer_B_Match_Interrupt_Enable(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A Count Direction
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		0 The timer counts down.
 * 						1 The timer counts up
 */
//void GPTM_Timer_B_Count_Direction(uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A  Alternate Mode Select
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		0 Capture or compare mode is enabled
 * 						1 PWM mode is enabled
 */
//void GPTM_Timer_B_Alternate_Mode_Select (uint32_t timerBase , uint8_t state);
/**
 * \brief  				This API Enable  Timer A   Capture Mode
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 * \param  state  		0 Edge-Count mode
 * 						1 Edge-Time mode
 */
//void GPTM_Timer_B_Capture_Mode (uint32_t timerBase , uint8_t state);

/*********************************** Raw Interrupt Status Register **************************************************/


/**
 * \brief  				This API returns  Timer A   Timer A Time-Out Raw Interrupt
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 */
//uint8_t GPTM_Timer_A_Time_Out_Flage (uint32_t timerBase);
/**
 * \brief  				This API returns  Timer A   Timer A  Capture Mode Match Raw Interrupt
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 */
//uint8_t GPTM_Timer_A_Capture_Mode_Match_Flage (uint32_t timerBase);
/**
 * \brief  				This API returns  Timer A   Timer A  Capture Mode Event Raw Interrupt
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 */
//uint8_t GPTM_Timer_A_Capture_Event_Mode_Match_Flage (uint32_t timerBase);
/**
 * \brief  				This API returns  RTC Raw Interrupt
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 */
//uint8_t GPTM_RTC_Flage (uint32_t timerBase);

/**
 * \brief  				This API returns  Timer A Match Raw Interrupt
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 */
//uint8_t GPTM_Timer_A_Match (uint32_t timerBase);

/**
 * \brief  				This API returns Timer B Time-Out Raw Interrupt
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 */
//uint8_t GPTM_Timer_B_Time_Out_Flage (uint32_t timerBase);
/**
 * \brief  				This API returns Timer B  Capture Mode Match Raw Interrupt
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 */
//uint8_t GPTM_Timer_B_Capture_Mode_Match_Flage (uint32_t timerBase);
/**
 * \brief  				This API returns  Timer B Capture Mode Event Raw Interrupt
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 */
//uint8_t GPTM_Timer_B_Capture_Event_Mode_Match_Flage (uint32_t timerBase);

/**
 * \brief  				This API returns  Timer B Match Raw Interrupt
 * \param  timerBase    select timer (0->5) or wide timer (0->5)
 */
//uint8_t GPTM_Timer_B_Match (uint32_t timerBase);





#endif /* HAL_TIMER_H_ */
