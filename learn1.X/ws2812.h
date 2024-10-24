/* 
 * File:   ws2812.h
 * Author: QXQX
 *
 * Created on May 29, 2024, 8:00 PM
 */

#ifndef WS2812_H
#define	WS2812_H

#include <p33FJ16GS502.h>

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

void ResetDataFlow(void);
void SendOnePix(unsigned char *ptr);

#endif	/* WS2812_H */

