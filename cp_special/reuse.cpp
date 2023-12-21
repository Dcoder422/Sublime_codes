
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N];
// } Driver Code Ends
class Solution{
	void sol(int n,int k, int i){
		int a;
		if(i==0){
		a=arr[n/2-1];
		arr[n/2-1] = arr[n/2];
		arr[n/2 ]=a;
	// for (int j = 0; j < n; j++) 
	// 		cout << arr[j] << " ";cout<<endl;
	}
		else{
		a=arr[n/2-1-i];
		arr[n/2-1-i] = arr[n/2-i];
		arr[n/2-i]=a;
		// for (int j = 0; j < n; j++) 
		// 	cout << arr[j] << " ";cout<<endl;
		a=arr[n/2+i-1];
		arr[n/2-1+i] = arr[n/2+i];
		arr[n/2+i]=a;
		// for (int j = 0; j < n; j++) 
		// 	cout << arr[j] << " ";cout<<endl;
		}
		cout << arr[1] << endl;
		if((n/2-1-i)==k)
		{i=0;k+=2;}else i+=1;
		if(k*2>=n)return;
		sol(n,k,i);

	}
	
	
	public:
	
	void shuffleArray(int n)
	{
		if(n>2)
	    sol(n,1,0);
	    
	    // Your code goes here
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	
    	int n;
	    cin>>n;
	    // int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    for (int i = 0; i < n; i++) 
			cout << arr[i] << " ";
    
	
        
	    cout << "\n";


       

        Solution ob;
        ob.shuffleArray(n);

		for (int i = 0; i < n; i++) 
			cout << arr[i] << " ";
    
	
        
	    cout << "\n";
	     
    
    return 0;
}
// } Driver Code Ends  6816

	
	
	
	// public:
	// void shuffleArray(int arr[],int n)
	// {
	//     for (int i=(n+1)/2;i<n;i++) {
	//         arr[i] = arr[i] + 10000 * arr[i-(n+1)/2];
	//     }
	//     int j = (n+1)/2;
	//     for (int i=0;i<n;i++) {
	//         if (i%2 == 0) {
	//             arr[i] = arr[j] / 10000;
	//         } else {
	//             arr[i] = arr[j] % 10000;
	//             j++;
	//         }
	//     }
	// }
		 

	