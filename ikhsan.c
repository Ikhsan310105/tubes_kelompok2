#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header.h"

double logarithm(double number, double base)
{   
    return log(number)/log(base);
}

double naturalLogarithm(double number)
{	
    return log(number);
}


//				while(input[i]!=')'){
//					if(isdigit(input[i]) || input[i]=='.'){
//						num[j++]=input[i];
//					} else{
//						log[x++]=input[i];
//					}
//					i++;
//				}
//				num[j]='\0';
//				angka=strtof(num, NULL);
//				hasil=processLogarithm(angka,10,log,&*valid);
//				EnqueOperand(&*Z, hasil);

//				while(input[i]!=')'){
//					if(isdigit(input[i]) || input[i]=='.'){
//						num[j++]=input[i];
//					} else{
//						log[x++]=input[i];
//					}
//					i++;
//				}
//				num[j]='\0';
//				angka=strtof(num, NULL);
//				hasil=processLogarithm(angka,10,log,&*valid);
//				EnqueOperand(&*Z, hasil);	

//			char log[6];
//			char Num[20];
//			float angka;
//			float a,hasil;
//			int h=0;
//			int j = 0,x = 0;
//			if(isdigit(input[i-1])){
//				a=DequeOperand(&*Z);
//				while(input[i]!=')'){
//					if(isdigit(input[i]) || input[i]=='.'){
//						Num[j++]=input[i];
//					} else{
//						log[x++]=input[i];
//					}
//					i++;
//				}
//				Num[j]='\0';
//				angka=strtof(Num, NULL);
//				hasil=processLogarithm(angka,a,log,&*valid);
//				EnqueOperand(&*Z, hasil);	
//			}else{
//				while(input[i]!=')'){
//					if(isdigit(input[i]) || input[i]=='.'){
//						Num[j++]=input[i];
//					} else{
//						log[x++]=input[i];
//					}
//					i++;
//				}
//				Num[j]='\0';
//				angka=strtof(Num, NULL);
//				hasil=processLogarithm(angka,10,log,&*valid);
//				EnqueOperand(&*Z, hasil);	
//			}
