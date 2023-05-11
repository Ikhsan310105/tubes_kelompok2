#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "header.h"

void PostOrder(address P){
	
	if(P!=Nil){
		PostOrder(left(P));
		PostOrder(right(P));
		if(P->data!='\0'){
			printf("%c ", P->data);
		}else{
			printf("%g ",P->operand);
		}
	}
}

 Stack PushStack(Stack First, char item){
	node P;
	P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{

		P->oprtr=item;
		P->next=NULL;
		if(First.Head==NULL){
			First.Head=P;
			First.Head->next=NULL;	
		}else{
			P->next=First.Head;
			First.Head=P;
		}
	
	return First;
	}
}

char PopStack(Stack *First){
	node P;
	P=First->Head;
	First->Head=P->next;
	return P->oprtr;
	free(P);
}


void ViewAsc(Queue First){
	node P;
	P=First.First;
	if(P!=NULL){
		
		while(P!=NULL){
			if(P->oprtr!='\0'){
				printf("%c ",P->oprtr);
			}else{
				printf("%g ",P->operand);
			}
		P=P->next;
		}
	}
	else if(P==NULL){
		printf("list kosong");
	}
}

void ViewAscStack(Stack First){
	node P;
	P=First.Head;
	if(P!=NULL){
		
		while(P!=NULL){
			if(P->oprtr!='\0'){
				printf("%c ",P->oprtr);
			}else{
				printf("%g ",P->operand);
			}
		P=P->next;
		}
	}
	else if(P==NULL){
		printf("list kosong");
	}
}

node CreateNodeList(){
	node P;
	
	P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{
		(P)->next=NULL;
		(P)->oprtr='\0';
	} 
	
	return P;
}

void EnqueOperator(Queue *Q, char item){
	node P;
	
	P=CreateNodeList();
	P->oprtr=item;
	if(Q->First==NULL){
		Q->First=P;
		Q->Last=P;
		Q->Last->next=NULL;
	} else{
		P->next=NULL;
		Q->Last->next=P;
		Q->Last=P;
	}
}

void EnqueOperand(Queue *Q, double item){
	node P;
	
	P=CreateNodeList();
	P->operand=item;
	if(Q->First==NULL){
		Q->First=P;
		Q->Last=P;
		Q->Last->next=NULL;
	} else{
		P->next=NULL;
		Q->Last->next=P;
		Q->Last=P;
	}
}

