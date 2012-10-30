/********************************************************************************/
/*!
	@file			uart_support.h
	@author         Nemui Trinomius (http://nemuisan.blog.bai.ne.jp)
    @version        1.00
    @date           2012.05.10
	@brief          Based on ChaN's FatFs Sample Thanks!

    @section HISTORY
		2012.05.10	V1.00	Start Here.

    @section LICENSE
		BSD License. See Copyright.txt
*/
/********************************************************************************/
#ifndef __UART_SUPPORT_H
#define __UART_SUPPORT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* General Inclusion */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

/* uC Specific Inclusion */
#include "mcu.h"

/* USART Definition */
#define UART_BUFSIZE			256			/* UART TX&RX BufferSize in byte */
#define UART_BAUDLATE			230400UL	/* UART Baudrate */
#define UART_MFS				3			/* MFS channel to be used as UART (0-3,4-7) */
#define UART_LOC				2			/* Pin relocation number (0-2) */

#if   UART_MFS == 0
#define MFS_UART_RX_IRQHandler 	MFS0RX_IRQHandler
#define MFS_UART_TX_IRQHandler 	MFS0TX_IRQHandler
#define MFS_UART_RX_IRQn 		MFS0RX_IRQn
#define MFS_UART_TX_IRQn 		MFS0TX_IRQn
#define MFS_UART_SMR   			FM3_MFS0_UART->SMR
#define MFS_UART_SCR  		 	FM3_MFS0_UART->SCR
#define MFS_UART_ESCR  			FM3_MFS0_UART->ESCR
#define MFS_UART_SSR   			FM3_MFS0_UART->SSR
#define MFS_UART_TDR   			FM3_MFS0_UART->TDR
#define MFS_UART_RDR   			FM3_MFS0_UART->RDR
#define MFS_UART_BGR   			FM3_MFS0_UART->BGR
#if   UART_LOC == 0
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 4)) | (4 << 4);  FM3_GPIO->PFR2 |= 3 << 1; }
#elif UART_LOC == 1
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 4)) | (10 << 4); FM3_GPIO->PFR1 |= 3 << 4; }
#elif UART_LOC == 2
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 4)) | (15 << 4); FM3_GPIO->PFRB |= 3 << 4; }
#endif

#elif UART_MFS == 1
#define MFS_UART_RX_IRQHandler	MFS1RX_IRQHandler
#define MFS_UART_TX_IRQHandler	MFS1TX_IRQHandler
#define MFS_UART_RX_IRQn 		MFS1RX_IRQn
#define MFS_UART_TX_IRQn 		MFS1TX_IRQn
#define MFS_UART_SMR   			FM3_MFS1_UART->SMR
#define MFS_UART_SCR   			FM3_MFS1_UART->SCR
#define MFS_UART_ESCR  			FM3_MFS1_UART->ESCR
#define MFS_UART_SSR   			FM3_MFS1_UART->SSR
#define MFS_UART_TDR   			FM3_MFS1_UART->TDR
#define MFS_UART_RDR   			FM3_MFS1_UART->RDR
#define MFS_UART_BGR   			FM3_MFS1_UART->BGR
#if   UART_LOC == 0
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 10)) | (4 << 10);  FM3_GPIO->PFR5 |= 3 << 6; }
#elif UART_LOC == 1
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 10)) | (10 << 10); FM3_GPIO->PFR1 |= 3 << 1; }
#elif UART_LOC == 2
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 10)) | (15 << 10); FM3_GPIO->PFRF |= 3 << 0; }
#endif

#elif UART_MFS == 2
#define MFS_UART_RX_IRQHandler	MFS2RX_IRQHandler
#define MFS_UART_TX_IRQHandler	MFS2TX_IRQHandler
#define MFS_UART_RX_IRQn 		MFS2RX_IRQn
#define MFS_UART_TX_IRQn 		MFS2TX_IRQn
#define MFS_UART_SMR   			FM3_MFS2_UART->SMR
#define MFS_UART_SCR   			FM3_MFS2_UART->SCR
#define MFS_UART_ESCR  			FM3_MFS2_UART->ESCR
#define MFS_UART_SSR   			FM3_MFS2_UART->SSR
#define MFS_UART_TDR   			FM3_MFS2_UART->TDR
#define MFS_UART_RDR   			FM3_MFS2_UART->RDR
#define MFS_UART_BGR   			FM3_MFS2_UART->BGR
#if   UART_LOC == 0
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 16)) | (4 << 16);  FM3_GPIO->PFR7 |= 3 << 2; }
#elif UART_LOC == 1
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 16)) | (10 << 16); FM3_GPIO->PFR2 |= 3 << 4; }
#elif UART_LOC == 2
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 16)) | (15 << 16); FM3_GPIO->PFR1 |= 3 << 7; }
#endif

