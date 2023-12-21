// O(n)
//https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
class Solution {
  public:
    const int N=1e3+10;
    const int M=1e9+7;
    long long int my(long long int n,vector<long long> &v){
        if(v[n]!=0)
        return v[n];
        v[n]=my(n-1,v)%M + my(n-2,v)%M;
        return v[n]%M;
    }
    long long int nthFibonacci(long long int n){
      vector<long long > v(N) ;
      v[1]=1;
      v[2]=1;
  
       return my(n,v)%M;
    }
};