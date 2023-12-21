#include<bits/stdc++.h>
using namespace std;
int power(int a,int b);
int main(){

		
	cout << power(10,5);
	}
	int power(int a,int b){
		    int a1 = a;
			while(b>1)
			{
				a*=a1;
				b--;
			}
			return a;
		}