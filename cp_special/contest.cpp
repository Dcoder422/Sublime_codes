

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
#define ld long double
 
const ll N=1e5+5,M=1e9+7,INF=LLONG_MAX,V=2e6+1;





ll binExp(ll a,ll b){
    ll ans =1;
    while(b){
        if(b&1)ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}

//  gives (a/b)%M
ll div_mod(ll a,ll b){
    ll bi = binExp(b,M-2); 
    return ((a%M)*bi)%M;
}


void solve(){
    int n; cin >> n;
    string ss;
    cin >> ss;
    ll prob=0,prob1;
    ll dp[2][n+2];
    memset(dp,0,sizeof(dp));
    dp[0][n+1]=1;
    dp[1][n+1]=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='0'){
            dp[1][i+1]=dp[1][i+2]*2;
            dp[0][i+1]=dp[0][i+2]+dp[]
        }
        else{
            dp[1][i+1]=dp[1][i+2]/2+;
            dp[0][i+1]=dp[1][i+2]/2;
        }
    }
    cout << prob << endl;

    // cout << (n+(n-1)*((1<<ct)-1)) << endl;
    // ct--;
    // for(ct=1;ct<11;ct++)
    // cout << __gcd(n+(n-1)*((1<<ct)-1),1<<ct) << endl;
    // cout << div_mod(n+(n-1)*((1<<ct)-1),1<<ct) << endl;
    // // else 
    // //     cout << n-1 << endl;
    // cout << ct << endl;


}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // presolve();
    // int n=843;int ct=0;
    // for(int i=1;i<=5;i++){
    //     n=843;
    //     int st=0;ct=0;
    //     while(n>1){
    //         st++;
    //         int val = n&1;
    //         ct+=n&1;
    //         n/=2;
    //         // if(i==ct or ct==i+1 or ct==i+2 or ct==i+3 or ct==i+4 or ct==i+5)n+=val;
    //         if(ct!=i and val){
    //             cout << ct << " " << n << endl;
    //             n+=val;
    //         }
    //         // cout << n << endl;
    //     }
    //     cout << i << " " << st << " " << ct << endl;
    // }
    
    // cout << n <<" " << ct << endl;
    // cout << div_mod(289,32) << endl;
    int t;
    cin >> t;                                                            
    while(t--)
        solve();
} 
 








#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
#define ld long double
 
const ll N=1e5+5,M=1e9+7,INF=LLONG_MAX,V=2e6+1;
 
