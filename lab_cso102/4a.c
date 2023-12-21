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
		if(p->top==-1){
			printf("Stack Underflow\n");
		}
		else{
			char a = (p->arr)[p->top];
			free((p->arr)+(p->top));
			p->top--;
			return a;}
	}
int prec(char ch){
	if(ch=='+'||ch=='-')
		return 2;
	if(ch=='*'||ch=='/')
		return 1;
}		
int main(){
	struct stack *my;
	my=(struct stack *)malloc(sizeof(struct stack));
	char a[80];
	printf("Enter infix expression:\n\n");
	scanf("%s",a);
	my->top = -1;
	int i=0;
	printf("Postfix expression:\n");
	for(i=0;i<=strlen(a);i++){
		if((a[i]>=65 && a[i]<=90) || (a[i]<=122 && a[i]>=97))
			printf("%c",a[i]);
		else{
			if(my->top==-1 || a[i]=='(')
				push(my,a[i]);
			else if(a[i] == ')'){
				do{
					printf("%c",pop(my));
				}while((my->arr)[my->top] != '(');
				char c = pop(my);
			}
			else if(a[i]=='\0'){
				while(my->top != -1){
					printf("%c",pop(my));
				}
			}
			else if(prec(a[i])<prec((my->arr)[my->top]) ||(my->arr)[my->top]=='(' )
				push(my,a[i]);
			else{
				do{
					printf("%c",pop(my));
				}while(my->top!=-1 && prec(a[i])<=prec((my->arr)[my->top]) );
				push(my,a[i]);
			}
		}
	}
	// printf("%d %d ",'+','*');
}