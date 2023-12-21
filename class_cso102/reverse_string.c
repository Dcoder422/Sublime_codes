#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rev(char *str,int l);
int main()
{
    char str[50];
    printf("enter a string\n");
    scanf("%[^\n]s",str);
    int l = strlen(str);
    rev(str,l);
    printf("reverse string : \n%s",str);

}
void rev(char *arr,int n)
{
    char a;
    for(int i =0;i<(n/2);i++){
        a=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=a;
    } 
}
