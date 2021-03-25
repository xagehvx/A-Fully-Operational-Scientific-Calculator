/*
 * calc.c
 *
 *  Created on: Dec 20, 2020
 *      Author: Mehmet Akif/171024027
 */
#include "calc.h"

#define PI 3.141
/*
 * Process has processnumber and
 * functions
 */
process funcArr[] = {
		{none,nonefunc},
		{Addition, AdditonFunc},
		{Substraction, SubstractionFunc},
		{Multiplacation, MultiplacationFunc},
		{Division, DivisionFunc},
		{E, Efunc},
		{Log, logFunc},
		{Ln, LnFunc},
		{Sqrt, SqrtFunc},
		{Pow2, Pow2Func},
		{EE, EEFunc},
		{Sin, SinFunc},
		{Cos, CosFunc},
		{Tan, TanFunc},
		{Cot, CotFunc},
};

/*
 * this func show that which func we have to go
 * according to enum
 */
void calculate(){
	funcArr[calculation.current_process].func();
}

/*none func for enum 0*/
void nonefunc(){
}

void AdditonFunc(){

	float c= calculation.x + calculation.y;
	if(c>9999){
		Display.Oflw=1;
	}
	else calculation.result=c;

}

void SubstractionFunc(){
		float c = calculation.x-calculation.y;

		if(c<-999){
			Display.Oflw=1;
		}
		else calculation.result=c;
}

void MultiplacationFunc(){
		float c = calculation.x * calculation.y;
		if((c>9999) | (c<-999)){
			Display.Oflw=1;
		}
		else calculation.result=c;

}
void DivisionFunc(){

	if(calculation.y==0){
		Display.Inv=1;
	}
	else  calculation.result = calculation.x/calculation.y;

}
/*empty func for enum 5*/
void Efunc(){
}
void logFunc(){
	if(calculation.x==0){
		Display.Inv=1;
	}
	else{
		calculation.result = log10(calculation.x);
	}
}
void LnFunc(){
	if(calculation.x==0){
		Display.Inv=1;
	}
	else{
		calculation.result = log(calculation.x);
	}
}
void SqrtFunc(){
	if(calculation.x<0){
		Display.Inv=1;
	}
	else{
		calculation.result = sqrt(calculation.x);
	}

}
/* x^2*/
void Pow2Func(){
	calculation.result = pow(calculation.x,2);
}
/*empty func for enum 10*/
void EEFunc(){
}
void SinFunc(){
	float c=(calculation.x * PI) / 180;
	calculation.result = sin(c);
}
void CosFunc(){
	float c=(calculation.x * PI) / 180;
	calculation.result = cos(c);
}
void TanFunc(){

	float c=(calculation.x * PI) / 180;
	if(cos(c)==0){
		Display.Inv=1;
	}
	else calculation.result = (sin(c)/cos(c));

}
void CotFunc(){
	float c=(calculation.x * PI) / 180;
	if(sin(c)==0){
		Display.Inv=1;
	}
	else calculation.result = (cos(c)/sin(c));
}




