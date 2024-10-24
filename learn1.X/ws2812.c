#include "ws2812.h"

/*          ws2812时序
T0H	0码，  高电平时间	0.4µs	±150ns
T1H	1码，  高电平时间	0.8 µs	±150ns
T0L	0码，  低电平时间	0.85µs	±150ns
T1L	1码，  低电平时间	0.45 µs	±150ns
 * 
24bit数据结构：
 * bit23   --    bit0
G7	G6	G5	G4	G3	G2	G1	G0	R7	R6	R5	R4	R3	R2	R1	R0	B7	B6	B5	B4	B3	B2	B1	B0
注：高位先发，按照GRB的顺序发送数据。
*/

#define DI _LATB13 

void _nop_(unsigned char size){
    unsigned char i;
    for (i = 0; i < size; i++) {      
        __builtin_nop();
    }
}
void ResetDataFlow(void)
{
	unsigned char i,j;
	DI=0;					//DI置为0后，延时50us以上，实现帧复位
	for(i=0;i<50;i++)		//此处33Mhz时延时65us
	{
		for(j=0;j<20;j++)
		{
			;
		}
	}
}
//-------------------------------------------------------------------------------
//子程序名称:SendOnePix(unsigned char *ptr)
//功能：发送一个像素点的24bit数据
//参数：接收的参数是一个指针，此函数会将此指针指向的地址的连续的三个Byte的数据发送
//说明：
//-------------------------------------------------------------------------------
void SendOnePix(unsigned char *ptr) //unsigned char a[3]={0,0,50};0=0x00=0000 0000   0x80=1000 0000  BGR
{
	unsigned char i,j;
	unsigned char temp;

	for(j=0;j<3;j++)
	{
		temp=ptr[j];
		for(i=0;i<8;i++)
		{
			if(temp&0x80)		 //从高位开始发送   发送1   
			{
				DI=1;			 //发送“1”码
				_nop_(5);		 //0.8us
				DI=0;
				_nop_(3);        //0.45us
			}
			else				//发送“0”码
			{
				DI=1;			 //发送“1”码
				_nop_(3);		 //0.45us
				DI=0;
				_nop_(6);        //0.8us
			}
			temp=(temp<<1);		 //左移位
		}
	}
}