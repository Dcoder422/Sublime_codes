#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node * create_list(struct Node ** head){
    int val;
    char ch='y';
    printf("Enter first element of the list \n");
    scanf("%d",&val);
    (*head) = (struct Node *) malloc(sizeof(struct Node));
    (*head)->data = val;
    (*head)->next=NULL;
    printf("for entering more elements press y else press n\n");
    scanf("%c",&ch);
    while(ch=='y'){
         printf("enter next element\n");
         scanf("%d",&val);
         (*head)=insertAtEnd((*head),val);
         printf("for entering more elements press y else press n\n");
         scanf("%c",&ch);
    }
    return *head;
}
struct Node *  reverse_list(struct Node *head){
    if(head->next==NULL)
        return head;
    struct Node *ptr =head;
    struct Node *q = ptr ->next;
    if(q->next == NULL){
        q->next = head;
        head->next=NULL;
        return q;
    }

    struct Node *a;
    head->next=NULL;
    do{
        a=ptr;
        ptr = q;
        q= ptr->next;
        ptr->next=a;
    }while((q->next)!=NULL);
    q->next=ptr;
    head=q;
    return head;
}
int main(){
    int j=0,k=0;
    struct Node *l1_head,*l2_head,*ptr,*q,*last_node,*ptr2,*ptr3;
    printf("For list L1\n");
    l1_head=create_list(&l1_head);
    linkedListTraversal(l1_head);
    printf("For list L2\n");
    l2_head=create_list(&l2_head);
    linkedListTraversal(l2_head);
    ptr = l2_head;
    q = l1_head;
    ptr2 = ptr;
    while (ptr != NULL)
    {
        while (ptr != NULL && q != NULL && ptr->data == q->data )
        {
            q = q->next;
            ptr = ptr->next;
            k=2;
            if(q==NULL){
                k=1;
                printf("l1 is present in l2\n");
                last_node = ptr;
                break;}
            if(ptr==NULL){
                k=4;
                break;
            }
        }
        if(k==0){
            ptr2 = ptr;
            ptr = ptr->next;
            j=1;
        }
        else if(k==2){
            q = l1_head;
            ptr2 = ptr;
            ptr = ptr->next;}
        else if(k==1||4)
        break;    
    }
    if(k!=1)
        printf("l1 is not present in l2\n");
    else if(l1_head->next==NULL)
        linkedListTraversal(l2_head) ;
    else{
        l1_head = reverse_list(l1_head); 
        q=l1_head;
        if(ptr2 == l2_head && j==0){
            ptr3 = ptr2;
            l2_head=l1_head;
        }
        else{
            ptr3 = ptr2->next;
            ptr2->next=l1_head;}
        while(q->next!=NULL){
            ptr=ptr3->next;
            free(ptr3);
            ptr3=ptr;
            q=q->next;
        }
        free(ptr);
        q->next=last_node;
        printf("\nFinal l2 is : \n");
        linkedListTraversal(l2_head) ;
    }
}