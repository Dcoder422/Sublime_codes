#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
#define ld long double
 
const ll N=2e6+5,M=1e9+7,INF=LLONG_MAX,V=2e6+1;

int sa[N],cnt[N],cl[N],cl2[N],sa2[N],lcp[N];
 
void solve(){ 
    string s;
    cin >> s;
    s+='$';
    int n=s.size(),m=27;

    // cl[i]-> class of suffix at pos i

    // cl and sa are kind of inverse function
    // cl[pos]=class
    // sa[order]=pos
    for(int i=0;i<n;i++)
        sa[i]=i,
        cl[i]=s[i]-'a'+1;

    cl[n-1]=0;
    sort(sa,sa+n,[&](int a,int b){return cl[a]<cl[b];});
    
    for(int k=1;k<n;k*=2){
        memset(cnt,0,4*(m+1));
        for(int i=0;i<n;i++)
            cnt[cl[i]]++; 
        for(int i=0;i<m;i++)
            cnt[i+1]+=cnt[i];
        for(int i=n-1;~i;i--)
            sa2[--cnt[cl[(sa[i]-k+n)%n]]]=(sa[i]-k+n)%n;
        
        m=0; 
        for(int i=0;i<n;i++){
            if(i and (cl[sa2[i]]!=cl[sa2[i-1]] or cl[(sa2[i]+k)%n]!=cl[(sa2[i-1]+k)%n]))
                m++;
            cl2[sa2[i]]=m;
        }
        memcpy(sa,sa2,4*n);
        memcpy(cl,cl2,4*n);
        if(m==n-1)  // all suffix have been given different classes
            break;
    }

    int k=0;
    for(int i=0;i<n-1;i++){
        int pos_i = cl[i]; 
        // after process all suffix will have diff class
        // and it points to there pos in suffix array
        int j = sa[pos_i-1];
        // lcp[i] = lcp(s[i..],s[j...])
        while(s[i+k]==s[j+k])k++;
        lcp[pos_i]=k;
        k=max(k-1,0);
    }
    for(int i=0;i<n;i++)
        cout << lcp[i] << " " << sa[i] << " " << s.substr(sa[i],n-sa[i]) << endl;


}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // presolve();
    int t;
    // cin >> t;                                                            
    t=1;   
    while(t--)
        solve();
} 

