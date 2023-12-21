#include<stdio.h>
#include<stdlib.h>
struct end_2_queue{
	int *arr;
	int size;
	int front;
	int end; 
};
void enqueue_end(struct end_2_queue * ptr,int data){
	if(((ptr->end+1)%ptr->size)!=ptr->front)
		{
			ptr->end=(ptr->end+1)%ptr->size;
			ptr->arr[ptr->end]=data;
		}
		else 
			printf("Queue is Full\n");
}
void enqueue_front(struct end_2_queue * ptr,int data){
	if(((ptr->front-1+ptr->size)%ptr->size)!=ptr->end)
		{
			ptr->front=(ptr->front-1+ptr->size)%ptr->size;
			ptr->arr[ptr->front]=data;
		}
		else 
			printf("Queue is Full\n");
}
void dequeue_front(struct end_2_queue * ptr){
	if(ptr->front==ptr->size && ptr->end==-1)
		printf("Queue is empty\n");
	else if((ptr->front%ptr->size)==(ptr->end%ptr->size)){
		ptr->end=-1;
		ptr->front=ptr->size;
	}
	else
	ptr->front=(ptr->front+1)%ptr->size;
}
void dequeue_end(struct end_2_queue * ptr){
	if(ptr->front==ptr->size && ptr->end==-1)
		printf("Queue is empty\n");
	else if((ptr->front%ptr->size)==(ptr->end%ptr->size)){
		ptr->end=-1;
		ptr->front=ptr->size;
	}
	else
	ptr->end=(ptr->end-1+ptr->size)%ptr->size;
}
int main(){
	struct end_2_queue * ptr=(struct end_2_queue *)malloc(sizeof(struct end_2_queue));
	printf("Enter size of array \n");
	scanf("%d",&ptr->size);
	ptr->arr=(int *)malloc(ptr->size*sizeof(int));
	ptr->front=ptr->size;
	ptr->end=-1;
	enqueue_front(ptr,2);
	enqueue_front(ptr,5);
	enqueue_front(ptr,1);
	enqueue_front(ptr,8);
	enqueue_end(ptr,3);
	dequeue_front(ptr);
	dequeue_end(ptr);
	dequeue_front(ptr);
	dequeue_front(ptr);
	dequeue_front(ptr);
	enqueue_front(ptr,89);
	printf("Final Queue is :\n");
	int start=(ptr->front)%ptr->size;
	int end= (ptr->end+ptr->size)%ptr->size;
	do{
		if(end==start%ptr->size){
			printf("%d\n",ptr->arr[end]);
			break;
		}
		else
			{printf("%d\n",ptr->arr[start%ptr->size]);
				start++;}
	}while(1);
}