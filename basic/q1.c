#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[]={1,2,3,4,5};
	printf("%p\n\n",a);
	printf("%p\t%d\n",(a+1),(*a+1000));
	printf("%d\t%d\n",*(a+1)+(*a+1),*(&a[0]+1)+*((a+1)));
	int *b;
	b=a+1;
	printf("%d\t%d\n",*a,*(b-1));
	for(int i=0;i<5;i++)
		printf("%p\n",(a+i));
}