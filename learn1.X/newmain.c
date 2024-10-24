/* 
 * File:   newmain.c
 * Author: QXQX
 *
 * Created on 2024年5月15日, 下午9:42
 */



#if 1

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (General Segment may be written)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = FRC              // Oscillator Source Selection (Internal Fast RC (FRC) oscillator)
#pragma config IESO = ON                // Internal External Switch Over Mode (Start up device with FRC, then automatically switch to user-selected oscillator source)

// FOSC
#pragma config POSCMD = HS              // Primary Oscillator Source (HS Crystal Oscillator Mode)
#pragma config OSCIOFNC = ON           // OSC2 Pin Function (OSC2 is clock output)
#pragma config IOL1WAY = OFF            // Peripheral Pin Select Configuration (Allow multiple reconfigurations)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor (Clock switching and Fail-Safe Clock Monitor are enabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR32            // WDT Prescaler (1:32)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is disabled)
#endif

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "init.h"
#include "xc.h"
#include "uart.h"
#if 0
_FGS(GWRP_OFF)
_FOSCSEL(FNOSC_FRC)
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON)
_FWDT(FWDTEN_OFF)
_FPOR(FPWRT_PWR128) 
_FICD(ICS_PGD2 & JTAGEN_OFF)
#endif   
#define LED _LATB13 
    
void delay(int x)
{
    int i = 0;
    for (i = 0; i < x; i++);
}
    

/* 
 * 
 */
int main(void) 
{
    uint16_t tick = 0;
    sys_init();
    GPIO_Init();
    Timer1_Init();
    
    while(1)
    {
        tick++;
        delay(10000);
        printf(" ok %d \r\n", tick);
        delay(10000);
    }
    
}

void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void)
{
    LED = !LED;
    _T1IF = 0;
}

void __attribute__((__interrupt__,no_auto_psv)) _U1RXInterrupt(void)
{
    _U1RXIF = 0;    //清除中断标志位
}