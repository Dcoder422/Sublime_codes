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
int isBST(struct node * root){
	if(root!=NULL){
		static struct node *prev = NULL; 
		if(!isBST(root->left))
			return 0 ;
		if(prev!=NULL && root->data<=prev->data)
			return 0;
		prev=root;
		return isBST(root->right);
	}
	else 
		return 1;

}
int main(){
	struct node * n[5];
	n[0]=create_node(5);
	n[1]=create_node(3);
	n[2]=create_node(4);
	n[3]=create_node(2);
	n[4]=create_node(4);
	
	n[0]->left=n[1];
	n[0]->right=n[2];
	n[1]->left=n[3];
	n[1]->right=n[4];
	printf("%d",isBST(n[0]));
	printf("hi");
}	