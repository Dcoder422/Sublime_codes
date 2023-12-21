#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *front = NULL;
struct node *end = NULL;

void enqueue_end(int data){
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->prev=end;
	new->next=NULL;
	new->data=data;
	if(front==NULL)
		front=new;
	if(end!=NULL)
		end->next=new;
	end= new;
}
void enqueue_front(int data){
	struct node * new= (struct node *)malloc(sizeof(struct node));
	new->prev=NULL;
	new->next=front;
	new->data=data;
	if(end==NULL)
		end=new;
	if(front!=NULL)
		front->prev=new;
	front= new;
}
void dequeue_end(){
	struct node*ptr;
	ptr=end;
	end=end->prev;
	end->next=NULL;
	free(ptr);
}
void dequeue_front(){
	struct node*ptr;
	ptr=front;
	front=front->next;
	front->prev=NULL;
	free(ptr);
}
void display(){
	struct node*ptr= front;
	while(ptr!=NULL){
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}
int main(){
	enqueue_end(4);
	enqueue_end(2);
	enqueue_end(5);
	enqueue_end(1);
	enqueue_front(9);	
	enqueue_front(0);
	dequeue_front();
	dequeue_end();
    dequeue_end();
    dequeue_end();
    dequeue_end();
    enqueue_front(0);
	display();
}