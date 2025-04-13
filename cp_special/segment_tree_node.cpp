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

class node{
public:
    ll sum,seg,suf,pre;
    node(){}
    node(ll a,ll b,ll c , ll d){
        sum = a;
        seg = b;
        suf = c;
        pre = d;
    }
};
node* t[2*N];
void assignn(node*cur,ll a,ll b,ll c , ll d){
    cur->sum = a;
    cur->seg = b;
    cur->suf = c;
    cur->pre = d;
}
void combine(node* a,node* b,node* &cur){
    if(a==NULL)cur=b;
    else if(b==NULL)cur=a;
    else assignn(cur,a->sum + b->sum,max({a->seg,b->seg,a->suf+b->pre}),max(b->suf,b->sum+a->suf),max(a->pre,b->pre+a->sum));
}
void solve(){
    ll n,m,k=1; 
    in n >> m; 
    while(k<n)k*=2;
    For(i,0,2*N)t[i]=NULL;
    For(i,0,n){
        ll a; in a;
        t[i+k]=new node(a,max(0ll,a),max(0ll,a),max(0ll,a));
    }
    rof(i,k-1,0){t[i]=new node();combine(t[i*2],t[i*2+1],t[i]);}
    out t[1]->seg e;
    while(m--){
        ll id,a;
        in id >> a;
        assignn(t[id+k],a,max(0ll,a),max(0ll,a),max(0ll,a));
        for(ll i=(id+k)/2;i;i/=2)
            combine(t[i*2],t[i*2+1],t[i]);
        out t[1]->seg e;
    }
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}