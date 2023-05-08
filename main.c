#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float hasil;
	char input[30],temp;
	char lagi;
	int valid;
	Stack S;
	Queue Z;
	node Q;
	do{
		system("cls");
		address P;
		valid=1;
		Z.First=NULL;
		Z.Last=NULL;
//		Z.invalid=0;
		S.Head=NULL;
		menu();
		printf("\n\t\t\tenter expression:");
		scanf("%s",&input);
		fflush(stdin);
		convertPostfix(&Z,&S,input,&valid);
		if(valid==1){
			P=Create_Tree(Z);
			hasil=kalkulasi(P);
			printf("\n\t\t\thasilnya adalah %.2f\n",hasil);
			printf("\t\t\tPostOrder: ");
			PostOrder(P);
		}else if(valid==3){
			printf("\t\t\tln(0)=Tidak Terdefinisi");
		}else{
			printf("\t\t\tInvalid Operator");
		}
		fflush(stdin);
		printf("\n\t\t\tLagi?(y/n)");
		scanf("%c", &lagi);
	}while(lagi=='y');
	
	return 0;
}

//	temp=PopStack(&X);
//	ViewAsc(Z);
//	ViewAscStack(X);
//	printf("input: %s", input);
//	InfixToPostfix("1*(2+3)/4^5-6", postfix);
//	printf("postfix: %s", postfix);
