#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
 
struct Node* top = NULL;
struct Node* top2 = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node* push(struct Node* top, int x){

    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
    return top;
    
}
 
int pop(struct Node** top){

    struct Node* n = *top;
    *top = (*top)->next;
    int x = n->data;
    free(n);
    return x; 
    
}

int main(){
	struct Node *ptr,*q;
	int a,c=1;
	char ch ='y';
	while(ch=='y'){
		printf("Enter stock's price\n");
		scanf("%d",&a);
		top = push(top,a);
		printf("In order to enter more stock's prices press 'y' else press 'n'\n");
		scanf("\n%c",&ch);
	}
	linkedListTraversal(top);
	ptr = top;
	while (ptr != NULL)
    {
        ptr=ptr->next;
        a=pop(&top);
        q=top;
        while(q!=NULL){
        	if(q->data<a)
        		c++;
        	q=q->next;
        }
        top2=push(top2,c);
        c=1;    }
        printf("\n");
        ptr = top2;
        while(ptr!=NULL){
        	printf("%d,",ptr->data);
        	ptr=ptr->next;
        }
}