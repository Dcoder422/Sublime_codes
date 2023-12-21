#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

//for queue of even numbers
struct Node *f=NULL;
struct Node *r=NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr; 
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
void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
 
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
 
int main(){

    struct Node *head=NULL;
    int first,last;
    printf("Enter first and last number of range of numbers you wish to give\n");
    scanf("%d%d",&first,&last);
    for(int i = last;i>=first;i--)
    head= insertAtFirst(head,i);
    
    //for stack of odd numbers

    struct Node *top=NULL;

    struct Node *ptr=head;
    while (ptr != NULL)
    {
        if(ptr->data%2==1)
            top=push(top,ptr->data);
        else
            enqueue(ptr->data);
        ptr = ptr->next;
    }
    printf("\nStack(top to bottom): \n");
    linkedListTraversal(top);

    printf("\n Queue(Front to Rear): \n");
    linkedListTraversal(f);

    // creating auxiliary stack
    struct Node *top2=NULL;
    ptr = top;
    while(ptr->next!=NULL){
        top2 = push(top2,pop(&top));
         ptr = top;
    }
 
    ptr = f;
    while(ptr!=NULL){
        top = push(top,dequeue());
        if(top2!=NULL)
        top = push(top,pop(&top2));
        ptr = f;
    }
    printf("\nfinal stack :\n");
    linkedListTraversal(top); 
}
