/*
 * bsp.h
 *
 *  Created on: 22 Ara 2020
 *      Author: Mehmet Akif/171024027
 */

#ifndef BSP_H_
#define BSP_H_

#include "keypad.h"

void BSP_init();
void init_timer1();

void delay_ms(volatile unsigned int);

#endif /* BSP_H_ */
