#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float hasil;
	char input[30],temp;
	char lagi;
	Stack S;
	Queue Z;
	node Q;
	for(;;){
		system("cls");
		address P;
		Z.First=NULL;
		Z.Last=NULL;
		Z.invalid=0;
		S.Head=NULL;
		menu();
		printf("\n\t\t\tenter expression:");
		scanf("%s",&input);
		fflush(stdin);
		convertPostfix(&Z,&S,input);
		if(Z.invalid==0){
			P=Create_Tree(Z);
			hasil=kalkulasi(P);
			printf("\n\t\t\thasilnya adalah %g\n",hasil);
			printf("\t\t\tPostOrder: ");
			PostOrder(P);
			printf("\n\t\t\tLagi?(y/n)");
			fflush(stdin);
			scanf("%c", &lagi);
			if(lagi=='n'){
				return 0;
			}else{
				P->left=NULL;
				P->right=NULL;
				free(P);
			}
		}else{
			printf("\n");
			system("pause");
		}
	}
}

//	temp=PopStack(&X);
//	ViewAsc(Z);
//	ViewAscStack(X);
//	printf("input: %s", input);
//	InfixToPostfix("1*(2+3)/4^5-6", postfix);
//	printf("postfix: %s", postfix);
