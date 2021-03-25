/*
 * calc.h
 *
 *  Created on: Dec 20, 2020
 *      Author: Mehmet Akif/171024027
 */

#ifndef CALC_H_
#define CALC_H_

#include "display.h"
#include "main.h"
/*
 * enum for func
 */
typedef enum{
	none,
	Addition,
	Substraction,
	Multiplacation,
	Division,
	E,
	Log,
	Ln,
	Sqrt,
	Pow2,
	EE,
	Sin,
	Cos,
	Tan,
	Cot
}calculator;

/*
 * the variables struct keep the
 * data which are number1 number2
 * and process number
 */

typedef struct{
	float x;
	float y;
	float result;
	uint8_t current_process;
}variables;

variables calculation;

typedef void (*funcptr)(void);

typedef struct{
	calculator processnumber;
	funcptr    func;
}process;



void calculate();
void nonefunc();
void AdditonFunc();
void SubstractionFunc();
void MultiplacationFunc();
void DivisionFunc();
void Efunc();
void logFunc();
void LnFunc();
void SqrtFunc();
void Pow2Func();
void EEFunc();
void SinFunc();
void CosFunc();
void TanFunc();
void CotFunc();


#endif /* CALC_H_ */
