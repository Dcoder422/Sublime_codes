// DHRUVI JAIN
// 21095040

#include <stdio.h>
#include <stdlib.h>
struct my_node{
	int a;
	struct my_node *p;
};
int main(){
	struct my_node *n1,*n2,*n3,*n4,*ptr,*head,*del;
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
	head = n1;
	ptr = head;
	printf("list before deletion:\n");
	while(ptr!=NULL){
		printf("%d,",ptr->a);
		ptr = ptr->p;
	}
	int e;
	printf("\nenter element to be deleted:\n");
	scanf("%d",&e);
	if(n1->a==e){
		head = n2;
		free(n1);
	}
	else if (n4->a == e){
		n3->p = NULL;
		free(n4);
	}
	else{
		ptr = head;
		del = head->p;
		while(ptr!=NULL){
			if((del->a)==e){
				ptr->p = del->p;
				free(del);
				break;	
			}
			ptr = ptr->p;
			del = del->p;
		}
	}	
	printf("\nlist after deletion:\n");
	ptr = head;
	while(ptr!=NULL){
		printf("%d,",ptr->a);
		ptr = ptr->p;
	}
}