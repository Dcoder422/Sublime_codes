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
	sp->size=400;
	sp->top=-1;
	sp->arr=(int *)malloc(sizeof(int)*sp->size);
	int i =0;
	int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
 
	visited[i]=1;
	printf("Visited : %d,",i);
	do{
		for(int j=0;j<7;j++){
			if(a[i][j]==1 && visited[j]==0)
				push(sp,j);
		}
		int e=pop(sp);
		if(visited[e]==0){
			visited[e]=1;
			printf("%d,",e);
			i=e;
		}
	}while(!isEmpty(sp));
}