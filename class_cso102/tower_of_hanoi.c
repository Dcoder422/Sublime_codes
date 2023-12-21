#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size ;
    int top;
    int * arr;
};

int isEmpty_array(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
void push_array(struct stack* ptr, int val){
        ptr->top++;
        ptr->arr[ptr->top] = val;
}
 
int pop_array(struct stack* ptr){
    if(isEmpty_array(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void display_tower(struct stack *t[]){
	for(int i=0;i<3;i++)
	{
		printf("Tower %d :",i+1);
		// if(isEmpty_array(t[i]))
		// 	printf("Empty");
		// else{
			for(int j=0;j<=t[i]->top;j++)
		printf("%d",t[i]->arr[j]);
		// }
		printf("\n");
	}
	printf("\n");
}
int main(){
	int n,j;
	scanf("%d",&n);
	struct stack *t[3];
	t[0]=(struct stack*)malloc(sizeof(struct stack));
	t[1]=(struct stack*)malloc(sizeof(struct stack));
	t[2]=(struct stack*)malloc(sizeof(struct stack));

	for( int i=0;i<3;i++){
		t[i]->top=-1;
	    t[i]->size=n;
	    t[i]->arr= (int *) malloc(t[i]->size * sizeof(int));
	}
	for(int i =n;i>=1;i--)
		push_array(t[0],i);
	display_tower(t);
	j=0;
	while(1){
		push_array(t[(j+1)%3],pop_array(t[j%3]));
		display_tower(t);
		if(isEmpty_array(t[(j)%3]) && isEmpty_array(t[(j+2)%3]))
			break;

		push_array(t[(j+2)%3],pop_array(t[j%3]));
		display_tower(t);
		if(isEmpty_array(t[(j)%3]) && isEmpty_array(t[(j+1)%3]))
			break;

		push_array(t[(j+2)%3],pop_array(t[(j+1)%3]));
		display_tower(t);
		if(isEmpty_array(t[(j)%3]) && isEmpty_array(t[(j+1)%3]))
			break;
	
		if(isEmpty_array(t[j%3]) ){
			push_array(t[(j)%3],pop_array(t[(j+1)%3]));
			display_tower(t);
			if(isEmpty_array(t[(j+1)%3]) && isEmpty_array(t[(j+2)%3]))
			break;
		}
		else if(t[j%3]->arr[t[j%3]->top]>t[(j+1)%3]->arr[t[(j+1)%3]->top]){
			push_array(t[(j)%3],pop_array(t[(j+1)%3]));
			display_tower(t);
			if(isEmpty_array(t[(j+1)%3]) && isEmpty_array(t[(j+2)%3]))
			break;
		}
		else	
			{push_array(t[(j+1)%3],pop_array(t[j%3]));
				display_tower(t);
				if(isEmpty_array(t[(j)%3]) && isEmpty_array(t[(j+2)%3]))
				break;}
		j=j+2;
	}
	// printf("\nAfter :\n");
	// display_tower(t);

}