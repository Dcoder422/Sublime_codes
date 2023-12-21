
//https://practice.geeksforgeeks.org/problems/josephus-problem/1



// editorial solution

// class Solution
// {
//     public:
//     int josephus(int n, int k)
//     {
//       if (n == 1) //base case
//         return 1;
//       else
      
      /* The position returned by josephus(n - 1, k) is adjusted because the 
           recursive call josephus(n - 1, k) considers the original position  
           k%n + 1 as position 1 */
//         return (josephus(n - 1, k) + k-1) % n + 1; //recursion
//     }

// };

#include<bits/stdc++.h>
using namespace std;
int my(vector<int> &v,int si,int k){
	if(v.size()==1)
		return v[0];
	auto it = find(v.begin(),v.end(),v[(si+k-1)%v.size()]);
	v.erase(it);
	si = (si+k-1)%(v.size()+1);
	return my(v,si,k);
}
  int josephus(int n, int k)
    {
       vector<int> v;
       for(int i=1;i<=n;i++){
       		v.push_back(i);
       }
       return my(v,0,k);
    }
int main(){
cout << josephus(3,2);
    
}

