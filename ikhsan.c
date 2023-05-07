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

int validasiLogarithm(char *op){
	if(strcmp(op,"log(")==0){
		return 1;
	}
	else if (strcmp(op,"ln(")==0){
		return 1;
	}
	else{
		printf("\t\t\tInvalid Operator", op);
        return 0;
	}
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
}
