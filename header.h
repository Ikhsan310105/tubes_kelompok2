#ifndef kalku_h
#define kalku_h
#define Data(P) (P)->data
#define right(P) (P)->right
#define left(P) (P)->left
#include <stdbool.h>
#define Nil NULL
#include <ctype.h>

typedef char infotype;
typedef struct Elemen *address;
typedef struct Elemen{
	infotype data;
	double operand;
	address right;
	address left;
}Tree;

typedef struct Node *node;
typedef struct Node{
	node next;
	infotype oprtr;
	double operand;
}ElmtList;

typedef struct{
	node Head;
}Stack;

typedef struct {
	node First;
	node Last;
}Queue;


int derajatOperator(infotype oper);
int isOperator(infotype oper);
void PostOrder(address P);
void ViewAsc(Queue First);
void EnqueOperand(Queue *First, double item);
void convertPostfix(Queue *Z,char *input,bool *valid);
void ViewAscStack(Stack First);
Stack PushStack(Stack First, char item);
char PopStack(Stack *First);
address Create_Tree(Queue Z);
address CreateNodeOperand(double input);
address CreateNodeOperator(char input);
double kalkulasi(address P);
float operasi_trigono(char* tes,float oprtr);
float Perkalian(float bilangan1, float bilangan2);
float akar_pangkat_n(int x,int n);
float Perpangkatan(float bilangan, float pangkat);
double DequeOperand(Queue *A);
double faktorial(double n);
node CreateNodeList();
double prosesPerhitunganTrigonometri(double angka, char operator[], bool *valid);
double naturalLogarithm(double number);
double logarithm(double number, double base);
double operasiPembagian(double bilangan1, double bilangan2);
double operasiSinus(double sudut);
double operasiCosinus(double sudut);
double operasiTangen(double sudut);
double operasiCosecan(double sudut);
double operasiSecan(double sudut);
double operasiCotangen(double sudut);
double operasiAsin(double bilangan);
double operasiAcos(double bilangan);
double operasiAtan(double bilangan);
void tampilkan_history();
void insert_to_history(char *input);
void help();
void printTree(address root, int space);


#endif


