//merge sort

void merge(int l , int r ,int mid){
    int l_sz = mid-l+1;
    int L[l_sz+1];
    int r_sz = r-mid;
    int R[r_sz+1];
    for(int i=0;i<l_sz;i++){
        L[i]=a[l+i];
    }
    for(int i=0;i<r_sz ;i++){
        R[i]=a[mid+1+i];
    }
    L[l_sz]=R[r_sz]=INTMAX;
    int l_i=0,r_i=0;
    for(int i=l;i<=r;i++){
        if(L[l_i]<=R[l_i]){
            a[i]=L[l_i];
            l_i++;
        }
        else{
            a[i]=R[r_i];
            r_i++;
        }
    }

}
void mergeSort(int l,int r){
    if(l==r)return;
    int mid =(l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,r,mid);
}


int binExpRecur(int a,int b){
    if(b==0)return 1;
    int res = binExpRecur(a,b/2);
    if(b&1)return (a*((res*1LL * res)% M))%M;
    return (res*1LL * res)% M;
}

int binExpIter(int a,int b){
    int ans =1;
    while(b){
        if(b&1)ans=(ans*1LL*a)%M;
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return ans;
} //O(logb)

// case 1:

//if a is v.large , a>10^9 , then calculations can also
//not be performed in long long 
// so if a<10^18 then can use a%M else 
// ex. a=2^1024;
// then do a = binExpo(2,1024,M);

// case 2:

// if 10^9 <M < 10^18
// we do binary multiplication

int binExpIter(int a,int b){
    int ans =1;
    while(b){
        if(b&1)ans=binMultiply(ans,a);
        a=binMultiply(a,a);
        b>>=1;
    }
    return ans;
} //O(log^2(N))
long long binMultiply(long long a,long long b,long long m){
    long long ans =0;
    while(b){
        if(b&1)ans=(ans+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return ans;
}

// case 3:
// for b<10^18 just change type of argument to long long
// int binExpIter(int a,long long b){
// b>10^18 ex. b=64^32...using ETF(euler totient function)
// for ex calculate (50^64^32)%M 
// do binEXp(50,binExp(64,32,M-1),M)(if M is prime)


// to print binary of a number
void print_bi(int n){
    for(int i=63;i>=0;i--){
        if((n&(1LL<<i))!=0)cout << 1 ;
        else cout << 0 ;
    }
    cout << endl;
}

int power(int a,int b){
		    int a1 = a;
			while(b>1)
			{
				a*=a1;
				b--;
			}
			if(b==0)
				return 1;
			return a;
		}
		
//array

void display_array(int arr[], int n){
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}
 
int indInsertion_array(int arr[], int size, int element, int capacity, int index){
    // code for Insertion
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1; 
}

void indDeletion_array(int arr[], int size, int index)
{
    // code for Deletion
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }  
}

int linearSearch_array(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
 
 // array should be sorted
int binarySearch_array(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return -1;
    
}

// linked list

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}

// Case 2
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
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

// Case 4
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    
    return head;
}


//STACKS

// Here are some of the basic operations we would want to perform on stacks:

// push(): to push an element into the stack
// pop(): to remove the topmost element from the stack

// peek(index): to return the value at a given index

// isempty() / isfull() : to determine whether the stack is empty or full to carry efficient push and pull operations.


// using arrays


struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty_array(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull_array(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push_array(struct stack* ptr, int val){
    if(isFull_array(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop_array(struct stack* ptr){
    if(isEmpty_array(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek_array(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int stackBottom(struct stack* sp){
    return sp->arr[0];
}

// int main(){
//     struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
//     sp->size = 10;
//     sp->top = -1;
//     sp->arr = (int *) malloc(sp->size * sizeof(int));
//     printf("Stack has been created successfully\n");
 
//     return 0;
// }	

// using linked list

// struct Node{
//     int data;
//     struct Node * next;
// };
 
// struct Node* top = NULL;
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
 
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
 
int peek(int pos){
    struct Node* ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
 
// int main(){
//     top = push(top, 28);
//     top = push(top, 18);
//     top = push(top, 15);
//     top = push(top, 7);
//     int x = pop(&top);
    
//     linkedListTraversal(top);
//     for (int i = 1; i <= 4; i++)
//     {
//         printf("Value at position %d is : %d\n", i, peek(i));
//     }
//     return 0;
// }


// QUEUE_ARRAY
 
// struct queue
// {
//     int size;
//     int f;
//     int r;
//     int* arr;
// };
 
 
int isEmpty_qarray(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull_qarray(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue_array(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue_array(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
// int main(){
//     struct queue q;
//     q.size = 4;
//     q.f = q.r = 0;
//     q.arr = (int*) malloc(q.size*sizeof(int));
    
//     // Enqueue few elements
//     enqueue(&q, 12);
//     enqueue(&q, 15);
//     enqueue(&q, 1); 
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("Dequeuing element %d\n", dequeue(&q)); 
//     enqueue(&q, 45);
//     enqueue(&q, 45);
//     enqueue(&q, 45);
 
//     if(isEmpty(&q)){
//         printf("Queue is empty\n");
//     }
//     if(isFull(&q)){
//         printf("Queue is full\n");
//     }
 
//     return 0;
// }


// QUEUE_linked_list


// #include <stdio.h>
// #include <stdlib.h>
 
// struct Node *f = NULL;
// struct Node *r = NULL;
 
// struct Node
// {
//     int data;
//     struct Node *next;
// };
 
// void linkedListTraversal(struct Node *ptr)
// {
//     printf("Printing the elements of this linked list\n");
//     while (ptr != NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }
 
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
 
// int main()
// {
//     linkedListTraversal(f);
//     printf("Dequeuing element %d\n", dequeue());
//     enqueue(34);
//     enqueue(4);
//     enqueue(7);
//     enqueue(17);
//     printf("Dequeuing element %d\n", dequeue());
//     printf("Dequeuing element %d\n", dequeue());
//     printf("Dequeuing element %d\n", dequeue());
//     printf("Dequeuing element %d\n", dequeue());
//     linkedListTraversal(f);
//     return 0;
// }


