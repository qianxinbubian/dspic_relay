#include "init.h"

void GPIO_Init(void)
{
    _TRISB13 = 0;
    _RB13 = 0;
    _LATB13 = 1;
    
}

void Timer1_Init(void)
{
    PR1 = 40000;
    T1CON = 0;
    IFS0bits.T1IF = 0;
    IPC0bits.T1IP = 5;
    IEC0bits.T1IE = 1;
    T1CONbits.TCKPS = 0;
    T1CONbits.TON = 1;
    
}

