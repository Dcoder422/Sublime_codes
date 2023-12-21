#include <stdio.h>
#include <stdlib.h>
struct my_node{
	int a;
	struct my_node *p;
};
int main(){
	struct my_node *head,*a,*ptr,*q,*n1,*n2,*n3,*n4,*n5;
	n1 = (struct my_node *)malloc(sizeof(struct my_node));
	n2 = (struct my_node *)malloc(sizeof(struct my_node));
	n3 = (struct my_node *)malloc(sizeof(struct my_node));
	n4 = (struct my_node *)malloc(sizeof(struct my_node));	
	n5 = (struct my_node *)malloc(sizeof(struct my_node));	
	head = n1;	
	n1->a=1;
	n1->p=n2;
	n2->a=3;
	n2->p=n3;
	n3->a=5;
	n3->p=n4;
	n4->a=9;
	n4->p=n5;
	n5->a=6;
	n5->p=NULL;
	ptr = head;
	printf("list before reversal:\n");
	while(ptr!=NULL){
		printf("%d,",ptr->a);
		ptr = ptr->p;
	}
	ptr =head;
	q = ptr ->p;
	head->p=NULL;
	do{
		a=ptr;
		ptr = q;
		q= ptr->p;
		ptr->p=a;
	}while((q->p)!=NULL);
	q->p=ptr;
	head=q;
	ptr = head;
	printf("\n\nlist after reversal:\n");
	while(ptr!=NULL){
		printf("%d,",ptr->a);
		ptr = ptr->p;
	}
}