#include "uart.h"
#include "stdio.h"

void UART1_Init(void)
{
    U1MODEbits.UARTEN = 1;
    _U1RXIE = 1;
    _U1RXIF = 0;
    _U1RXIP = 3;
    _U1RXR = 8;     //RP8 作为串口输入
    _RP15R = 3;     //RP15 作为串口的输出
    U1BRG = 21;  //115200 bps fcy/16/baud - 1
}

 int fputc(int ch, FILE *f);
 int fputc(int ch, FILE *f)  
{ 
     while(!_TRMT);
     U1TXREG = ch;
 }

