#include<stdio.h>
#include<stdlib.h>
void find_and_replace (char *A, char *oldc, char *newc) {

for (int i=0; i<5; i++){

for (int j=0; j<3; j++){

if (A[i]== oldc[j]){
	A[i]=newc[j];
	break;
}
}}

}
int main(){
	char A[6]="abcde";
	char oldc[4]="abc";
	char newc[4]="bac";
	find_and_replace(A,oldc,newc);
	printf("%s",A);

}