void convertPostfix(Queue *Z, char *input, int *valid){
	node P;
	Stack X;
	char token, c, negatif;
	int num3=10;
	int i,temp;
	double num=0,num2;
	double angka;
	int j;
	
	X.Head=NULL;
	for(i=0;i<strlen(input);i++){
		token=input[i];
		if(isdigit(token)||token=='.'||(token=='-'&&(isOperator(input[i-1])||i==0||input[i-1]=='('))){
			if(isdigit(token)){
				num=num*10+(token-'0');
			}else if(token=='.'){
				i++;
				while(isdigit(input[i])){
				num2=(input[i]-'0');
				num=num+(num2/num3);	
				num3=num3*10;
				i++;
			}
			num3=10;
			i--;
			}else if(token=='-'){
				negatif='-';
			}
			 if(isdigit(input[i+1])!=1&&input[i+1]!='.'){
			 	if(negatif=='-'){
			 		num=num*-1;
				 }
				negatif='\0';
				EnqueOperand(&*Z, num);
				num=0;
			}
		}else if (token=='s' || token=='c' || token=='t' || token=='a'){
			char trigono[7];
			char sudut[20];
			int x=0;
			j=0;
			float f;
			double hasil;
			if(!isdigit(input[i-1])){
				while(input[i]!=')'&&i<strlen(input)){
					if(isdigit(input[i]) || input[i]=='.'){
						sudut[j++]=input[i];
					} else{
						trigono[x++]=input[i];
					}
					i++;
				}
				if(input[i]!=')'){
					*valid=0;
				}
				sudut[j]='\0';
				angka=strtod(sudut, NULL);
				hasil=prosesPerhitunganTrigonometri(angka,trigono,&*valid);
				EnqueOperand(&*Z, hasil);	
			}
			else{
				f=DequeOperand(&*Z);
				while(input[i]!=')'){
					if(isdigit(input[i]) || input[i]=='.'){
						sudut[j++]=input[i];
					} else{
						trigono[x++]=input[i];
					}
					i++;
				}
				sudut[j]='\0';
				angka=strtod(sudut, NULL);
				hasil=prosesPerhitunganTrigonometri(angka,trigono,&*valid);
				hasil*=f;
				EnqueOperand(&*Z, hasil);
			}
		}else if(isOperator(token)&&X.Head!=NULL&&X.Head->oprtr!='('&&isdigit(input[i-1])){
			c=X.Head->oprtr;
			while(derajatOperator(token)<=derajatOperator(c)&&X.Head!=NULL&&X.Head->oprtr!='('){
				EnqueOperator(&*Z,PopStack(&X));
			}
			X=PushStack(X,token);
		}else if(token==')'){
			c=X.Head->oprtr;
			while(c!='('&&X.Head->next!=NULL){
				EnqueOperator(&*Z,PopStack(&X));
				c=X.Head->oprtr;
			}
			if(c=='('){
				PopStack(&X);
			}else{
				printf("format yang dimasukkan salah\n");
				break;
			}
		}else if(token == 'l'){
			char num[20];
			int x=0;
			j=0;
			double hasil;
			double f,o;
			if(isdigit(input[i-1])){
				o=DequeOperand(&*Z);
				if((input[i+1]=='o')&&(input[i+2]=='g')&&(input[i+3]=='(')){
					i=i+4;
					while((input[i]!=')')&&(isdigit(input[i]))||(input[i]!=')')&&(input[i]=='.')){
						num[j++]=input[i];
						i++;
					}
					num[j]='\0';
					if(input[i]==')'){
						angka=strtof(num, NULL);
						hasil=logarithm(angka,o);
						EnqueOperand(&*Z, hasil);
					}else{
						*valid=0;
					}
				}else{
					*valid=0;
				}	
			}else{
				if((input[i+1]=='o')&&(input[i+2]=='g')&&(input[i+3]=='(')){
					i=i+4;
					while((input[i]!=')')&&(isdigit(input[i]))||(input[i]!=')')&&(input[i]=='.')){
						num[j++]=input[i];
						i++;
					}
					num[j]='\0';
					if(input[i]==')'){
						angka=strtof(num, NULL);
						hasil=logarithm(angka,10);
						EnqueOperand(&*Z, hasil);
					}else{
						*valid=0;
					}
				}else if((input[i+1]=='n')&&(input[i+2]=='(')){
					i=i+3;
					while((input[i]!=')')&&(isdigit(input[i]))||(input[i]!=')')&&(input[i]=='.')){
						num[j++]=input[i];
						i++;
					}
					num[j]='\0';
					if(input[i]==')'){
						angka=strtof(num, NULL);
						if(angka==0){
							*valid=0;
						}else{
							hasil=naturalLogarithm(angka);
							EnqueOperand(&*Z, hasil);
						}
					}else{
						*valid=0;
					}
				}else{
					*valid=0;
				}
			}
		}else if(token=='('){
			X=PushStack(X,token);
		}else if(token=='!'){
			double a,c;
			char t;
			t=token;
			if(isdigit(input[i-1])){
				a=DequeOperand(&*Z);
				c=faktorial(a);
				EnqueOperand(&*Z,c);
				
			}else{
				printf("\t\t\tformat yang anda masukkan salah: ");
			}
		}else if(token=='v'&&!isdigit(input[i-1])){
			i++;
			float hasilakarkuadrat=0;
			int plus=0;
			char num[20];
			float num1;
			while(isdigit(input[i])||input[i]=='.'){
				num[plus++]=input[i];
				i++;
			}
			num1=strtof(num,NULL);
			hasilakarkuadrat=akar_pangkat_n(num1,2);
			EnqueOperand(&*Z,hasilakarkuadrat);
			
		}
		else{
			X=PushStack(X,token);
		}
	}
	while(X.Head!=NULL){
		c=PopStack(&X);
		EnqueOperator(&*Z,c);
	}
	
	
}

