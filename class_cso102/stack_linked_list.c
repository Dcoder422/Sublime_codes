#include<stdio.h>
#include<stdlib.h>
struct stack{
	int size;
	int top;
	int *arr;
};
int isEmpty(struct stack *sp){
	if(sp->top==-1)
		return 1;
	return 0;
}
int isFull(struct stack *sp){
	if(sp->top==(sp->size-1))
		return 1;
	return 0 ;
}
void push(struct stack *sp,int val){
	if(isFull(sp))
		printf("Stack Overflow\n");
	else{
		sp->top++;
		sp->arr[sp->top]=val; }
}
int pop(struct stack *sp){
	if(isEmpty(sp))
		printf("Stack Underflow\n");
	else{
		int val = sp->arr[sp->top--];
		return val;
	}
}
void display(struct stack* sp){
	if(isEmpty(sp))
		printf("Stack is empty\n");
	else{
		for(int i=sp->top;i>=0;i--)
			printf("element %d: %d\n",sp->top-i+1,sp->arr[i]);
	}}
int main(){
	struct stack * sp;
	sp=(struct stack *)malloc(sizeof(struct stack ));
	printf("Enter size of stack array\n");
	scanf("%d",&sp->size);
	// printf("%d",sp->size);	sp->top=-1;
	sp->arr=(int *)malloc(sizeof(int)*sp->size);
	push(sp,3);
	push(sp,2);
	push(sp,4);
	push(sp,7);
	push(sp,8);
	push(sp,0);
	push(sp,8);
	pop(sp);
	pop(sp);
	display(sp);
}