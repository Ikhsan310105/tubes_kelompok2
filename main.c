#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float hasil;
	char input[30],temp,temp1[20];
	char lagi;
	bool valid;
	Queue Z;
	
	do{
		system("cls");
		address P;
		valid=true;
		Z.First=NULL;
		Z.Last=NULL;
		menu();
		printf("\tH:masuk ke histori kalkulator\n\t\t\tL:List aturan aritmatika");
		printf("\n\n\t\t\tenter expression:");
		scanf("%s",&input);
		if(input[0]=='C' && input[1]=='\0'||input[0]=='c' && input[1]=='\0'){
			return 0;
		}else if(input[0]=='L' && input[1]=='\0'||input[0]=='l' && input[1]=='\0'){
			system ("cls");
			help();
			printf("\nLakukan Operasi Lagi?(y/n/h/l)\ny:lakukan lagi\nn:berhenti dan keluar\n\nPilihan Anda:");
			fflush(stdin);
			scanf("%c",&lagi);
		}else if(input[0]=='H' && input[1]=='\0'||input[0]=='h' && input[1]=='\0'){
			system ("cls");
			tampilkan_history();
			printf("\nLakukan Operasi Lagi?(y/n/h/l)\ny:lakukan lagi\nn:berhenti dan keluar\n\nPilihan Anda:");
			fflush(stdin);
			scanf("%c", &lagi);
		}else{
			fflush(stdin);
			convertPostfix(&Z,input,&valid);
			if(valid==true){
				insert_to_history(input);
				P=Create_Tree(Z);
				hasil=kalkulasi(P);
				gcvt(hasil,20,temp1);
				insert_to_history("=");
				insert_to_history(temp1);
				insert_to_history("\n");
				insert_to_history("--------------------------------------------------------------------");
				insert_to_history("\n");
				printf("\t\t\thasilnya adalah %.2f\n", hasil);
//				printTree(P,0);
//				printf("\n\t\t\tPostOrder: ");
//				PostOrder(P);
			}else{
				printf("\t\t\tMATH ERROR \n");
			}
			fflush(stdin);
			printf("\n\t\t\tLakukan Operasi Lagi?(y/n/h/l)\n\t\t\ty:lakukan lagi\n\t\t\tn:berhenti dan keluar\n\t\t\tH:masuk ke histori kalkulator\n\t\t\tL:List aturan aritmatika\n\t\t\tPilihan Anda:");
			scanf("%c", &lagi);fflush(stdin);
			while(lagi=='H'||lagi=='h'){
				system ("cls");
				tampilkan_history();
				printf("\nLakukan Operasi Lagi?(y/n/h/l)\ny:lakukan lagi\nn:berhenti dan keluar\nH:masuk ke histori kalkulator\nL:List aturan aritmatika\n\nPilihan Anda:");
				scanf("%c", &lagi);fflush(stdin);
			}
			while(lagi=='l'||lagi=='L'){
				system ("cls");
				help();
				printf("\n\nLakukan Operasi Lagi?(y/n/h/l)\ny:lakukan lagi\nn:berhenti dan keluar\nH:masuk ke histori kalkulator\nL:List aturan aritmatika\n\nPilihan Anda:");
				scanf("%c", &lagi);fflush(stdin);
			}
		}
	}while(lagi=='y'||lagi=='Y');
	
	return 0;
}


