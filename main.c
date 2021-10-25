/*
 * File:   main.c
 * Author: aibyo
 *
 * Created on 2020/07/19, 1:38
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "usart.h"

// CONFIG1
#pragma config FOSC = INTRC_CLKOUT        // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 2.1V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#define _XTAL_FREQ 4000000

void usart_init(void);
void putch(unsigned char);

char rx_data;
char s[10];
int rx_flag = 0;
volatile int i = 0;

void main(void)
{   
    OSCCON = 0b01101000;                                                        //ÉNÉçÉbÉNÇ4MHzÇ…
    ANSEL = 0x00;
    TRISC = 0x00;
    PORTC = 0x00;
    
    _usart_init();
    __delay_ms(1000);
    
    while(1)
    {
        
    }

}

void putch(unsigned char c)
{
    while(!TXIF);
    TXREG = c;
}


void interrupt rx_uart0(void)
{
    if(RCIF)
    {
        s[i] = RCREG;
        i++;
        
        if(s[i] == 0x0d || s[i] == 0x0a)
        {
            printf("%s\r\n", s);
            i = 0;
        }

        
        RCIF = 0;
    }
}




