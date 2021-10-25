/* 
 * File:   usart.h
 * Author: sasaki sho
 * Comments: 
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __USART_H
#define __USART_H

/*---Define---*/
#define _USART_TX_CONFIG             	    0b00100100                          //TX9=1(8bit���M),TXEN=1(���M����),SYNC=1(�񓯊����[�h),BRGH=1(�������[�h),
#define _USART_RX_CONFIG             	    0b10010000                          //SPEN=1(�V���A���|�[�g����),CREN=1(�A����M����),
#define _USART_BAUDRATE_H_9600         	    0x00                                //9600bps�ɐݒ�
#define _USART_BAUDRATE_L_9600         	    0x67                                //9600bps�ɐݒ�
//#define _USART_BAUDRATE_L_9600              0x67                              
#define _XTAL_FREQ                   		4000000
#define _RX_STRAGE_SIZE              		16


/*--Prototype--*/
void _usart_init(void);
void _putch(unsigned char c);
void usart_puts(char* s);
void usart_save(void);
char* usart_get(void);

#endif



