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
    int a,in,j;
    printf("\nEnter element to be inserted\n");
    scanf("%d",&a);
    printf("\nEnter index after which element to be inserted\n\n");
    scanf("%d",&in);
    for(int i = 0,j =0;i<n;i++,j++){
        if(j!=(in+1))
        arr1[j]=arr[i];
        else{
            --i;
            arr1[j]=a;
        }
    }
    printf("elements after insertion :\n");
    for( int i=0;i<n+1;i++)
        printf("%d,",arr1[i]);
}