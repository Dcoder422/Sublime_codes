#include<bits/stdc++.h>
using namespace std;
int main(){
    double max_prob=0,n=26;
    int X;

    //array for storing values of f_k
    vector<float> f_k(27); 
    f_k[0]=1;

    for(int i=1;i<27;i++){

        // calculating and storing f_k
        f_k[i]=((n-i+1)/(n+i))*f_k[i-1];
    }

    for(int i=1;i<28;i++){

        // comparing values of probablity
    	if(f_k[i-1]-f_k[i]>max_prob){

            // storing element with higher probablity
            X=i-1;
            max_prob=f_k[i-1]-f_k[i];
        } 
    }
    cout << "payoff with highest probability is : " << X << endl;
    cout << " with a probability of : " << max_prob << endl;
 }
