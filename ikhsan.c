#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header.h"

float logarithm(double number, double base);
float naturalLogarithm(double number);

//rumus logaritma
float logarithm(double number, double base)
{   
    return log(number)/log(base);
}

//rumus logaritma natural
float naturalLogarithm(double number)
{	
    return log(number);
}

float processLogarithm(float number, float base, char *op){
	int baseInt = base;
	float baseDouble = 10;
	
	if(strcmp(op,"log(")==0){
		return logarithm(number,base);
	}
	else if (strcmp(op,"ln(")==0){
		return naturalLogarithm(number);
	}
	else{
		printf("\t\t\tOperator is invalid: %s", op);
        exit(1);
	}
}