address Create_Tree(Queue Z){
	
	address P;
	address stack[50];
	node Q;
	int i, len, top=-1;
	infotype c;
	double d;
	
	Q=Z.First;
	
	while(Q!=NULL){
		if(Q->oprtr!='\0'){
			c=Q->oprtr;
			P=CreateNodeOperator(c);
			right(P)=stack[top--];
			left(P)=stack[top--];
		}else{
			d=Q->operand;
			P=CreateNodeOperand(d);
		}
		stack[++top]=P;
		Q=Q->next;
	}
	return(stack[0]);
}

address CreateNodeOperand(double input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->operand=input;
	P->data='\0';
	P->left=NULL;
	P->right=NULL;
	return P;
	
}

address CreateNodeOperator(char input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->data=input;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}

double kalkulasi(address P){
	if(P->data!='\0'){
		if(P->data=='+'){
			return kalkulasi(P->left) + kalkulasi(P->right);
		}else if(P->data=='-'){
			return kalkulasi(P->left) - kalkulasi(P->right);
		}else if(P->data=='-'){
			return kalkulasi(P->left) - kalkulasi(P->right);
		}else if(P->data=='/'){
			return operasiPembagian(kalkulasi(P->left), kalkulasi(P->right));
		}else if(P->data=='*'){
			return Perkalian(kalkulasi(P->left), kalkulasi(P->right));
		}else if(P->data=='^'){
			return Perpangkatan(kalkulasi(P->left), kalkulasi(P->right));
		}else if(P->data=='v'){
			return akar_pangkat_n(kalkulasi(P->right), kalkulasi(P->left));
		}
	}
	
	return P->operand;
}

double DequeOperand(Queue *A){
	double q;
	node First,Last,Throw;
	First=A->First;
	Last=A->Last;
	if(First==NULL){
		printf("Queue Empty");
	}else{
		if(First!=Last){
			while(First->next!=Last){
				First=First->next;
			}
			Throw=Last;
			q=Last->operand;
			A->Last=First;
			A->Last->next=NULL;
			free(Throw);
			return q;
		}else{
			Throw=Last;
			q=Last->operand;
			A->Last=NULL;
			A->First=NULL;
			free(Throw);
			return q;
		}
		
	}
}


double faktorial(double n){
	double hasil=1;
	int i=1;
	
	while(i<=n){
		hasil=hasil*i;
		i++;
	}
	return hasil;
}

double prosesPerhitunganTrigonometri(double angka, char operator[], int *valid){
	if(strcmp(operator,"sin(")==0){
		return operasiSinus(angka);
	}else if(strcmp(operator,"cos(")==0 ){
		return operasiCosinus(angka);
	}else if(strcmp(operator,"tan(")==0 && angka!=90 && angka!=270){
		return operasiTangen(angka);
	}else if(strcmp(operator,"asin(")==0 && angka>=-1 && angka<=1){
		return operasiAsin(angka);
	}else if(strcmp(operator,"acos(")==0 && angka>=-1 && angka<=1){
		return operasiAcos(angka);
	}else if(strcmp(operator,"atan(")==0){
		return operasiAtan(angka);
	}else if(strcmp(operator,"csc(")==0 && angka!=0 && angka!=180 && angka!=360 ){
		return operasiCosecan(angka);
	}else if(strcmp(operator,"sec(")==0 && angka!=90 && angka!=270){
		return operasiSecan(angka);
	}else if(strcmp(operator,"cot(")==0 && angka!=0 && angka!=180 && angka!=360){
		return operasiCotangen(angka);
	}else{
        *valid=0;
        return 0;
	}
}
