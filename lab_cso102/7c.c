// Dhruvi Jain
// 21095040
// electronics

#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node * left;
	struct node * right;
};
struct node * create_node(int data){
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
}
int similar(struct node * root1,struct node * root2){
	static int k;
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1==NULL || root2==NULL)
	    return 0;
	if(root1->data==root2->data)
		k=similar(root1->left,root2->right);
	else
	k=0;
	if(k==1)
		k=similar(root1->right,root2->left);
	return k;
}
int main(){
	struct node * n[6],*n1[6];
	n[0]=create_node(5);
	n[1]=create_node(3);
	n[2]=create_node(6);
	n[3]=create_node(2);
	n[4]=create_node(4);
	n[5]=create_node(1);
	
	n[0]->left=n[1];
	n[0]->right=n[2];
	n[1]->left=n[3];
	n[1]->right=n[4];
	n[4]->right=n[5];
	

	n1[0]=create_node(5);
	n1[1]=create_node(6);
	n1[2]=create_node(3);
	n1[3]=create_node(4);
	n1[4]=create_node(2);
	n1[5]=create_node(1);
	
	n1[0]->left=n1[1];
	n1[0]->right=n1[2];
	n1[2]->left=n1[3];
	n1[2]->right=n1[4];
	n1[3]->left=n1[5];

	if(similar(n[0],n1[0])==1)
	printf("Trees are symmetric");
	else
	printf("Trees are not symmetric");
}	