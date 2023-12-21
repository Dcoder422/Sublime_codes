#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7, M=1e9+7;

int main(){
    string s,p;
    cin >> s >> p;
    int b =31;// more than no. of distinct characters
    vector<int> powers(N),hash(s.size()+1,0);
    powers[0]=1;

    for(int i=1;i<N;i++)
        powers[i]=(1LL*b*powers[i-1])%M;

    int phash=0;
    for(int i=0;i<p.size();i++)
        phash= (0LL+ phash + (1LL*(p[i]-'a'+1)*powers[i])%M)%M;
    
    for(int i=1;i<=s.size();i++){
        hash[i]= (0LL + (1LL*(s[i-1]-'a'+1)*powers[i-1])%M + hash[i-1])%M;
        //    
    }

    for(int i=0;i+p.size()-1<s.size();i++){
        int hij = ((0LL+hash[i+p.size()]-hash[i]+M)%M); // dont do hij/power[i] -- since both are under modulo 
        // n modulo division is not that simple like modulo add sub n product
       
        if(hij==(1LL*phash*powers[i])%M) // hence multiply
            // instead of placing 0LL n 1LL everywhere just take long long to avoid overflow
            // if by chance missed one 0LL whole ans will be wrong so better take long long
            cout<< "Found at : " << i << endl;
    }
 }

