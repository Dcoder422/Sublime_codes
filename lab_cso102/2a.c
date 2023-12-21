// DHRUVI JAIN
// 21095040

#include <stdio.h>
#include <stdlib.h>
struct my_node{
	int a;
	struct my_node *p;
};
int main(){
	struct my_node *n1,*n2,*n3,*n4;
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
}