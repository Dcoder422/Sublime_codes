#include<stdio.h>
#include<stdlib.h>

int main(){
	int n=6  ,sum=0;
	// scanf("%d",&n);
	int v[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			v[i][j]=i-j;
			sum+=i-j;
		}

	}
	printf("%d",sum);

}
