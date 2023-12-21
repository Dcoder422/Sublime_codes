#include<bits/stdc++.h>
using namespace std;
void lps(string &p,vector<int> &lp){

    lp[0]=0;

    for(int i=1 ; i<p.size();i++){
        int j= lp[i-1];

        while(j>0 && p[i]!=p[j])
            j=lp[j-1];

        if(p[i]==p[j])
            j++;
        lp[i]=j;

    }
}
int main(){
    string s,p;
    cin >> s >> p;
    vector<int> lp(p.size());

    lps(p,lp);
    int i(0),j(0);
    while(i<s.size()){
        if(s[i]==p[j]){
            i++;
            j++;
        }
        if(j==p.size()){
            cout << "Found at :" << i-j << endl;
            j=lp[j-1];
        }
        if(s[i]!=p[j]){
            if(j>0)
                j=lp[j-1];
            else
                i++;
        }
    }

 }

