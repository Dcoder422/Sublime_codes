#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct stack{
	int top;
	char arr[];
};
void push(struct stack *p,char c);
void push(struct stack *p,char c){
		p->top++;
		(p->arr)[p->top]=c;
	}
char pop(struct stack *p);
char pop(struct stack *p){
		char a = (p->arr)[p->top];
		p->top--;
		return a;
	}	
int main(){
	struct stack *my;
	struct stack *f;
	char c,c1;
	int k=0;
	my=(struct stack *)malloc(sizeof(struct stack));
	f=(struct stack *)malloc(sizeof(struct stack));
	char a[80];
	printf("Enter postfix expression:\n");
	scanf("%s",a);
	my->top = -1;
	f->top = -1;
	int i=0;
	for(i=strlen(a)-1;i>=0;i--){
		if((a[i]>=65 && a[i]<=90) || (a[i]<=122 && a[i]>=97)){
			if(f->top == -1 )
			push(f,a[i]); 