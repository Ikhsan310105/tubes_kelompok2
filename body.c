#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "header.h"
#include "dinda.h"

void InfixToPostfix(infotype* input, infotype postfix[]){
	infotype stack[50], c;
	int i, length,top=-1, x=0,oper1, oper2;
	
	length=strlen(input);
	printf("length: %d \n", length);
	printf("input: %s \n", input);
	
	for(i=0;i<length;i++){
		c=input[i];
		if(isdigit(c)){
//			char num[length];
//			int j=0;
//			while(isdigit(input[i] || input[i]=='.')){
//				num[j++]=input[i];
//				i++;
//			}
//			i--;
//			postfix[x++]=num;
			postfix[x++]=c;
		} else{
			if(isOperator(c) && top!=-1 && stack[top]!='('){
//				printf("\noper: %c", c);
//				printf("\ntop: %c", stack[top]);
				oper1=derajatOperator(c);
				oper2=derajatOperator(stack[top]);
				while(oper1<=oper2 && top!=-1 ){
					postfix[x++]=stack[top--];
				}
				stack[++top]=c;
			} else if(c==')'){
//				printf("\noper: %c", c);
				postfix[x++]=stack[top--];
				top--;	
			} else{
				stack[++top]=c;
			}
		}
		
	}
	while(top!=-1){
		postfix[x++]=stack[top--];
	}
	postfix[x] = '\0';
}

int derajatOperator(infotype oper){
	if(oper=='+' || oper=='-'){
		return 1;
	} else if(oper=='*' || oper=='/'){
		return 2;
	} else if(oper=='^' || oper=='v'){
		return 3;
	} else{
		printf("Error, Operator Tidak Diketahui: %c", oper);
        exit(1);
	}
}

int isOperator(infotype oper){
	if(oper=='+' || oper=='-' || oper=='*' || oper=='/' || oper=='^' || oper=='v'){
		return 1;
	} 
	return 0;
}

address CreateNode(infotype data){
	address P;
	
	P = (address) malloc (sizeof (Tree));
	Data(P)=data;
	right(P)=Nil;
	left(P)=Nil;
	
	return P;
}

address BuildTree(infotype postfix[]){
	address P;
	address stack[50];
	int i, len, top=-1;
	infotype c;
	
	len=strlen(postfix);
	
	for(i=0;i<len;i++){
		c=postfix[i];
		if(isdigit(c)){
			P=CreateNode(c);
		} else{
			P=CreateNode(c);
			right(P)=stack[top--];
			left(P)=stack[top--];
		}
		stack[++top]=P;
	}
	return(stack[0]);
}

void PostOrder(address P){
	
	if(P!=Nil){
		PostOrder(left(P));
		PostOrder(right(P));
		if(P->isOperator==1){
		printf("%c ", P->data);
		}else{
		printf("%g ",P->operand);
		}
	}
}

