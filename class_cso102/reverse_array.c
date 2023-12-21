#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n,a ;
    printf("enter size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements of an array \n");
    int i=0;
    while(i!=(n)){
        scanf("%d",&arr[i]);
        ++i;
    }
    for(i =0;i<(n/2);i++){
        a=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=a;
    }
    printf("reverse array : \n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
