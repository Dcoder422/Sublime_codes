// Dhruvi Jain
// 21095040
// electronics

#include <stdio.h>
#include <stdlib.h>
struct node{
	char data;
	struct node * left;
	struct node * right;
};
struct node * create_node(char data){
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
		if(prev!=NULL && (int)(root->data)<=(int)(prev->data))
			return 0;
		prev=root;
		return isBST(root->right);
	}
	else 
		return 1;
}
void preorder(struct node * root){
	if(root!=NULL){
		printf("%c,",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node * root){
	if(root!=NULL){
		inorder(root->left);
		printf("%c,",root->data);
		inorder(root->right);
	}
}
void postorder(struct node * root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%c,",root->data);
	}
}
int main(){
	struct node * n[5];
	n[0]=create_node('e');
	n[1]=create_node('c');
	n[2]=create_node('f');
	n[3]=create_node('b');
	n[4]=create_node('d');
	
	n[0]->left=n[1];
	n[0]->right=n[2];
	n[1]->left=n[3];
	n[1]->right=n[4];
	if(isBST(n[0])==1)
	printf("It is a binary search tree\n");
	else
	printf("It is not a binary search tree\n");	
	printf("Preorder :\n");	
	preorder(n[0]);
	printf("\nInorder :\n");
	inorder(n[0]);
	printf("\nPostorder :\n");
	postorder(n[0]);
}	