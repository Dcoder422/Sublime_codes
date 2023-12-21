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
void preorder(struct node * root,int n ,int * n_max){
	if(root!=NULL){
		preorder(root->left,n+1,n_max);
		preorder(root->right,n+1,n_max);
		if(n>*n_max)
			*n_max=n;
	}
}
int main(){
	struct node * n[11];
	for(int i = 0;i<11;i++)
		n[i]=create_node(i+1);
	n[0]->left=n[1];
	n[0]->right=n[2];
	n[1]->left=n[3];
	n[1]->right=n[4];
	n[2]->left=n[5];
	n[2]->right=n[6];
	n[7]->left=n[9];
	n[7]->right=n[10];
	n[6]->left=n[7];
	n[6]->right=n[8];
	int max = 0;
	preorder(n[0],1,&max);
	printf("%d",max);

}