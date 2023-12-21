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
int isalpha(char ch){
	if((ch>=65 && ch<=90) || (ch<=122 && ch>=97))
		return 1;
	return 0;
}
int isOper(char ch){
	if((ch>=40 && ch<=50))
		return 1;
	return 0;
}	
int main(){
	struct stack *sign,*final;
	sign=(struct stack *)malloc(sizeof(struct stack));
	final=(struct stack *)malloc(sizeof(struct stack));
	char a[80];
	printf("Enter postfix expression:\n\n");
	scanf("%s",a);
	sign->top = -1;
	final->top= -1;
	int i=0;
	printf("Infix expression:\n");
	for(i=strlen(a)-1;i>=0;i--){
		if(isalpha(a[i])){
			if(final->top==-1){
				push(final,a[i]);
			}
			else if(isalpha(final->arr[final->top])||final->arr[final->top]=='(' )
			{
				push(final,pop(sign));
				push(final,a[i]);
				if(sign->arr[sign->top]=='(')
					push(final,pop(sign));
			}
			else
			push(final,a[i]);	
	}
	else{
		if(isalpha(final->arr[final->top]) && prec(sign->arr[sign->top])>=prec(a[i])){
			push(final,pop(sign));
			push(sign,a[i]);		
		}
		else if(isalpha(final->arr[final->top]) && prec(sign->arr[sign->top])<prec(a[i])){
			push(final,pop(sign));
			push(final,')');
			push(sign,'(');
			push(sign,a[i]);
		}
		else if(sign->top!=-1 && !isalpha(final->arr[final->top]) && prec(sign->arr[sign->top])<prec(a[i])){
			if(final->arr[final->top]=='(')
				push(final,pop(sign));
			push(final,')');
			push(sign,'(');
			push(sign,a[i]);
		}
		else
		push(sign,a[i]);
	}
	}
		for(int i = final->top;i>=0;i--)
			printf("%c",final->arr[i]);
		}