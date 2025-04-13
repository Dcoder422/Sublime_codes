//https://usaco.guide/problems/ioi-05-mountain/user-solutions
//https://dmoj.ca/submission/6782207


// I am incrementing range a to b with AP and from b + 1 to n + 1 with the constant value which was increased due to the increments in the AP.
 
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
#include <cassert>
ll n,m,op,lx,rx,v,ans,k,as,a,d,sum,del; 
ll NEUTRAL=0,NO_OPERATION=LLONG_MAX-1;
vector<vi> val(1048580,vi(5,0));
 
ll lst_el(ll id){
    return val[id][2]+(val[id][1]-val[id][0]+1)*val[id][3];
}
ll fst_el(ll id){
    return val[id][2]+val[id][3];
}
void apply(ll id,ll cha){
    val[id][2]+=cha;
    val[id][4]+=cha;
}
 
void propagate(ll id){
    if(val[id][3]!=NO_OPERATION){
        val[2*id][3]=val[2*id+1][3]=val[id][3];
 
        val[2*id][2]=val[id][2];
        val[2*id][4]=max(fst_el(2*id),lst_el(2*id));
 
        val[2*id+1][2]=lst_el(2*id);
        val[2*id+1][4]=max(fst_el(2*id+1),lst_el(2*id+1));
 
        val[id][3]=NO_OPERATION;
    }
    else{
        apply(2*id+1,val[id][2]-val[2*id][2]);
        apply(2*id,val[id][2]-val[2*id][2]);
    }
}
 
void do_ops(ll id=1){
    if(val[id][1]<lx or val[id][0]>n)return;
    if(val[id][0]>=lx and val[id][1]<=rx){
        if(sum!=LLONG_MAX)val[id][2]=sum;
        val[id][3]=d;
        val[id][4]=max(fst_el(id),lst_el(id));
        sum=lst_el(id);
        return;        
    }
    if(val[id][0]>rx and val[id][1]<=n ){
        if(del==LLONG_MAX)del = sum-val[id][2];
        apply(id,del);
        return;
    }
    propagate(id);
    do_ops(id*2);
    do_ops(id*2+1);
    val[id][2]=val[2*id][2];
    val[id][4]=max(val[id*2][4],val[id*2+1][4]);
}
 
void calc_val(ll id=1){
    if(val[id][4]<=v )return;
    if(val[id][3]!=NO_OPERATION ){
        if(val[id][3])ans=val[id][0] +(v-val[id][2])/val[id][3];
        else ans=val[id][0];
        return;
    }
    propagate(id);
    calc_val(id*2);
    if(ans==n+1)calc_val(id*2+1);
}
 
vector<vi> que;
set<ll> se;
void solve(){
    in n; 
 
    while(1){
        char ch ;
        in ch ;
        if(ch=='E')break;
        else if(ch=='I'){
            vi temp(3);
            For(i,0,3)in temp[i];
            se.insert(temp[0]);
            se.insert(temp[1]);
            que.push_back(temp);
        }
        else{
            vi temp(1);
            in temp[0];
            que.push_back(temp);
        }
    }
    se.insert(1);
    se.insert(n);
    vector<pii> seg;
    seg.push_back({0,0});
    for(auto i : se){
        ll lst = seg.back().y;
        if(i-1-lst-1>=0)seg.push_back({lst+1,i-1});
        seg.push_back({i,i});
    }
    ll len=seg.size();
    k=1;while(k<len)k*=2;
    For(i,0,len)
    val[i+k][0]=seg[i].x,val[i+k][1]=seg[i].y;
    For(i,len,k)val[i+k][0]=val[i+k][1]=n+1+i-len;
    rof(i,k-1,0)val[i][0]=val[2*i][0],
    val[i][1]=val[2*i+1][1];
 
    rep(i,que){
        sum=del=LLONG_MAX;
        if(i.size()==3){
            lx=i[0],rx=i[1],d=i[2];
            do_ops();
        } 
        else{
            v=i[0];
            ans=n+1;
            calc_val();
            out max(0ll,ans-1) e;
        }
 
    }
}
 
int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}