//https://atcoder.jp/contests/dp/tasks/dp_r


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

int n;
struct mat{
    vector<vi> t; 
    mat(){
        t.resize(n,vi(n));
    }
    mat operator* (const mat &b) const{
        mat c;
        For(i,0,n){
            For(j,0,n){
                For(k,0,n){
                    c.t[i][j]+=(t[i][k]*b.t[k][j])%M; 
                    c.t[i][j]%=M;
                }
            }
        }
        return c;
    }
};


void solve(){
    ll k; in n >> k;
    mat a;
    For(i,0,n)For(j,0,n)in a.t[i][j];
    mat ans;
    For(i,0,n)ans.t[i][i]=1;
    while(k){
        if(k&1)ans = ans*a;
        a=a*a;
        k>>=1;
    }
    ll tot=0;
    For(i,0,n)For(j,0,n)tot=(tot+ans.t[i][j])%M;
    out tot ;
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}