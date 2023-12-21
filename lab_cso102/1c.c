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
    int arr1[n+1];
    printf("\nEnter element to be inserted\n");
    scanf("%d",&arr1[0]);
    for(int i = 1;i<n+1;i++)
        arr1[i]=arr[i-1];
    printf("elements after insertion :\n");
    for( int i=0;i<n+1;i++)
        printf("%d,",arr1[i]);
}