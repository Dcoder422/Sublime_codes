//valid for special type of array 
// whose order of elements is in a specific way 
 // see below ex proves it wrong 
  // que :


// Given an array of integers Arr of size N and a number K. 
// Return the maximum sum of a subarray of size K


//below is gfg given solution

//https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

//sub array are continuous ig here

#include<bits/stdc++.h>
using namespace std;
long maximumSumSubarray(int K, vector<int> &Arr, int N){
        
        
        long res = 0;
        for (int i=0; i<K; i++)
           res += Arr[i];
     
        long curr_sum = res;
        for (int i=K; i<N; i++)
        {
           curr_sum += Arr[i] - Arr[i-K];
           res = max(res, curr_sum);
        }
     
        return res;
        
        
        
    }

int main(){
int N = 5, K = 2;

vector<int> Arr = {9,2,8,7,5};
cout << maximumSumSubarray(K,Arr,N);

}