#elif UART_MFS == 3
#define MFS_UART_RX_IRQHandler	MFS3RX_IRQHandler
#define MFS_UART_TX_IRQHandler	MFS3TX_IRQHandler
#define MFS_UART_RX_IRQn 		MFS3RX_IRQn
#define MFS_UART_TX_IRQn 		MFS3TX_IRQn
#define MFS_UART_SMR   			FM3_MFS3_UART->SMR
#define MFS_UART_SCR   			FM3_MFS3_UART->SCR
#define MFS_UART_ESCR  			FM3_MFS3_UART->ESCR
#define MFS_UART_SSR   			FM3_MFS3_UART->SSR
#define MFS_UART_TDR   			FM3_MFS3_UART->TDR
#define MFS_UART_RDR   			FM3_MFS3_UART->RDR
#define MFS_UART_BGR   			FM3_MFS3_UART->BGR
#if   UART_LOC == 0
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 22)) | (4 << 22);  FM3_GPIO->PFR7 |= 3 << 5; }
#elif UART_LOC == 1
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 22)) | (10 << 22); FM3_GPIO->PFR5 |= 3 << 0; }
#elif UART_LOC == 2
#define ATTACH_MFS() { FM3_GPIO->EPFR07 = (FM3_GPIO->EPFR07 & ~(15 << 22)) | (15 << 22); FM3_GPIO->PFR4 |= 3 << 8; }
#endif

#elif UART_MFS == 4
#define MFS_UART_RX_IRQHandler	MFS4RX_IRQHandler
#define MFS_UART_TX_IRQHandler	MFS4TX_IRQHandler
#define MFS_UART_RX_IRQn 		MFS4RX_IRQn
#define MFS_UART_TX_IRQn 		MFS4TX_IRQn
#define MFS_UART_SMR   			FM3_MFS4_UART->SMR
#define MFS_UART_SCR   			FM3_MFS4_UART->SCR
#define MFS_UART_ESCR  			FM3_MFS4_UART->ESCR
#define MFS_UART_SSR   			FM3_MFS4_UART->SSR
#define MFS_UART_TDR   			FM3_MFS4_UART->TDR
#define MFS_UART_RDR   			FM3_MFS4_UART->RDR
#define MFS_UART_BGR   			FM3_MFS4_UART->BGR
#if   UART_LOC == 0
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 4)) | (4 << 4);  FM3_GPIO->PFRD |= 3 << 1; }
#elif UART_LOC == 1
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 4)) | (10 << 4); FM3_GPIO->PFR1 |= 3 << 10; }
#elif UART_LOC == 2
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 4)) | (15 << 4); FM3_GPIO->PFR0 |= 3 << 5; }
#endif

#elif UART_MFS == 5
#define MFS_UART_RX_IRQHandler	MFS5RX_IRQHandler
#define MFS_UART_TX_IRQHandler	MFS5TX_IRQHandler
#define MFS_UART_RX_IRQn 		MFS5RX_IRQn
#define MFS_UART_TX_IRQn 		MFS5TX_IRQn
#define MFS_UART_SMR   			FM3_MFS5_UART->SMR
#define MFS_UART_SCR   			FM3_MFS5_UART->SCR
#define MFS_UART_ESCR 			FM3_MFS5_UART->ESCR
#define MFS_UART_SSR  			FM3_MFS5_UART->SSR
#define MFS_UART_TDR  			FM3_MFS5_UART->TDR
#define MFS_UART_RDR   			FM3_MFS5_UART->RDR
#define MFS_UART_BGR   			FM3_MFS5_UART->BGR
#if   UART_LOC == 0
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 10)) | (4 << 10);  FM3_GPIO->PFR6 |= 3 << 0; }
#elif UART_LOC == 1
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 10)) | (10 << 10); FM3_GPIO->PFR9 |= 3 << 2; }
#elif UART_LOC == 2
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 10)) | (15 << 10); FM3_GPIO->PFR3 |= 3 << 6; }
#endif

