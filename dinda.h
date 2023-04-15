#ifndef operasi_h
#define operasi_h
#include <stdio.h>
#define PI 3.14159265358979323846
#define SUDUT 180.0
#include <math.h>


double operasiPembagian(double bilangan1, double bilangan2){
	return bilangan1/bilangan2;
}

float operasiSinus(float sudut){
	float rad=sudut*(PI/180);
	
	return sin(rad);
}

float operasiCosinus(float sudut){
	float rad=sudut*(PI/180);
	
	return cos(rad);
}

float operasiTangen(float sudut){
	float rad=sudut*(PI/180);
	
	return tan(rad);
}

float operasiCosecan(float sudut){
	return 1/operasiSinus(sudut);
}

float operasiSecan(float sudut){
	return 1/operasiCosinus(sudut);
}

float operasiCotangen(float sudut){
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

#endif



