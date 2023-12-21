#include <stdio.h>
#include <stdlib.h>
struct stack_2{
 int *arr;
 int top1;
 int top2;
};
int n ;
void push_1(struct stack_2 *ptr,int data){
	if((ptr->top1+1)!=ptr->top2)
	{
		ptr->top1++;
		ptr->arr[ptr->top1]=data;}
		else
			printf("stack1 is full\n");
}
void push_2(struct stack_2 *ptr,int data){
	if((ptr->top2-1)!=ptr->top1)
	{
		ptr->top2--;
		ptr->arr[ptr->top2]=data;}
		else
			printf("stack2 is full\n");
}
void pop_1(struct stack_2 *ptr){
	if(ptr->top1==-1)
		printf("stack1 is empty\n");
	else
	ptr->top1--;
}
void pop_2(struct stack_2 *ptr){
	if(ptr->top2==n)
		printf("stack2 is empty\n");
	else
	ptr->top2++;
}
int main(){
	struct stack_2 * ptr;
	ptr = (struct stack_2*)malloc(sizeof(struct stack_2));
	printf("Enter size of array\n");
	scanf("%d",&n);
	ptr->arr=(int *)malloc(n*sizeof(int));
	ptr->top1=-1;
	ptr->top2=n;
	push_1(ptr,1);
	push_1(ptr,2);
	push_1(ptr,3);
	push_2(ptr,5);
	push_2(ptr,4);
	push_2(ptr,6);
	push_2(ptr,8);
	pop_1(ptr);
	printf("Stack 1 :\n");
	for(int i =ptr->top1;i>=0;i--)
		printf("%d\n",ptr->arr[i]);
	printf("Stack 2 :\n");
	for(int i =ptr->top2;i<=n-1;i++)
		printf("%d\n",ptr->arr[i]);

}