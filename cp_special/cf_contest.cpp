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
#define N 200005
#define out cout << 
#define in cin >>
#define partition_point pp
#define eps 1e-7
#define o << " " <<
#define e << endl
#define n0 0LL
#define n1 1LL
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve(){
    ll n,l,a,b;
    in n >> l >> a >> b;
    ll ar[n];
    inv(ar,n);
    int fox=0,foy=0;
    map<ll,ll> ma;
    For(i,0,n) ma[ar[i]]++;
    For(i,0,n){
        if(ma[ar[i]+a]){
            fox=1;
            break;
        }
    }
    For(i,0,n){
        if(ma[ar[i]+b]){
            foy=1;
            break;
        }
    }
    if(fox && foy) out 0;
    else if(fox) out 1 e << b;
    else if(foy) out 1 e << a;
    else{
        
        if(ma[a+b] || ma[a-b] ) {out 1 e << a;return;}
        
        if(ma[a+b] || ma[b-a]) {out 1 e << b;return;}
        out 2 e << a o b;

    }
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}