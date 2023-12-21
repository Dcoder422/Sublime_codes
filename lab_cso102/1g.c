// DHRUVI JAIN
// 21095040
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("enter size of array \n");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements of array \n");
    for( int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("elements before :\n");
    for( int i=0;i<n;i++)
        printf("%d,",arr[i]);
    int arr1[n-1];
    int a,i;
    printf("\nEnter element to be deleted\n");
    scanf("%d",&a);
    for(i = 0;i<n;i++){
        if(arr[i]==a)
            break;
        arr1[i]=arr[i];
    }
    for(;i<n;i++)
        arr1[i]=arr[i+1];
    printf("elements after deletion :\n");
    for( int i=0;i<n-1;i++)
        printf("%d,",arr1[i]);
}