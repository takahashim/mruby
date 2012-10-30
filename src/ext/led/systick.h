/********************************************************************************/
/*!
	@file			systick.h
	@author         Nemui Trinomius (http://nemuisan.blog.bai.ne.jp)
    @version        2.00
    @date           2011.05.08
	@brief          delay mSec-order routine using SysTick Timer			@n
					delay uSec-order routine using FM3 DUAL-Timer1

    @section HISTORY
		2011.01.20	V1.00	Start Here.
		2012.05.07	V2.00   Implemented _delay_us() Using FM3 Dual-Timer1

    @section LICENSE
		BSD License. See Copyright.txt
*/
/********************************************************************************/
#ifndef __SYSTICK_H
#define __SYSTICK_H 0x0200

/* General Inclusion */
#include "mcu.h"

/* Systick Interval MilliSecond order (in Hz) */
#define INTERVAL		1000UL
/* Timer Interval MicroSecond order (in Hz) */
#define USEC_INTERVAL 	1000000UL

/* Inline Static Function */
extern __IO uint32_t TimingDelay;
static inline void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

/* Externals */
extern void _delay_ms(__IO uint32_t mSec);
extern void _delay_us(__IO uint32_t uSec);
extern void SysTickInit(__IO uint32_t interval);

#endif /* __SYSTICK_H */
