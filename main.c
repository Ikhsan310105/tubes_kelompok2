#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float hasil;
	char input[30],temp,temp1[20];
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
			insert_to_history(input);
			P=Create_Tree(Z);
			printTree(P,0);
			hasil=kalkulasi(P);
			gcvt(hasil,20,temp1);
			insert_to_history("=");
			insert_to_history(temp1);
			insert_to_history("\n");
			insert_to_history("--------------------------------------------------------------------");
			insert_to_history("\n");
			printf("\n\t\t\thasilnya adalah %.2f\n",hasil);
			printf("\t\t\tPostOrder: ");
			PostOrder(P);
		}else{
			printf("\t\t\tMATH ERROR");
		}
		fflush(stdin);
		printf("\n Lakukan Operasi Lagi?(y/n/h/l)\ny:lakukan lagi\nn:berhenti dan keluar\nh:masuk ke histori kalkulator\nl:List aturan aritmatika\nPilihan Anda:");
		scanf("%c", &lagi);fflush(stdin);
			while(lagi=='h'){
			system ("cls");
			tampilkan_history();
			printf("\n Lakukan Operasi Lagi?(y/n/h/l)\ny:lakukan lagi\n:berhenti dan keluar\nh:masuk ke histori kalkulator\nl:List aturan aritmatika\nPilihan Anda:");
			scanf("%c", &lagi);fflush(stdin);
		}
		while(lagi=='l'){
			system ("cls");
			help();
			printf("\n Lakukan Operasi Lagi?(y/n/h/l)\ny:lakukan lagi\n:berhenti dan keluar\nh:masuk ke histori kalkulator\nl:List aturan aritmatika\nPilihan Anda:");
			scanf("%c", &lagi);fflush(stdin);
		}
	}while(lagi=='y');
	
	return 0;
}


