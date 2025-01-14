/*
 *
 * https://blog.csdn.net/humphreyandkate/article/details/104731073
 * https://blog.csdn.net/luo_5458/article/details/51907193
 *
 * notes:
 * Clock phase CPHA should be 2 Edge
 * speed < 4M/bit
 *
 */

#ifndef __ADS1118_H__
#define __ADS1118_H__

#include "main.h"
#include "spi.h"
#include "gpio.h"

#define SS 0x1
#define MUX 0x4
#define PGA 0x0
#define MODE 0x1

#define DR 0x4
#define TS_MODE 0x0
#define PULLUP_EN 0x1
#define NOP 0x1

int ADS1118_GetData(void);
float ADS1118_GetVoltage(uint8_t mode, uint8_t range, uint8_t speed);
/*
 * mode: 000=Ain0-Ain1, 001=Ain0-Ain3, 010=Ain1-Ain3, 011=Ain2-Ain3,
 * 		 100=Ain0-gnd, 101=Ain1-gnd, 110=Ain2-gnd, 111=Ain3-gnd.
 *
 *
 * range: 000=±6.144V, 001=±4.096V, 010=±2.048V,
 * 		  011=±1.024V, 100=±0.512V, 101=110=111=±0.256V.
 *
 * speed: 000=8, 001=16, 010=32, 011=31,
 * 		  100=128, 101=250, 110=475, 111=860(times/s)
 *
 */
#endif
