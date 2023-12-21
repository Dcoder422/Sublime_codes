#include <bits/stdc++.h>
using namespace std;
int remove_duplicate(int a[],int n){
        // code here
        int sp=0,sv=a[0];
        for(int i=1;i<n;i++){
            if(a[i]==sv)continue;
            else{
                sv=a[i];
                sp++;
                a[i]=a[sp];
                a[sp]=sv;
            }
        }
        return sp+1;
    }

int main(){
    int arr[]={0,0, 1,1, 3, 3,4};
    cout << remove_duplicate(arr,7) << endl;
    for(int i=0;i<7;i++){
        cout << arr[i] << endl;
    }
}    