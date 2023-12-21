#include<bits/stdc++.h>
using namespace std;


// imp points: always:
// start at i 
// end at n-i-1

void Sol(vector<vector<int>> &v,int i){
    int n= v.size();
    int temp1,temp = v[i][n-1-i];

     for(int j=n-1-i;j>i;j--)
        v[i][j]=v[i][j-1];

     
     temp1=v[n-1-i][n-1-i];

     for(int j=n-1-i;j>1;j--)
        v[j][n-1-i]=v[j-1][n-1-i];
    v[i+1][n-1-i]=temp;
    //
    temp = v[n-1-i][i];

    for(int j=i;j<n-2-i;j++)
        v[n-1-i][j]=v[n-1-i][j+1];
    v[n-1-i][n-2-i]=temp1;
 
    for(int j=i;j<n-2-i;j++)
        v[j][i]=v[j+1][i];
    
    v[n-2-i][i]=temp;

}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> v[i][j]; 
    for(int i=0;i<n/2;i++)
        for(int j=0;j<n-1-i*2;j++)
        Sol(v,i);
    for(int i=0;i<n;i++)
        {for(int j=0;j<n;j++)
                    cout << v[i][j] << " ";
        cout << endl;}
 }
