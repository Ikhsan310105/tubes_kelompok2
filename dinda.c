#include <stdio.h>
#define PI 3.14159265358979323846
#define SUDUT 180.0
#include <math.h>
#include "header.h"


double operasiPembagian(double bilangan1, double bilangan2){
	return bilangan1/bilangan2;
}

double operasiSinus(double sudut){
	double rad=sudut*(PI/180);
	
	return sin(rad);
}

double operasiCosinus(double sudut){
	double rad=sudut*(PI/180);
	
	return cos(rad);
}

double operasiTangen(double sudut){
	double rad=sudut*(PI/180);
	
	return tan(rad);
}

double operasiCosecan(double sudut){
	return 1/operasiSinus(sudut);
}

double operasiSecan(double sudut){
	return 1/operasiCosinus(sudut);
}

double operasiCotangen(double sudut){
	return 1/operasiTangen(sudut);
}

//fungsi operasi Asin
double operasiAsin(double bilangan){
    if(bilangan>1 || bilangan<-1)
    {
        printf("not define\n");
    }
    else
    {
        return asin(bilangan)* SUDUT/ PI;
    }
}


//fungsi operasi Acos
double operasiAcos(double bilangan) {
	if(bilangan>1 || bilangan<-1)
    {
        printf("not define\n");
    }
    else
    {
		return acos(bilangan)*SUDUT/ PI;
    }
    
}

//fungsi operasi Atan
double operasiAtan(double bilangan) {
    return atan(bilangan) * SUDUT/ PI;
}





