#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float hasil;
	char input[30],temp;
	char lagi;
	int valid;
	Queue Z;
	
	do{
		system("cls");
		address P;
		valid=1;
		Z.First=NULL;
		Z.Last=NULL;
		menu();
		printf("\n\t\t\tenter expression:");
		scanf("%s",&input);
		fflush(stdin);
		convertPostfix(&Z,input,&valid);
		if(valid==1){
			P=Create_Tree(Z);
			hasil=kalkulasi(P);
			printf("\n\t\t\thasilnya adalah %.2f\n",hasil);
			printf("\t\t\tPostOrder: ");
			PostOrder(P);
		}else{
			printf("\t\t\tMATH ERROR");
		}
		fflush(stdin);
		printf("\n\t\t\tLagi?(y/n)");
		scanf("%c", &lagi);
	}while(lagi=='y');
	
	return 0;
}


