/*
 * display.h
 *
 *  Created on: Dec 19, 2020
 *      Author: Mehmet Akif/171024027
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "main.h"
#include "bsp.h"

typedef struct{
	uint8_t Digits[4];
	uint8_t Oflw:1;
	uint8_t sign:1;
	uint8_t dot:3;
	uint8_t Inv:1;
}SSD;

/*
 * Display struct keep the digits and
 * overflow, sign, dot, invalid bits
 */
SSD Display;

/*
 * initiation for keypad pins
 */
void init_SSD();

/*
 * This function ensures that the digits on the display
 * are lit by quickly flashing the digits.
 */
void display_SSD();

/*
 * the cases which are inside of this func show that
 * how to display the character
 */
void printDigit_SSD(uint8_t);

void displayID_SSD();

/*
 * when the result bigger than 9999 or less than -999
 * display shows that OuFL
 */
void overflow_SSD();

/*
 * when the operation is invalid i.e. 3/0 or sqrt(-2))
 * display shows that Invd
 */
void invalid_SSD();

/*
 * separates the incoming result into digit
 * and we can see that if number is negative or
 * not through sign bit
 */
void utility_SSD(float var);

/*
 * It determines which character should be lit on which
 * digit by assigning case values to digit.
 */
void displaychar_SSD(uint8_t x);

#endif /* DISPLAY_H_ */
