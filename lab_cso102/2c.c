// DHRUVI JAIN
// 21095040

#include <stdio.h>
#include <stdlib.h>
struct my_node{
	int a;
	struct my_node *p;
};
int main(){
	struct my_node *n1,*n2,*n3,*n4,*n0,*ptr;
	n1 = (struct my_node *)malloc(sizeof(struct my_node));
	n2 = (struct my_node *)malloc(sizeof(struct my_node));
	n3 = (struct my_node *)malloc(sizeof(struct my_node));
	n4 = (struct my_node *)malloc(sizeof(struct my_node));		
	n1->a=1;
	n1->p=n2;
	n2->a=3;
	n2->p=n3;
	n3->a=5;
	n3->p=n4;
	n4->a=6;
	n4->p=NULL;
	ptr = n1;
	printf("list before insertion:\n");
	while(ptr!=NULL){
		printf("%d,",ptr->a);
		ptr = ptr->p;
	}
	int e;
	n0 = (struct my_node *)malloc(sizeof(struct my_node));
	printf("\n\nenter element after which insertion is to be done:\n");
	scanf("%d",&e);
	printf("\nenter element to be inserted:\n");
	scanf("%d",n0);
	ptr = n1;
	while(ptr!=NULL){
		if((ptr->a)==e){
			n0->p=ptr->p;
			ptr->p = n0;
			break;	
		}
		ptr = ptr->p;
	}
	printf("\nlist after insertion:\n");
	ptr = n1;
	while(ptr!=NULL){
		printf("%d,",ptr->a);
		ptr = ptr->p;
	}
}