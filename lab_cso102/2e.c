// DHRUVI JAIN
// 21095040

#include <stdio.h>
#include <stdlib.h>
struct my_node{
	int a;
	struct my_node *p;
};
int main(){
	int n;
	printf("enter size of list\n\n");
	scanf("%d",&n);
	struct my_node *p_arr[n];
	struct my_node *ptr;
	for(int i=0;i<n;i++){
		p_arr[i] = (struct my_node *)malloc(sizeof(struct my_node));
		printf("enter list element at index : %d\n",i);
		scanf("%d",p_arr[i]);
		if(i!=0 && i!=(n-1))
			p_arr[i-1]->p =p_arr[i];
		else if(i==(n-1)){
			p_arr[i-1]->p =p_arr[i];
			p_arr[i]->p = NULL;
		}		 
	}	
	ptr = p_arr[0];
	printf("list:\n");
	while(ptr!=NULL){
		printf("%d,",ptr->a);
		ptr = ptr->p;
	}
}	
