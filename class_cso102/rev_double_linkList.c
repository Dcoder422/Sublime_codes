#include <stdio.h>
#include <stdlib.h>
struct my_node{
	int a;
	struct my_node *p;
	struct my_node *b;
};
int main(){
	struct my_node *ptr,*n1,*n2,*n3,*n4,*n5;
	n1 = (struct my_node *)malloc(sizeof(struct my_node));
	n2 = (struct my_node *)malloc(sizeof(struct my_node));
	n3 = (struct my_node *)malloc(sizeof(struct my_node));
	n4 = (struct my_node *)malloc(sizeof(struct my_node));	
	n5 = (struct my_node *)malloc(sizeof(struct my_node));	
	n1->a=1;
	n1->p=n2; 
	n1->b=NULL;
	n2->a=4;
	n2->p=n3;
	n2->b=n1;
	n3->a=5;
	n3->p=n4;
	n3->b=n2;
	n4->a=9;
	n4->p=n5;
	n4->b=n3;
	n5->a=6;
	n5->p=NULL;
	n5->b=n4;
	ptr = n1;
	printf("list before reversal:\n");
	while(ptr!=NULL){
		printf("%d,",ptr->a);
		ptr = ptr->p;
	}
	ptr = n5;
	printf("\n\nlist after reversal:\n");
	while(ptr!=NULL){
		printf("%d,",ptr->a);
		ptr = ptr->b;
	}
}