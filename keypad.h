/*
 * keypad.h
 *
 *  Created on: Dec 19, 2020
 *      Author: Mehmet Akif/171024027
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include"main.h"

/*Keypad related function*/
void keypad_init();		//initiation for keypad pins
void clear_rows_keypad(); // set 0  keypad rows
void set_rows_keypad(); // set 1 keypad rows


/* taken data from button which is pressed
 and figure out which button is this*/
void Keypad_data(uint8_t a);


#endif /* KEYPAD_H_ */
