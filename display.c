/*
 * display.c
 *
 *  Created on: Dec 19, 2020
 *      Author: Mehmet Akif/171024027
 *
 */

#include "display.h"

void init_SSD(){
	GPIOB->MODER &= ~(3U << 2*1);
	GPIOB->MODER |= (1U << 2*1);//PB1 is output

	GPIOB->MODER &= ~(3U << 2*3);
	GPIOB->MODER |= (1U << 2*3);//PB3 is output

	GPIOB->MODER &= ~(3U << 2*6);
	GPIOB->MODER |= (1U << 2*6);//PB6 is output

	GPIOB->MODER &= ~(3U << 2*7);
	GPIOB->MODER |= (1U << 2*7);//PB7 is output

	GPIOA->MODER &= ~(3U << 2*0);
	GPIOA->MODER |= (1U << 2*0);//PA0 is output

	GPIOA->MODER &= ~(3U << 2*1);
	GPIOA->MODER |= (1U << 2*1);//PA1 is output

	GPIOA->MODER &= ~(3U << 2*4);
	GPIOA->MODER |= (1U << 2*4);//PA4 is output

	GPIOA->MODER &= ~(3U << 2*5);
	GPIOA->MODER |= (1U << 2*5);//PA5 is output

	GPIOA->MODER &= ~(3U << 2*6);
	GPIOA->MODER |= (1U << 2*6);//PA6 is output

	GPIOA->MODER &= ~(3U << 2*7);
	GPIOA->MODER |= (1U << 2*7);//PA7 is output

	GPIOA->MODER &= ~(3U << 2*11);
	GPIOA->MODER |= (1U << 2*11);//PA11 is output

	GPIOA->MODER &= ~(3U << 2*12);
	GPIOA->MODER |= (1U << 2*12);//PA12 is output


}

void display_SSD(){

	static int i = 0;
		if(Display.Inv == 1){
			invalid_SSD();

		}
		else if(Display.Oflw == 1){
			overflow_SSD();

		}

		if(i == 1){
			GPIOA->ODR |= (1U << 7); //PA7
			GPIOB->ODR &= ~(1U << 6); //PB6
			GPIOB->ODR &= ~(1U << 7); //PB7
			GPIOB->ODR &= ~(1U << 1); //PB1
			printDigit_SSD(Display.Digits[0]);
			GPIOA->ODR |= ( 1U << 6); // PA6
			if(Display.dot == 0) GPIOA->ODR &= ~( 1U << 6);
		}
		else if(i == 10){
			GPIOA->ODR &= ~(1U << 7); //PA7
			GPIOB->ODR |= (1U << 6); //PB6
			GPIOB->ODR &= ~(1U << 7); //PB7
			GPIOB->ODR &= ~(1U << 1); //PB1
			printDigit_SSD(Display.Digits[1]);
			GPIOA->ODR |= ( 1U << 6); // PA6
			if(Display.dot == 1) GPIOA->ODR &= ~( 1U << 6);
		}

		else if(i == 20){
			GPIOA->ODR &= ~(1U << 7); //PA7
			GPIOB->ODR &= ~(1U << 6); //PB6
			GPIOB->ODR |= (1U << 7); //PB7
			GPIOB->ODR &= ~(1U << 1); //PB1
			printDigit_SSD(Display.Digits[2]);
			GPIOA->ODR |= ( 1U << 6); // PA6
			if(Display.dot == 2) GPIOA->ODR &= ~( 1U << 6);
		}
		else if(i == 30){
			GPIOA->ODR &= ~(1U << 7); //PA7
			GPIOB->ODR &= ~(1U << 6); //PB6
			GPIOB->ODR &= ~(1U << 7); //PB7
			GPIOB->ODR |= (1U << 1); //PB1
			printDigit_SSD(Display.Digits[3]);
			GPIOA->ODR |= ( 1U << 6); // PA6
			if(Display.dot == 3) GPIOA->ODR &= ~( 1U << 6);
		}
		else if(i == 40) i = 0;

		i++;




}

