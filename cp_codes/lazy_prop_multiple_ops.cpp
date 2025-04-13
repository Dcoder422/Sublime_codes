
// https://cses.fi/problemset/task/1735/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
 
const ll N=2e5+8,M=1e3,INF=1e17;

vector<ll> t(4*N,0),ops1(4*N,0),ops2(4*N,0);
int k=1;

void apply1(int id,ll x,int len){
    ops1[id]+=x;
    t[id]+=x*len;
    // we do not do ops2[id]=0 bcoz it preserves 
    // the order of operations =>
    // first assignment then updation 
    // so that all operations go in order
}

void apply2(int id,ll x,int len){
    ops2[id]=x;
    ops1[id]=0;
    t[id]=x*len;
}

void propagate(int id, int len){
    if(ops2[id]){
        apply2(2*id,ops2[id],len/2);
        apply2(2*id+1,ops2[id],len/2);
        ops2[id]=0;
    }
    apply1(2*id,ops1[id],len/2);
    apply1(2*id+1,ops1[id],len/2);
    ops1[id]=0;
}


void rec(int l, int r , ll &x , int type, int id=1 , int lx=0 , int rx=k-1){
    if(lx>r or rx<l) return;
    if(lx>=l and rx<=r){
        if(type==1){
            apply1(id,x,rx-lx+1);
        }
        else if(type==2){
            apply2(id,x,rx-lx+1);
        }
        else{
            x+=t[id];
        }
        return;
    }
    propagate(id,rx-lx+1);
    int mid = (lx+rx)/2;
    rec(l,r,x,type,id*2,lx,mid); 
    rec(l,r,x,type,id*2+1,mid+1,rx); 
    t[id]=t[id*2]+t[id*2+1]; 
}
 
void solve(){
    int n ,q ;
    cin >> n >> q;
    while(k<n)k*=2;
    for(int i=0;i<n;i++)
        cin >> t[i+k];
    for(int i=k-1;i;i--)t[i]=t[i*2]+t[i*2+1];
    while(q--){
        int op;cin >> op;
        int l,r; 
        cin >> l >> r,l--,r--;
        ll x=0;
        if(op==3){
            rec(l,r,x,3); 
            cout << x << endl;
        }   
        else{
            cin >> x;
            rec(l,r,x,op);
        }
    }
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t; []                                                               
    t=1;
    while(t--)
        solve();
}
