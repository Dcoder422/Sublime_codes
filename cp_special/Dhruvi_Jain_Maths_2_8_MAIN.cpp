#include<bits/stdc++.h>
using namespace std;
int main(){
    double n=26;
    //array for storing values of f_k
    vector<float> f_k(27); 
    f_k[0]=1;

    for(int i=1;i<27;i++){

        // calculating and storing f_k
        f_k[i]=((n-i+1)/(n+i))*f_k[i-1];
    }

    for(int i=2;i<28;i++){

        // printing probabilities 
    	cout << "P(X=" << i-1 << ") = " << f_k[i-1]-f_k[i] << endl; 
    }
 }