void PushStack(Stack *First, char item, node *P){
	*P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{

		(*P)->oprtr=item;
		(*P)->isoperator=1;
		(*P)->next=NULL;
		if(First->Head==NULL){
			(*First).Head=*P;
			(*First).Head->next=NULL;	
		}else{
			(*P)->next=First->Head;
			First->Head=*P;
		}
	
	
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
		if(P->isoperator==1){
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
			if(P->isoperator==1){
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
		(P)->isoperator=1;
	} 
	
	return P;
}

void EnqueOperator(Queue *Q,char item){
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

void EnqueOperand(Queue *Q,float item){
	node P;
	
	P=CreateNodeList();
	P->operand=item;
	P->isoperator=0;
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
//float kalkulasi()
void convertPostfix(Queue *Z,Stack *X,char *input){
	node P;
	char token,c,negatif;
	int num3=10;
	int i,temp;
	float num=0,num2;
	float angka;
	int j;
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
			float hasil;
			while(input[i]!=')'){
				if(isdigit(input[i]) || input[i]=='.'){
					sudut[j++]=input[i];
				} else{
					trigono[x++]=input[i];
				}
				i++;
			}
			sudut[j]='\0';
			angka=strtof(sudut, NULL);
			hasil=prosesPerhitunganTrigonometri(angka,trigono);
		
			EnqueOperand(&*Z, hasil);	
		}else if(isOperator(token)&&X->Head!=NULL&&X->Head->oprtr!='('){
			c=X->Head->oprtr;
			while(derajatOperator(token)<=derajatOperator(c)&&X->Head!=NULL&&X->Head->oprtr!='('){
				EnqueOperator(&*Z,PopStack(&*X));
			}
			PushStack(&*X,token, &P);
		}else if(token==')'){
			c=X->Head->oprtr;
			while(c!='('&&X->Head->next!=NULL){
				EnqueOperator(&*Z,PopStack(&*X));
				c=X->Head->oprtr;
			}
			if(c=='('){
				PopStack(&*X);
			}else{
				printf("format yang dimasukkan salah\n");
				break;
			}
		}else if(token == 'l'){
			char log[10];
			char Num[100];
			float angka;
			float a,hasil;
			int j = 0,x = 0;
			if(isdigit(input[i-1])){
				a=DequeOperand(&*Z);
				while(input[i]!=')'){
					if(isdigit(input[i]) || input[i]=='.'){
						Num[j++]=input[i];
					} else{
						log[x++]=input[i];
					}
					i++;
				}
				Num[j]='\0';
				angka=strtof(Num, NULL);
				hasil=processLogarithm(angka,a,log);
				EnqueOperand(&*Z, hasil);	
			}else{
				while(input[i]!=')'){
					if(isdigit(input[i]) || input[i]=='.'){
						Num[j++]=input[i];
					} else{
						log[x++]=input[i];
					}
					i++;
				}
				Num[j]='\0';
				angka=strtof(Num, NULL);
				hasil=processLogarithm(angka,0,log);
				EnqueOperand(&*Z, hasil);	
			}
			
		}else if(token=='('){
			PushStack(&*X,token, &P);
		}else if(token=='!'){
			float a,c;
			char t;
			t=token;
			if(isdigit(input[i-1])){
				a=DequeOperand(&*Z);
				c=faktorial(a);
				EnqueOperand(&*Z,c);
				
			}else{
				printf("format yang anda masukkan salah: ");
			}
		}
		else{
			PushStack(&*X,token, &P);
		}
	}
	while(X->Head!=NULL){
		c=PopStack(&*X);
		EnqueOperator(&*Z,c);
	}
	
	
}

address Create_Tree(Queue Z){
	
	address P;
	address stack[50];
	node Q;
	int i, len, top=-1;
	infotype c;
	float d;
	
	Q=Z.First;
	
	while(Q!=NULL){
		if(Q->isoperator==1){
			c=Q->oprtr;
			P=CreateNodeOperator(c);
			right(P)=stack[top--];
			left(P)=stack[top--];
		}else{
			d=Q->operand;
			P=CreateNodeOperand(d);
		}
//		if(isdigit(c)){
//			P=CreateNode(c);
//		} else{
//			P=CreateNode(c);
//			right(P)=stack[top--];
//			left(P)=stack[top--];
//		}
		stack[++top]=P;
		Q=Q->next;
	}
	return(stack[0]);
}

address CreateNodeOperand(float input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->operand=input;
	P->isOperator=0;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}

address CreateNodeOperator(char input){
		address P;
	P = (address) malloc (sizeof (Tree));
	P->data=input;
	P->isOperator=1;
	P->left=NULL;
	P->right=NULL;
	return P;
	
}

double kalkulasi(address P){
	if(P->isOperator==1){
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
			return akar_pangkat_n(kalkulasi(P->left), kalkulasi(P->right));
		}
	}
	
	return P->operand;
}

float DequeOperand(Queue *A){
	float q;
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


float faktorial(float n){
	float hasil=1;
	int i=1;
	
	while(i<=n){
		hasil=hasil*i;
		i++;
	}
	return hasil;
}

double prosesPerhitunganTrigonometri(double angka, char operator[]){
	if(strcmp(operator,"sin(")==0){
		return operasiSinus(angka);
	}
	else if(strcmp(operator,"cos(")==0){
		return operasiCosinus(angka);
	}else if(strcmp(operator,"tan(")==0){
		return operasiTangen(angka);
	}else if(strcmp(operator,"asin(")==0){
		return operasiAsin(angka);
	}else if(strcmp(operator,"acos(")==0){
		return operasiAcos(angka);
	}else if(strcmp(operator,"atan(")==0){
		return operasiAtan(angka);
	}else if(strcmp(operator,"csc(")==0){
		return operasiCosecan(angka);
	}else if(strcmp(operator,"sec(")==0){
		return operasiSecan(angka);
	}else if(strcmp(operator,"cot(")==0){
		return operasiCotangen(angka);
	}
	else{
		if(strcmp(operator,"SIN")==0||strcmp(operator,"SIN(")==0||strcmp(operator,"sin")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya sin(...), contoh sin(60)", operator);
		}else if(strcmp(operator,"COS")==0||strcmp(operator,"COS(")==0||strcmp(operator,"cos")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya cos(...), contoh cos(45)", operator);
		}else if(strcmp(operator,"TAN")==0||strcmp(operator,"TAN(")==0||strcmp(operator,"tan")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya tan(...), contoh tan(30)", operator);
		}else if(strcmp(operator,"ASIN")==0||strcmp(operator,"ASIN(")==0||strcmp(operator,"asin")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya asin(...), contoh asin(0.5)", operator);
		}else if(strcmp(operator,"ACOS")==0||strcmp(operator,"ACOS(")==0||strcmp(operator,"acos")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya acos(...), contoh acos(0.5)", operator);
		}else if(strcmp(operator,"ATAN")==0||strcmp(operator,"ATAN(")==0||strcmp(operator,"atan")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya atan(...), contoh atan(0.5)", operator);
		}else if(strcmp(operator,"CSC")==0||strcmp(operator,"CSC(")==0||strcmp(operator,"csc")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya csc(...), contoh csc(40)", operator);
		}else if(strcmp(operator,"SEC")==0||strcmp(operator,"SEC(")==0||strcmp(operator,"sec")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya sec(...), contoh sec(0.5)", operator);
		}else if(strcmp(operator,"COT")==0||strcmp(operator,"COT(")==0||strcmp(operator,"cot")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya COT(...), contoh cot(0.5)", operator);
		}else{
			printf("Operator Tidak Diketahui sin: %s", operator);
		}
        exit(1);
	}
}
