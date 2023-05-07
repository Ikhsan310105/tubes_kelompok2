#ifndef kalku_h
#define kalku_h
#define Data(P) (P)->data
#define right(P) (P)->right
#define left(P) (P)->left
#define Nil NULL
#include <ctype.h>

typedef char infotype;
typedef struct Elemen *address;
typedef struct Elemen{
	infotype data;
	float operand;
	address right;
	address left;
	int isOperator;
}Tree;

typedef struct Node *node;
typedef struct Node{
	node next;
	infotype oprtr;
	float operand;
	int isoperator;
}ElmtList;

typedef struct{
	node Head;
}Stack;

typedef struct {
	node First;
	node Last;
//	int invalid;
}Queue;


void InfixToPostfix(infotype* input, infotype postfix[]);
int derajatOperator(infotype oper);
int isOperator(infotype oper);
address CreateNode(infotype data);
address BuildTree(infotype postfix[]);
void PostOrder(address P);
void ViewAsc(Queue First);
void EnqueOperand(Queue *First,float item);
void convertPostfix(Queue *Z,Stack *X,char *input,int *invalid);
void ViewAscStack(Stack First);
void PushStack(Stack *First,char item, node *P);
char PopStack(Stack *First);
address Create_Tree(Queue Z);
address CreateNodeOperand(float input);
address CreateNodeOperator(char input);
double kalkulasi(address P);
float operasi_trigono(char* tes,float oprtr);
float Perkalian(float bilangan1, float bilangan2);
float akar_pangkat_n(int x,int n);
float Perpangkatan(float bilangan, float pangkat);
float DequeOperand(Queue *A);
float faktorial(float n);
int validasiTrigono(char operator[]);
double prosesPerhitunganTrigonometri(double angka, char operator[]);
node CreateNodeList();
float processLogarithm(float number, float base, char *op);
float naturalLogarithm(double number);
float logarithm(double number, double base);


#endif


