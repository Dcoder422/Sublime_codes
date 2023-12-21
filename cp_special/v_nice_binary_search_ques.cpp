#include<bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/painters-partition-problem/
int paint(int A, int B, vector<int> &C) {
    long long min_time = (*max_element(C.begin(), C.end()));
    long long max_time =accumulate(C.begin(), C.end(), 0);
    // assert(B<=1000000);  
    long long mid;
    int required=0, time=0;
    while(min_time<=max_time){
        required=1;
        time=0;
        mid = (min_time+max_time)/2;
        for(int i=0; i<C.size(); i++){
            if(time+C[i]>mid){
                time=C[i];
                required++;
            }
            else time+=C[i];
        }
        if(required>A) min_time = mid+1;
        else max_time = mid-1;
    }
    return (B*min_time)% 10000003;
}

int main(){
    vector<int> l= {658,786,531,47,169,397,914};
    int a=5,b=10;
    cout << paint(a,b,l);
}