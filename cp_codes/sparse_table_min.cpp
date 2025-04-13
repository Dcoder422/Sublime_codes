// O(1)->min,max,gcd,lcd
// https://www.spoj.com/problems/RMQSQ/
// https://www.youtube.com/watch?v=0jWeUdxrGm4

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// find_by_order, order_of_key
//  declaration => oset<data_type> s;
#define lb lower_bound
#define ub upper_bound

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
#define e << "\n"
#define inv(a,n) for(ll (i)=0;(i) < (n); ++(i)) cin >> (a)[i];
#define pa(a,n) for(ll (i)=0;(i) < (n); ++(i)) cout << (a)[i] << " ";cout e;
#define pv(a) for(auto &(i) : (a)) cout << (i) << " ";cout e;
#define countBl(x) __builtin_popcountll(x)
#define mp(a,b) make_pair((a),(b))
#define yes cout << "YES" e;return;
#define no cout << "NO" e;return;
#define prio priority_queue
#define inf 1e9+1
#define M 1000000007
#define N 100005
#define out cout << 
#define in cin >>
#define partition_point pp
#define eps 1e-7
#define o << " " <<
#define n0 0LL
#define n1 1LL
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll dp[N][20];

void solve(){
    ll n; 
    in n;
    ll a[n];
    inv(a,n);
    For(i,0,n)dp[i][0]=a[i];
    For(i,1,20){
        For(j,0,n-(1<<i)+1)
        dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
    }
    ll q; in q;
    
    while(q--){
        ll l,r; 
        in l >> r;
        ll len=r-l+1,logg=31-__builtin_clz(len);
        out min(dp[l][logg],dp[r-(1<<logg)+1][logg]) e;
    }
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}