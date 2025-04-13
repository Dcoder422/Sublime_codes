// https://www.youtube.com/watch?v=dOAxrhAUIhA
// https://www.spoj.com/problems/LCASQ/

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

ll depth[10004],dp[10004][16],parent[10004];
    
void solve(){
    ll n; in n;
    For(i,0,n){
        ll m;
        in m;
        while(m--){
            ll a;
            in a;
            parent[a]=i;
        }
    }
    depth[0]=0;
    For(i,1,n)dp[i][0]=parent[i];
    For(i,1,16){
        For(j,1,n)
        depth[j]=depth[parent[j]]+1,
        dp[j][i]=dp[dp[j][i-1]][i-1];
    }
    ll q;
    in q;
    while(q--){
        ll u,v;
        in u >> v;

        if(depth[u]<depth[v])swap(u,v);
        ll k=depth[u]-depth[v];
        ll j=0;
        while(k){
            if(k&1)u=dp[u][j];
            k>>=1;
            j++;
        }
        if(u==v)out u e;
        else{
            rof(i,15,-1){
                if(dp[u][i]!=dp[v][i])
                    u=dp[u][i],
                    v=dp[v][i];
            }
            out parent[u] e;
        }
        
    }
    
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}