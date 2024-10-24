

#include "config.h"

void sys_init(void)
{
    // Configure PLL prescaler, PLL postscaler, PLL divisor   7.37*217/2/10=79.9645
    PLLFBD = 41; // M = 217
    CLKDIVbits.PLLPOST=0; // N2 = 2
    CLKDIVbits.PLLPRE=0; // N1 = 4
    
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(OSCCON | 0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    // Wait for PLL to lock
    while(OSCCONbits.LOCK!=1) {};
    
}