void printDigit_SSD(uint8_t x){

		switch(x){
		case 0:		//0

			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR |=  ( 1U << 11); // PA11

			break;

		case 1:		//1
			GPIOB->ODR |= ( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR |= ( 1U << 4); // PA4
			GPIOA->ODR |= ( 1U << 5); // PA5
			GPIOA->ODR |= ( 1U << 12); // PA12
			GPIOA->ODR |= ( 1U << 11); // PA11

			break;

		case 2:		//2
			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR |=  ( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR |=  ( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11

			break;

		case 3:		//3

			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR |=  ( 1U << 5); // PA5
			GPIOA->ODR |=  ( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11

			break;

		case 4:		//4
			GPIOB->ODR |=  ( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR |=  ( 1U << 4); // PA4
			GPIOA->ODR |=  ( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11

			break;

		case 5:		//5

			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR |=  ( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR |=  ( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11

			break;

		case 6:		//6
			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR |=  ( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11

			break;

		case 7:		//7

			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR |=  ( 1U << 4); // PA4
			GPIOA->ODR |=  ( 1U << 5); // PA5
			GPIOA->ODR |=  ( 1U << 12); // PA12
			GPIOA->ODR |=  ( 1U << 11); // PA11

			break;

		case 8:		//8

			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11

			break;

		case 9:		//9
			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR |=  ( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11

			break;

		case 10://A

			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR |=  ( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11



			break;

		case 11://B

			GPIOB->ODR |=  ( 1U << 3); // PB3
			GPIOA->ODR |=  ( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11


			break;

		case 12://C
			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR |=  ( 1U << 0); // PA0
			GPIOA->ODR |=  ( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR |=  ( 1U << 11); // PA11

			break;

		case 13://D
			GPIOB->ODR |=  ( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR |=  ( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11

			break;

		case 14://E
			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR |=  ( 1U << 0); // PA0
			GPIOA->ODR |=  ( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11


			break;

		case 15: //F
			GPIOB->ODR &= ~( 1U << 3); // PB3
			GPIOA->ODR |=  ( 1U << 0); // PA0
			GPIOA->ODR |=  ( 1U << 1); // PA1
			GPIOA->ODR |=  ( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11
			break;


		case 30: //u
			GPIOB->ODR |=  ( 1U << 3); // PB3
			GPIOA->ODR |=  ( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR |=  ( 1U << 12); // PA12
			GPIOA->ODR |=  ( 1U << 11); // PA11
			break;

		case 31: //L
			GPIOB->ODR |=  ( 1U << 3); // PB3
			GPIOA->ODR |=  ( 1U << 0); // PA0
			GPIOA->ODR |=  ( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR &= ~( 1U << 12); // PA12
			GPIOA->ODR |=  ( 1U << 11); // PA11
			break;

		case 32: //n
			GPIOB->ODR |=  ( 1U << 3); // PB3
			GPIOA->ODR |=  ( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR |=  ( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR |=  ( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11
			break;

		case 33: //D
			GPIOB->ODR |=  ( 1U << 3); // PB3
			GPIOA->ODR &= ~( 1U << 0); // PA0
			GPIOA->ODR &= ~( 1U << 1); // PA1
			GPIOA->ODR &= ~( 1U << 4); // PA4
			GPIOA->ODR &= ~( 1U << 5); // PA5
			GPIOA->ODR |=  ( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11
			break;

		case 34: // negative sign
			GPIOB->ODR |= ( 1U << 3); // PB3
			GPIOA->ODR |= ( 1U << 0); // PA0
			GPIOA->ODR |= ( 1U << 1); // PA1
			GPIOA->ODR |= ( 1U << 4); // PA4
			GPIOA->ODR |= ( 1U << 5); // PA5
			GPIOA->ODR |= ( 1U << 12); // PA12
			GPIOA->ODR &= ~( 1U << 11); // PA11
			break;

		case 35: // space
			GPIOB->ODR |= ( 1U << 3); // PB3
			GPIOA->ODR |= ( 1U << 0); // PA0
			GPIOA->ODR |= ( 1U << 1); // PA1
			GPIOA->ODR |= ( 1U << 4); // PA4
			GPIOA->ODR |= ( 1U << 5); // PA5
			GPIOA->ODR |= ( 1U << 12); // PA12
			GPIOA->ODR |= ( 1U << 11); // PA11
			break;
		}
}


void displaychar_SSD(uint8_t x){
	Display.dot = 5;
	switch(x){
	case 0:	//-
		Display.Digits[0] = 34;
		Display.Digits[1] = 35;
		Display.Digits[2] = 35;
		Display.Digits[3] = 35;
		break;
	case 1: //'A'
		Display.Digits[3] = 10;
		Display.Digits[0] = 35;
		Display.Digits[2] = 35;
		Display.Digits[1] = 35;
		break;
	case 2: //'B'
		Display.Digits[3] = 11;
		Display.Digits[1] = 35;
		Display.Digits[2] = 35;
		Display.Digits[0] = 35;
		break;
	case 3:  //'C'
		Display.Digits[3] = 12;
		Display.Digits[1] = 35;
		Display.Digits[2] = 35;
		Display.Digits[0] = 35;
		break;
	case 4:	//'D'
		Display.Digits[3] = 13;
		Display.Digits[1] = 35;
		Display.Digits[2] = 35;
		Display.Digits[0] = 35;
		break;
	case 5:  //'E'
		Display.Digits[3] = 14;
		Display.Digits[2] = 35;
		Display.Digits[1] = 35;
		Display.Digits[0] = 35;
		break;
	case 6:	//'EA'
		Display.Digits[3] = 14;
		Display.Digits[2] = 10;
		Display.Digits[1] = 35;
		Display.Digits[0] = 35;
		break;
	case 7:	//'EB'
		Display.Digits[3] = 14;
		Display.Digits[2] = 11;
		Display.Digits[1] = 35;
		Display.Digits[0] = 35;
		break;
	case 8:	//'EC'
		Display.Digits[3] = 14;
		Display.Digits[2] = 12;
		Display.Digits[1] = 35;
		Display.Digits[0] = 35;
		break;
	case 9:	//'ED'
		Display.Digits[3] = 14;
		Display.Digits[2] = 13;
		Display.Digits[1] = 35;
		Display.Digits[0] = 35;
		break;
	case 10:	//'EE'
		Display.Digits[3] = 14;
		Display.Digits[2] = 14;
		Display.Digits[1] = 35;
		Display.Digits[0] = 35;
		break;
	case 11:	//'EEA'
		Display.Digits[3] = 14;
		Display.Digits[2] = 14;
		Display.Digits[1] = 10;
		Display.Digits[0] = 35;
		break;
	case 12:	//'EEB'
		Display.Digits[3] = 14;
		Display.Digits[2] = 14;
		Display.Digits[1] = 11;
		Display.Digits[0] = 35;
		break;
	case 13:	//'EEC'
		Display.Digits[3] = 14;
		Display.Digits[2] = 14;
		Display.Digits[1] = 12;
		Display.Digits[0] = 35;
		break;
	case 14:	//'EED'
		Display.Digits[3] = 14;
		Display.Digits[2] = 14;
		Display.Digits[1] = 13;
		Display.Digits[0] = 35;
		break;
	case 20: // 0uFL
		Display.Digits[0] = 31;
		Display.Digits[1] = 15;
		Display.Digits[2] = 30;
		Display.Digits[3] = 0;
		break;
	case 21: // InuD
		Display.Digits[0] = 33;
		Display.Digits[1] = 30;
		Display.Digits[2] = 32;
		Display.Digits[3] = 1;

		break;
	}
}

void displayID_SSD(){
	Display.Digits[0]= 7;
	Display.Digits[1]= 2;
	Display.Digits[2]= 7;
	Display.Digits[3]= 1;


}

void overflow_SSD(){

	displaychar_SSD(20);

	Display.Oflw = 0;
	calculation.current_process=0;
	calculation.x=0;
	calculation.y=0;
	calculation.result=0;

}

void invalid_SSD(void){

	displaychar_SSD(21);

	Display.Inv = 0;
	calculation.current_process=0;
	calculation.x=0;
	calculation.y=0;
	calculation.result=0;

}

void utility_SSD(float var){

	int number = (int)var;

	float i = 0.0;

	if((number < 0) & (number >= -999)){
		Display.sign = 1;
		i = -1.0;
		Display.dot = 0;
		if(number >= -99){
			i = -10.0;
			Display.dot = 1;
			if(number >= -9){
				i = -100.0;
				Display.dot = 2;
			}
		}
	}
	else if((number >= 0) & (number <= 9999)){
		Display.sign = 0;
		i = 1.0;
		Display.dot = 0;
		if(number <= 999){
			i = 10.0;
			Display.dot = 1;
			if(number <= 99){
				i = 100.0;
				Display.dot = 2;
				if(number <= 9){
					i = 1000.0;
					Display.dot = 3;
				}
			}
		}
	}


	number = (int)(var * i);

	int temp = number / 10;
	Display.Digits[0] = (uint8_t)(number - (temp*10));

	temp = number / 100;
	Display.Digits[1] = (uint8_t)((number - (temp * 100)) / 10);

	temp = number / 1000;
	Display.Digits[2] = (uint8_t)((number - (temp * 1000)) / 100);

	temp = number / 10000;
	Display.Digits[3] = (uint8_t)((number - (temp * 10000)) / 1000);

	// negative sign
	if (Display.sign) Display.Digits[3] = 34;

}

