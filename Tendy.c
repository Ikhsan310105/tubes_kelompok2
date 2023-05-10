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
 
 void help(){
 	printf("\t\t\t Aturan Kalkulator\n");
 	printf("1 TrigonoMetri: pada penggunaan trigono metri digunakan format sebagai berikut:(simbol trigonometri)(angka)\n");
	printf("Misal: sin(90) atau 90sin(30)\n");
	printf("2 Logaritma: pada penggunaan operasi logaritma digunakan format sebagai berikut: (basis bebas)log(angka) atau tanpa basis bebas sekalipun\n");
	printf("Misal: log(100) atau 2log(8) dsb\n");
	printf("3. Akar: pada penggunaan operasi akar disini digunaka format sebagai berikut: (pangkat akar)v(angka)\n");
	printf("Misal: 2v4 atau 3v8\n");
	
}


 void printTree(address root, int space) {
    if (root == NULL) {
        return;
    }
    int i;
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (i = 5; i < space; i++) {
        printf(" ");
    }
    if(root->data!='\0'){
    printf("%c\n", root->data);
	}else{
		printf("%.2f",root->operand);
	}
    printTree(root->left, space);
}
