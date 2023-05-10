#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header.h"



float Perkalian(float bilangan1, float bilangan2){
	return bilangan1*bilangan2;
}

float akar_pangkat_n(int x,int n){
 double eps = 1e-8;  // toleransi error
    double a, b, c;
    if (x >= 0) {  // jika x >= 0, maka interval awal adalah [0, x]
        a = 0;
        b = x;
    } else {       // jika x < 0 dan n ganjil, maka interval awal adalah [x, 0]
        if (n % 2 == 1) {
            a = x;
            b = 0;
        } else {   // jika x < 0 dan n genap, maka akar tidak terdefinisi
            printf("Akar tidak terdefinisi\n");
            return 0;
        }
    }
    c = (a + b) / 2;
    while (fabs(pow(c, n) - x) > eps) {
        if (pow(c, n) < x) {
            a = c;
        } else {
            b = c;
        }
        c = (a + b) / 2;
    }
    return c;

}


float Perpangkatan(float bilangan, float pangkat){
 	float hasil,i;
 	hasil=1;
 	i=1;
 	if(bilangan!=0&&pangkat!=0){
	 
 	while(i<=pangkat){
 		hasil=hasil*bilangan;
 		i++;
	 } 
 	return hasil;
 	}else if(bilangan!=0&&pangkat==0){
 		return 1;
	}else{
	 	return 0;
	}
 	
 }
 
 
  void insert_to_history(char *input){
 	FILE *file;
 	if((file = fopen ("History.txt","a"))==NULL){
 		printf("file yang dimasukkan tidak ada");
		fclose(file);
	}else{
		fputs(input,file);
		fclose(file);
	}
	
 }
 
 void tampilkan_history(){
 	FILE *file;
 	char buff[255];
 	if((file =fopen("History.txt","r"))==NULL){
 		printf("FIlE tidak ada");
 		fclose(file);
	 }
 	  while(fgets(buff, sizeof(buff), file)){
        printf("%s", buff);
    }
    fclose(file);
 }
 