#elif UART_MFS == 6
#define MFS_UART_RX_IRQHandler	MFS6RX_IRQHandler
#define MFS_UART_TX_IRQHandler	MFS6TX_IRQHandler
#define MFS_UART_RX_IRQn 		MFS6RX_IRQn
#define MFS_UART_TX_IRQn 		MFS6TX_IRQn
#define MFS_UART_SMR   			FM3_MFS6_UART->SMR
#define MFS_UART_SCR   			FM3_MFS6_UART->SCR
#define MFS_UART_ESCR  			FM3_MFS6_UART->ESCR
#define MFS_UART_SSR   			FM3_MFS6_UART->SSR
#define MFS_UART_TDR   			FM3_MFS6_UART->TDR
#define MFS_UART_RDR   			FM3_MFS6_UART->RDR
#define MFS_UART_BGR   			FM3_MFS6_UART->BGR
#if   UART_LOC == 0
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 16)) | (4 << 16);  FM3_GPIO->PFR5 |= 3 << 3; }
#elif UART_LOC == 1
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 16)) | (10 << 16); FM3_GPIO->PFR3 |= 3 << 2; }
#elif UART_LOC == 2
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 16)) | (15 << 16); FM3_GPIO->PFRF |= 3 << 3; }
#endif

#elif UART_MFS == 7
#define MFS_UART_RX_IRQHandler	MFS7RX_IRQHandler
#define MFS_UART_TX_IRQHandler	MFS7TX_IRQHandler
#define MFS_UART_RX_IRQn 		MFS7RX_IRQn
#define MFS_UART_TX_IRQn 		MFS7TX_IRQn
#define MFS_UART_SMR   			FM3_MFS7_UART->SMR
#define MFS_UART_SCR  			FM3_MFS7_UART->SCR
#define MFS_UART_ESCR  			FM3_MFS7_UART->ESCR
#define MFS_UART_SSR   			FM3_MFS7_UART->SSR
#define MFS_UART_TDR   			FM3_MFS7_UART->TDR
#define MFS_UART_RDR   			FM3_MFS7_UART->RDR
#define MFS_UART_BGR   			FM3_MFS7_UART->BGR
#if   UART_LOC == 0
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 22)) | (4 << 22);  FM3_GPIO->PFR5 |= 3 << 9; }
#elif UART_LOC == 1
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 22)) | (10 << 22); FM3_GPIO->PFR4 |= 3 << 13; }
#elif UART_LOC == 2
#define ATTACH_MFS() { FM3_GPIO->EPFR08 = (FM3_GPIO->EPFR08 & ~(15 << 22)) | (15 << 22); FM3_GPIO->PFRB |= 3 << 0; }
#endif

#endif

/* General Definition */
/* Structs of UART(This is From AVRX uC Sample!!!) */
/* @brief USART transmit and receive ring buffer. */
typedef struct USART_Buffer
{
	/* @brief Receive buffer. */
	volatile uint8_t RX[UART_BUFSIZE];
	/* @brief Transmit buffer. */
	volatile uint8_t TX[UART_BUFSIZE];
	/* @brief Receive buffer head. */
	volatile uint16_t RX_Head;
	/* @brief Receive buffer tail. */
	volatile uint16_t RX_Tail;
	/* @brief Transmit buffer head. */
	volatile uint16_t TX_Head;
	/* @brief Transmit buffer tail. */
	volatile uint16_t TX_Tail;
} USART_Buffer_t;


/* Funcion Prototypes */
extern void conio_init(uint32_t baudrate);
extern void putch(uint8_t c);
extern uint8_t getch(void);
extern uint8_t keypressed(void);
extern void cputs(char *s);
extern void cgets(char *s, int bufsize);

/* Externs */


#ifdef __cplusplus
}
#endif

#endif	/* __UART_SUPPORT_H */
