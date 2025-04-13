#include <bits/stdc++.h>
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(ll (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(ll (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define pob pop_back()
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define double long double
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
#define countB(x) __builtin_popcount(x)
#define inv(a,n) for(ll (i)=0;(i) < (n); ++(i)) cin >> (a)[i];
#define pa(a,n) for(ll (i)=0;(i) < (n); ++(i)) cout << (a)[i] << " ";cout << endl;
#define pv(a) for(auto &(i) : (a)) cout << (i) << " ";cout << endl;
#define countBl(x) __builtin_popcountll(x)
#define mp(a,b) make_pair((a),(b))
#define yes cout << "YES" << endl;return;
#define no cout << "NO" << endl;return;
#define prio priority_queue
#define inf 1e9+1
#define M 1000000007
#define N 100005
#define out cout << 
#define in cin >>
#define partition_point pp
#define eps 1e-7
#define o << " " <<
#define e << endl
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll n,m,op,id,v,k;
vector<vi> t(4*N,vi (4,0));
vi combine( vi &a, vi &b){
    vi ans(4);
    ans[0]=max({a[0],b[0],a[1]+b[2]});
    ans[1]=max(b[1],b[3]+a[1]);
    ans[2]=max(a[2],a[3]+b[2]);
    ans[3]=a[3]+b[3]; 
    return ans;
}

void solve(){
    in n >> m;
    k=1;
    while(k<n)k*=2;
    For(i,0,n) in v,op=max(0LL,v),t[i+k]={op,op,op,v}; 
    rof(i,k-1,0) t[i]=combine(t[2*i],t[2*i+1]);
    out t[1][0] e;
    while(m--){
        in id >> v; 
        op=max(0LL,v),t[id+k]={op,op,op,v};
        for(int i=(id+k)/2; i>0; i/=2) t[i] = combine(t[2*i], t[2*i+1]);
        out t[1][0] e;
    }
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}