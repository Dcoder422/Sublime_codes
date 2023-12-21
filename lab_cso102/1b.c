// DHRUVI JAIN
// 21095040

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("enter size of array\n\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements of array\n\n");
    for( int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("elements are :\n");
    for( int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
}