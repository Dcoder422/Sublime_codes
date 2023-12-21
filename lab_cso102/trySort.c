#include<stdio.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    int key, j;
    for (int i = 1; i <= n-1; i++)
    {
        key = A[i];
        j = i-1;
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void bubbleSort(int *A, int n){
    int temp;
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j <n-1-i ; j++)
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}
void selectionSort(int *A, int n){
    int indexOfMin, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}
void  merge2(int *A,int low,int high){
    int mid = (low+high)/2;
    int k,i=low,j=mid+1;
    int B[high-low+1];
    for(k=0;k<=high-low;k++){
        if(A[i]<A[j] && i<=mid && j<=high){
            B[k]=A[i];i++;
        }
        else if(A[i]>A[j] && i<=mid && j<=high){
            B[k]=A[j];j++;
        }
        else{
            if(i>mid){
                while(j<high+1){
                B[k]=A[j];j++;k++;}}
            else if(j>high){
                while(i<mid+1){
                B[k]=A[i];i++;k++;}}
        }
    }
    for(i=low,k=0;i<=high;i++,k++)
        A[i]=B[k];
}
void mergeSort2(int *a,int low,int high){
    if(low==high)
        return;
    mergeSort2(a,low,(low+high)/2);
    mergeSort2(a,(low+high)/2+1,high);
    merge2(a,low,high);    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}



int main(){
  
    int A[] = {10, 11, 3, 4, 5, 6};
    int n = 6;
    // int a[]={1,0};
    printArray(A,6);
    // merge2(A,0,5);
    // insertionSort(A, n);
    // bubbleSort(A, n);
    // selectionSort(A, n);
    mergeSort2(A, 0, 5);  
    printArray(A, 6);
    return 0;
}
