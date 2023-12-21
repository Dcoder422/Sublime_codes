#include<bits/stdc++.h>
using namespace std;
int main(){
    double exp=0, n=26;

    //array for storing values of f_k
    vector<float> f_k(27); 
    f_k[0]=1;

    for(int i=1;i<27;i++){

        // calculating and storing f_k
    	f_k[i]=((n-i+1)/(n+i))*f_k[i-1];
    }

    for(int i=2;i<28;i++){

        //using formula for calculating expectation
    	exp+=(i-1)*(f_k[i-1]-f_k[i] );
    }

    cout << "expected pay-off in the game of 52 cards is : " << exp << endl;
 }