int f[3]={1,2,3};
int query(){
    cout << "? "<< f[0] << " " << f[1] << " " << f[2] << endl;
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void solve(){ 
    int n; cin >> n;
    
    while(1){
        int val = query();
        if(!val){
            cout << "! " << f[0] << " " << f[1] << " " << f[2] << endl;
            cout.flush();
            return; 
        }
        int c[3];
        for(int i=0;i<3;i++){
            int tmp = f[i];
            f[i]=val;
            c[i]=query();
            f[i]=tmp;    
        }
        int ix = min_element(c,c+3)-c;
        f[ix]=val;
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // presolve();
    int t;
    cin >> t;                                                            
    // t=1;   
    while(t--)
        solve();
} 




#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
#define ld long double
 
const ll N=1e5+5,M=1e9+7,INF=LLONG_MAX,V=2e6+1;
 

void solve(){ 
    int n,m; cin >> n >> m;
    vector<ll> x(n),r(n);
    ll ct =0;
    map <ll,ll> ym;
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int i=0;i<n;i++)
        cin >> r[i];
    for(int i=0;i<n;i++){
            for(ll xx=-r[i];xx<=r[i];xx++){
                ll yy = sqrt(r[i]*r[i]-xx*xx);
                ym[x[i]+xx]=max(ym[x[i]+xx],yy);
            }
    }
    for(auto i : ym)
        ct+=2*i.ss+1;
    cout << ct << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // presolve();
    int t;
    cin >> t;                                                            
    // t=1;   
    while(t--)
        solve();
} 



























#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ff first
#define ss second
 
const ll N=2e5+8,M=1e3,INF=1e17;

vector<ll> t(4*N,0);
 
void solve(){
    int n ,q ;
    cin >> n >> q;
    int k=1;
    while(k<n)k*=2;
    for(int i=0;i<n;i++)
        cin >> t[i+k];
    for(int i=k-1;i;i--)t[i]=(t[i*2]^t[i*2+1]);
    while(q--){
        int op,a,b; 
        cin >> op >> a >> b;
        a--; 
        if(op==1){
            t[a+k]=b; 
            for(int i=(a+k)/2;i;i/=2)
                t[i]=min(t[i*2],t[i*2+1]);
        }
        else{
            ll res = INF; 
            for(int l=a+k,r=b+k;l<r;l/=2,r/=2){
                if(l&1)res=min(res,t[l++]);
                if(r&1)res=min(t[--r],res);
            }
            cout << res << endl;
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
void solve(){
    ll n; in n;
    string k;in k;
    ll tmp=0,ans=0,mul=1,xx=1;
    rof(i,k.size()-1,-1){
        if(tmp+xx*(k[i]-'0')<n)tmp+=xx*(k[i]-'0'),xx*=10;
        else{
            out tmp o mul e;
            ans+=mul*tmp;
            tmp=(k[i]-'0');
            out tmp e;
            xx=10;
            mul*=n ;
        }
    }
    ans+=mul*tmp;
    out ans e;
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}




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
// #define inf 1e9+1
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

vector<string> vs;

priority_queue<pair<ll,pair<pii,pii>>> q;
ll n,m,k; 
ll vis[1002][1002];

bool valid(ll a,ll b,ll di){
    return (a>=0 and b>=0 and a<n and b<m and vs[a][b]=='.');
}

pii mo[]={{-1,0},{1,0},{0,1},{0,-1}};

void solve(){
    For(i,0,1002)For(j,0,1002)vis[i][j]=INT_MAX;
    in n >> m >>k ;
    For(i,0,n){
        string s; 
        in s; 
        vs.push_back(s);
    }    
    ll sx,sy;
    pii d; 
    in sx >> sy >> d.x >> d.y ;
    sx--,sy--,d.x--,d.y--;
    
    q.push({0,{{-1,0},{sx,sy}}});
    vis[sx][sy]=0;
    ll ct=0;
    while(!q.empty()){
        ct++; 
        if(ct>1002*1002*5)break;

        auto cv = q.top();
        q.pop();

        auto po=cv.y.y; 
        auto inf = cv.y.x;

        if()


        if(po==d){
            out -cv.x ;
            out ct e;
            return;
        }
        For(i,0,4){
            ll a = po.x+mo[i].x ; 
            ll b = po.y+mo[i].y;
            if(valid(a,b,i)){
                if(inf.x==i){
                    ll t=inf.y==k?1:0;
                    ll dis = inf.y==k?1:inf.y+1;
                    q.push({cv.x-t,{{i,dis},{a,b}}});
                }
                else{
                    q.push({cv.x-1,{{i,1},{a,b}}});
                }
            }
        }
    }
    out -1 ;
}

int main(){
    fastio();
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}
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
ll n,m,op,lx,rx,v,ans,k,as,a,d,sum,dele; 
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
    // out val[id][0] o  val[id][1] o id e;
    if(val[id][1]<lx or val[id][0]>n)return;
    if(val[id][0]>=lx and val[id][1]<=rx){
        if(sum!=LLONG_MAX)val[id][2]=sum;
        val[id][3]=d;
        val[id][4]=max(fst_el(id),lst_el(id));
        sum=lst_el(id);
        // pv(val[id]);
        return;        
    }
    if(val[id][0]>rx and val[id][1]<=n ){
        if(dele==LLONG_MAX)dele = sum-val[id][2];
        apply(id,dele);
        // out " ex ";  
        // pv(val[id]);
        return;
    }
    propagate(id);
    do_ops(id*2);
    do_ops(id*2+1);
    val[id][2]=val[2*id][2];
    val[id][4]=max(val[id*2][4],val[id*2+1][4]);
    // out val[id*2+1][4] e;
    // cout << id << " fen "  <<" ";
    // pv(val[id]);
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
    // len=400000;
    k=1;while(k<len)k*=2;
    // out 2*k e;
    // return;
    For(i,0,len)
    val[i+k][0]=seg[i].x,val[i+k][1]=seg[i].y;
    For(i,len,k)val[i+k][0]=val[i+k][1]=n+1+i-len;
    rof(i,k-1,0)val[i][0]=val[2*i][0],
    val[i][1]=val[2*i+1][1];
    // val[i][4]=max(val[2*i][4],val[2*i+1][4]);
    // For(j,0,2*k){pv(val[j]);}
    rep(i,que){
        sum=dele=LLONG_MAX;
        if(i.size()==3){
            lx=i[0],rx=i[1],d=i[2];
            do_ops();
            // out val[1][4] e;
        } 
        else{
            v=i[0];
            // assert(v>0);
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



























// #include <bits/stdc++.h>
// using namespace std;
// #define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
// #define For(i,a,b) for(ll (i)=(a);(i) < (b); ++(i))
// #define rof(i,a,b) for(ll (i)=(a);(i) > (b); --(i))
// #define rep(i, c) for(auto &(i) : (c))
// #define x first
// #define y second
// #define pb push_back
// #define pob pop_back()
// #define sqr(a) (((a) * (a)))
// #define all(a) a.begin() , a.end()
// #define coud(a,b) cout<<fixed << setprecision((b)) << (a)
// #define double long double
// typedef long long ll;
// typedef pair<ll,ll> pii;
// typedef vector<ll> vi;
// #define countB(x) __builtin_popcount(x)
// #define inv(a,n) for(ll (i)=0;(i) < (n); ++(i)) cin >> (a)[i];
// #define pa(a,n) for(ll (i)=0;(i) < (n); ++(i)) cout << (a)[i] << " ";cout << endl;
// #define pv(a) for(auto &(i) : (a)) cout << (i) << " ";cout << endl;
// #define countBl(x) __builtin_popcountll(x)
// #define mp(a,b) make_pair((a),(b))
// #define yes cout << "YES" << endl;return;
// #define no cout << "NO" << endl;return;
// #define prio priority_queue
// #define inf 1e9+1
// #define M 1000000007
// #define N 100005
// #define out cout << 
// #define in cin >>
// #define partition_point pp
// #define eps 1e-7
// #define o << " " <<
// #define e << endl
// #define n0 0LL
// #define n1 1LL
// #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// ll n,m,k,op,l,r;
// vector<vi> t(4*N,vi (4,0));

// vi combine( vi &a, vi &b){
//     //...
//     vi ans(4);
     
//     return ans;
// }
// //O(logn)
// ll query(int node=1, int st=0 , int en=n-1){
//     if(st>r || en<l) return 0;
//     if(st>=l && en<=r) return tree[node];

//     int mid=(st+en)/2;

//     return query(2*node,st,mid)+query(2*node+1,mid+1,en);
// }
// void solve(){
//     in n >> m;
//     k=1;
//     while(k<n)k*=2;
//     For(i,0,n) in l,t[i+k]={}; 
//     rof(i,k-1,0) t[i]=combine(t[2*i],t[2*i+1]);
//     while(m--){
//         in op >> l >> r;
//         if(op==1){
//             t[l+k]={};
//             for(int i=(l+k)/2; i>0; i/=2) t[i] = combine(t[2*i], t[2*i+1]);
//         }
//         else{
//             vi res={}; //.. r is excluded acc to code
//             // so take r grater as r+1 if in ques querry it is included
            
//             for(l=l+k, r=r+k; l<r; l/=2, r/=2) {
//                 if(l % 2) res = combine(res, t[l++]);
//                 if(r % 2) res = combine(res, t[--r]);
//             }
//             out ;

//             // for top-down
            
//             // r=1;
//             // while(r<k){
//             //     out r o l e;
//             //     if(t[2*r]>=l)r*=2;
//             //     else l-=t[2*r],r=2*r+1;
//             // }
//             // out r-k e;
//         }
//     }
// }

// int main(){
//     fastio();
//     // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
//     solve();
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define INF (int)1e18

// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// vector<int> manacher_odd(string s) {
//     int n = s.size();
//     s = "$" + s + "^";
//     vector<int> p(n + 2);
//     int l = 1, r = 1;
//     cout << s << endl;
//     for(int i = 1; i <= n; i++) {
//         p[i] = max(0, min(r - i, p[l + (r - i)]));
//         while(s[i - p[i]] == s[i + p[i]]) {
//             p[i]++;
//         }
//         if(i + p[i] > r) {
//             l = i - p[i], r = i + p[i];
//         }
//     }
//     for (auto i:p ) cout << i ;
//     return vector<int>(begin(p) + 1, end(p) - 1);
// }

// vector<int> manacher(string s) {
//     string t;
//     for(auto c: s) {
//         t += string("#") + c;
//     }
//     auto res = manacher_odd(t + "#");
//     return vector<int>(begin(res) + 1, end(res) - 1);
// }

// #define int long long

// void Solve() 
// {
//     int n, q; cin >> n >> q;

//     string s; cin >> s;
//     auto v = manacher(s);
//     for (auto &x : v) x--;

//     // we also need to know if all same, and all alternating 
//     set <int> s1, s2;
//     for (int i = 0; i < n - 1; i++){
//         if (s[i] != s[i + 1]) s1.insert(i);
//         if (i != n - 1 && s[i] != s[i + 2]) s2.insert(i);
//     }

//     while (q--){
//         int l, r; cin >> l >> r;
//         l--;
//         r--;

//         if (l == r){
//             cout << 0 << "\n";
//             continue;
//         }
        
//         int len = r - l + 1;

//         int ans;
//         auto it = s1.lower_bound(l);
//         if (it == s1.end() || (*it) >= r){
//             ans = 0;
//         } else {
//             it = s2.lower_bound(l);
//             if (it == s2.end() || (*it) >= r - 1){
//                 ans = ((len - 1)/ 2) * (((len - 1) / 2) + 1);
//             } else {
//                 ans =  len * (len - 1) / 2 - 1;
//             }
//         }

//         if (v[l + r] < (r - l + 1)) ans += len;

//         cout << ans << "\n";
//     }
// }

// int32_t main() 
// {
//     auto begin = std::chrono::high_resolution_clock::now();
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     // freopen("in",  "r", stdin);
//     // freopen("out", "w", stdout);
    
//     cin >> t;
//     for(int i = 1; i <= t; i++) 
//     {
//         //cout << "Case #" << i << ": ";
//         Solve();
//     }
//     auto end = std::chrono::high_resolution_clock::now();
//     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
//     cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
//     return 0;
// }