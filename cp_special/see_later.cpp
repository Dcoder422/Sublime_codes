// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);






#include "bits/stdc++.h"
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset = tree<T,null_type,less_equal// for indexed_multiset */
// <T> ,rb_tree_tag,tree_order_statistics_node_update> ;    // order_of_key (k) -> # of elem strictly < k .
//                                                      // *(s.find_by_order(k)) -> element at index K .
#define int              long long int
using   ll=              long long;
#define ld               long double
#define endl             '\n'
#define dbg(x)           cout<<#x<<" is -> "<<x<<endl
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define pb               push_back
#define po               pop_back
#define mp               make_pair
#define sab(x)           x.begin(),x.end()
#define rsab(x)          x.rbegin(),x.rend()
#define ff               first
#define ss               second
#define sz(x)            (int)x.size()
#define sp(x)            fixed<<setprecision(x)
#define uni(edge)        edge.erase(unique(edge.begin(),edge.end()),edge.end());
#define to_up(x)         transform(sab(x),x.begin(),::toupper)
#define to_low(x)        transform(x.begin(),x.end(),x.begin(),::tolower)
#define ONLINE_JUDGE

const int M = 1000000007;
const int MM = 998244353;
const ld Pi= acos(-1);
const int N=1e5+10;
const int inf=1e18;
const int MAXX=1e9;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
/*

int string_to_int(string s){
    stringstream geek(s);
 
    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    geek >> x;
    return x;
}

////--------------------------------- GRAPHS -------------------------------------------------------------///

vector<int>order;
void dfs1(int n){
    vis1[n]=1;
    for(auto x:v[n]){
        if(!vis1[x]){
            dfs1(x);
        }
    }
    order.pb(n);
}
 
vector<int>scc;
vector<int>comp(N);
void dfs2(int n,int c){
    vis2[n]=1;
    scc.pb(n);
    comp[n]=c;
    for(auto x: vrev[n]){
        if(!vis2[x]){
            dfs2(x,c);
        }
    }
}
 
void dijkstra(int n){
    dis[n]=0;
    par[n]=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(mp(0,n));
    // path[n]=1;
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        if(dis[curr.ss]!=curr.ff){
            continue;
        }
        for(auto x:v[curr.ss]){
            if(dis[x.ss]>x.ff+dis[curr.ss]){
                dis[x.ss]=x.ff+dis[curr.ss];
                pq.push(mp(dis[x.ss],x.ss));
                par[x.ss]=curr.ss;
                // path[x.ss]=path[x.ff];
            }
            // else if(dis[x.ss]==x.ff+dis[curr.ss]){
            //     path[x.ss]+=path[x.ff];  // addition when dis are equal to find number of possible paths.
            // }
        }
    }
}

void bfs_0_1(int n){
    dis[n]=0;
    deque<int>q;
    q.push(n);
    while(!q.empty()){
        int curr=q.front();
        q.pop_front();
        for(auto x:v[curr]){
            if(dis[x.ss]>dis[curr]+x.ff){
                dis[x.ss]=dis[curr]+x.ff;
                if(x.ff==1){
                    q.push_back(n);
                }
                else{
                    q.push_front(n);    
                }
            }
        }
    }
}

vector<int>in(N,0);
void find_euler(int n){  // CIRCUIT -> (IN = OUT) OF ALL EDGES AND GRAPH MUST BE A SCC.
    stack<int>st;        // PATH -> ONLY ONE EDGE (IN-OUT)==1 AND ONE (OUT-IN)==1,REST (OUT==IN).
    st.push(n);
    while(!st.empty()){
        int y=st.top();
        vis[y]=1;
        if(sz(v[y])==0){
            st.pop();
            cout<<y<<" "; // the actual eulerian path
        }
        else{
            int curr=v[y].front();
            st.push(curr);
            v[y].erase(find(sab(v[y]),curr));
            // v[curr].erase(find(sab(v[curr]),y));  // erase the other way only if it's not-directed.
        }
    }
}

int up[N][31];
int depth[N];
bool vis[N];

int jump(int a, int d) {
    for(int i=0; i<30; i++) if(d & (1<<i))
        a = up[a][i];
    return a;
}

int get_lca(int x, int y){
    if(depth[x]<depth[y]){
            swap(x,y);
        }
        int k=depth[x]-depth[y];
        for(int j=29;j>=0;j--){ //maxx = ceil(log2(N));
            if(((1ll<<j)&k)){
                x=up[x][j]; // same in K'th ancestor.
            }
        }
        if(x==y){
            return x;
        }
        for(int j=29;j>=0;j--){
            if(up[y][j]!=up[x][j]){
                y=up[y][j];
                x=up[x][j];
            }
        }
        return up[x][0];     
}

vector<int>rnk(N,1);
vector<int>par(N,-1);

int find(int a){
    if(par[a]<0){
        return a;
    }
    return par[a]=find(par[a]);
}
void un(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b){
        return ;
    }
    else if(rnk[a]>=rnk[b]){
        par[b]=a;
        rnk[a]+=rnk[b];
    }
    else{
        par[a]=b;
        rnk[b]+=rnk[a];
    }
}

////-------------------------------------------- GRAPHS --------------------------------------------------///

int inv[N],fac_inv[N],fac[N];
void initialize()
{
    int i;
    inv[1]=1;
    for(i=2;i<=N-2;i++)
        inv[i]=(MM-MM/i)*inv[MM%i]%MM; 
    fac[0]=fac[1]=1;
    for(i=2;i<=N-2;i++)
        fac[i]=i*fac[i-1]%MM;
    fac_inv[0]=fac_inv[1]=1;
    for(i=2;i<=N-2;i++)
        fac_inv[i]=inv[i]*fac_inv[i-1]%MM;

}

int ncr(int n, int r){
    if (r < 0 || n < r) return 0;
    return (((fac[n]%MM)*(fac_inv[r]%MM))%MM*(fac_inv[n-r]%MM))%MM;
}


int msb(int n){ // change 63 to 31 if 32 bit integer is used and use __builtin_clz(n)
    return 63 - __builtin_clzll(n);
}

////--------------------------------------- BITSET IMPORTANT --------------------------------------------////

    bitset<N>ans(0);
    for(int k=ans._Find_first();k<sz(ans);k=ans._Find_next(k)){ // only iterates on the set bits of a bitset.
        // cout<<k+1<<" ";
    }
      # sets representation 
    // F(x,y) = (A U B) - (A intersec B) = (A ^ B); 
    // (A ^ B) = (A + B) - 2*(A & B);
    // (A + B) = (A | B) + (A & B);
    
////-----------------------------------------------------------------------------------------------------////

// first define int as long long int ---> #define int long long int

// const int MOD = MM;  // check mod
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    };

*/
struct segtree{
    
    vector<int>sums,sum2;
    int size_of_sum=1; // raise it to the greater power of 2.
    void init(int n){
        
        while(size_of_sum<n){
            size_of_sum*=2;
        }
        sums.assign(2*size_of_sum,0);
        sum2.assign(2*size_of_sum,0);
    }
    
    void build(vector<int>&v,int x, int l, int r){
        if(r-l==1){
            if(l<sz(v)){
                sum2[x]=1;
                sums[x]=v[l];
            }
            return ;
        }
        int mid=(r+l)/2;
        build(v,2*x+1,l,mid);
        build(v,2*x+2,mid,r);
        int sum_of_leftchild=sums[2*x+1];
        int sum_of_rightchild=sums[2*x+2];
        sums[x]=min(sums[2*x+1],sums[2*x+2]);
        if(sum_of_leftchild==sum_of_rightchild){
            sum2[x]=sum2[2*x+1]+sum2[2*x+2];
        }
        else if(sum_of_leftchild<sum_of_rightchild){
            sum2[x]=sum2[2*x+1];
        }
        else{
            sum2[x]=sum2[2*x+2];
        }
    }
    
    void buildd(vector<int>&v){
        build(v,0,0,size_of_sum);
    }
    
    void update(int index,int value,int x,int l,int r){
        if(r-l==1){
            sums[x]=value;
            sum2[x]=1;
            return ;
        }
        int mid=(r+l)/2;
        if(index<mid){
            update(index,value,2*x+1,l,mid);
        }
        else{
            update(index,value,2*x+2,mid,r);
        }
        sums[x]=min(sums[2*x+1],sums[2*x+2]);
        int left_c=sums[2*x+1];
        int right_c=sums[2*x+2];
        if(left_c==right_c){
            sum2[x]=sum2[2*x+1]+sum2[2*x+2];
        }
        else if(left_c<right_c){
            sum2[x]=sum2[2*x+1];
        }
        else{
            sum2[x]=sum2[2*x+2];
        }
    }
    
    void updatee(int index, int value){
        update(index,value,0,0,size_of_sum);
    }

    pair<int,int> oper(int from, int to, int x, int l, int r){
        if(from>=r || to<=l){
            return mp(inf,0);
        }
        if(from<=l && to>=r){
            return mp(sums[x],sum2[x]) ;
        }
        int mid=(l+r)/2;
        pair<int,int>m1=oper(from,to,2*x+1,l,mid);
        pair<int,int>m2=oper(from,to,2*x+2,mid,r);
        
        if(m1.ff==m2.ff){
            return mp(m1.ff,m1.ss+m2.ss);
        }
        else if(m1.ff>m2.ff){
            return m2;
        }
        else{
            return m1;
        }
    }
    
    pair<int,int> operr(int from,int to){
        return oper(from, to,0,0,size_of_sum);
    }
    
};

vector<int>v,segtree;

void build(int s, int e, int i) {
    if (s == e) {
        segtree[i] = v[s];
        return;
    }
    int mid = s + (e - s) / 2;
    build(s, mid, 2 * i + 1);
    build(mid + 1, e, 2 * i + 2);
    
    segtree[i] = segtree[2 * i + 1] & segtree[2 * i + 2];
}

int range(int s, int e, int i, int qs, int qe) {
    if (qs <= s && qe >= e)
        return segtree[i];
    if (qs > e || qe < s)
        return INT_MAX;
    int mid = s + (e - s) / 2;
    int l = range(s, mid, 2 * i + 1, qs, qe);
    int r = range(mid + 1, e, 2 * i + 2, qs, qe);
    return l & r;
}


void simp(){
    
    // dp?, graph?, bs on answer?, compress/sort queries/array?, stupid observation?
    
    int n;
    cin>>n;
    v.resize(n);
    segtree.resize(5*n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    build(0,n-1,0);
    int q;
    cin>>q;
    while(q--){
        int k,l;
        cin>>l>>k;
        int right=n;
        l--;
        int left=l-1;
        while(right-left>1){
            int mid=(right+left)/2;
            if(range(0,n-1,0,l,mid)>=k){
                left=mid;
            }
            else{
                right=mid;
            }
        }
        if(right==l){
            if(v[l]<k){
                cout<<-1<<" ";
            }
            else{
                cout<<l<<" ";
            }
        }
        else{
            cout<<right<<" ";
        }
    }
    cout<<endl;
}


signed main(){

    speed_;// remove this in interactive problems
    
    // freopen("helpcross.in", "r", stdin);
    // freopen("helpcross.out", "w", stdout);
    
    int t;
    t=1;
    cin>>t;
    
    // initialize();
    // solve();
    
    //gen_factorial(N+10);
    
    int curr=1;
    while(t--){  
        
 #ifndef ONLINE_JUDGE
    
 #endif  
       // cout<<"Case #"<<curr++<<": "; 
        simp();
        
    }
return 0;
}



-----------------------------------------------------










#include <bits/stdc++.h>
using namespace std;
 
#define FORN(i, k) for (int i = 0; i < k; i++)
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
 
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n';
#define int long long
#define MAXN 200001
#define bitscnt 40
 
typedef long long ll;
typedef unsigned long long ull;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;

struct TreapNode {
    char data;
    int priority;
    int size;
    TreapNode* left;
    TreapNode* right;

    TreapNode(char c, int p) {
        data = c;
        priority = p;
        size = 1;
        left = right = nullptr;
    }
};

class Treap {
public:
    TreapNode* root;

    int getSize(TreapNode* node) {
        return (node != nullptr) ? node->size : 0;
    }

    void updateSize(TreapNode* node) {
        if (node != nullptr) {
            node->size = getSize(node->left) + getSize(node->right) + 1;
        }
    }

    pair<TreapNode*, TreapNode*> split(TreapNode* root, int key) {
        if (root == nullptr) return make_pair(nullptr, nullptr);

        if (key <= getSize(root->left)) {
            pair<TreapNode*, TreapNode*> leftRight = split(root->left, key);
            root->left = leftRight.second;
            updateSize(root);
            return make_pair(leftRight.first, root);
        } else {
            pair<TreapNode*, TreapNode*> leftRight = split(root->right, key - getSize(root->left) - 1);
            root->right = leftRight.first;
            updateSize(root);
            return make_pair(root, leftRight.second);
        }
    }

    TreapNode* merge(TreapNode* left, TreapNode* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        if (left->priority > right->priority) {
            left->right = merge(left->right, right);
            updateSize(left);
            return left;
        } else {
            right->left = merge(left, right->left);
            updateSize(right);
            return right;
        }
    }

    TreapNode* reverseTreap(TreapNode* node, bool reverse) {
        if (node == nullptr) return nullptr;

        if (reverse) {
            swap(node->left, node->right);
        }

        node->left = reverseTreap(node->left, reverse);
        node->right = reverseTreap(node->right, reverse);
        updateSize(node);

        return node;
    }

    Treap() {
        root = nullptr;
    }

    void insert(char c, int position, int priority) {
        pair<TreapNode*, TreapNode*> leftRight = split(root, position);
        root = merge(merge(leftRight.first, new TreapNode(c, priority)), leftRight.second);
    }

    void reverseRange(int start, int end) {
        pair<TreapNode*, TreapNode*> leftMiddle = split(root, start);
        pair<TreapNode*, TreapNode*> middleRight = split(leftMiddle.second, end - start + 1);
        middleRight.first = reverseTreap(middleRight.first, true);
        leftMiddle.second = merge(middleRight.first, middleRight.second);
        root = merge(leftMiddle.first, leftMiddle.second);
    }

    string inOrderTraversal(TreapNode* node) {
        if (node == nullptr) return "";

        string left = inOrderTraversal(node->left);
        string current(1, node->data);
        string right = inOrderTraversal(node->right);

        return left + current + right;
    }

    string toString() {
        return inOrderTraversal(root);
    }
};

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        return p1.first > p2.first;
    }
    return p1.second > p2.second;
}

bool comp2(vector<ll> &a, vector<ll> &b){
    if(a[0] == b[0]){
        if(a[1] == b[1]){
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] > b[0];
}

bool isPowerOfK(int n, int k) {
    if (n == 0 || k == 0 || k == 1) {
        return false;
    }

    while (n % k == 0) {
        n /= k;
    }
 
    return n == 1;
}

int binary_search(vector<int>& a, int target) {
    int n = a.size();
    int i = 0, j = n-1;
    while(i <= j){
        int mid = i + (j-i)/2;
        if(a[mid] == target){
            return mid;
        }
        if(target > a[mid]){
            i = mid+1;
        }else{
            j = mid-1;
        }
    }
    return -1;
}

long long binaryToDecimal(string num)
{
    ll dec_value = 0;
    ll base = 1;
    ll len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value = (dec_value + base);
        base = (base * 2);
    }
    return dec_value;
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
        
        return hash1;
    }
};

void primeFactors(int n, map<int, int> &mp){
    while (n % 2 == 0){
        mp[2]++;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){
            mp[i]++;
            n = n/i;
        }
    }
 
    if (n > 2)
        mp[n]++;
}

int fact(int n){
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

ll lcm(ll a, ll b){ // HCF
    return a / __gcd(a, b) * b;
}

vector<int> dir = {0, -1, 0, 1, 0};
void dfs_in_matrix(vector<vector<char>> &a, vector<vector<bool>> &vis, int i, int j){
    if(i < 0 or j < 0 or i >= a.size() or j >= a[0].size() or vis[i][j] or a[i][j] == '#'){
        return;
    }
    vis[i][j] = true;
    for(int k=0; k<4; k++){
        dfs_in_matrix(a, vis, i + dir[k], j + dir[k+1]);
    }
}

void bfs_in_matrix(vector<vector<char>> &a, vector<vector<bool>> &vis, int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y] = true;
        for(int k=0; k<4; k++){
            int p = x + dir[k];
            int r = y + dir[k+1];
            if(p >= 0 and r >= 0 and p < a.size() and r < a[0].size() and vis[p][r] == false and a[p][r] != '#'){
                q.push({p, r});
            }
        }
    }
}

vector<ll> all_primes(){
    const ll N = 10000000;
    vector<ll> lp(N + 1);
    vector<ll> pr;
    for (ll i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
        {
            lp[i * pr[j]] = pr[j];
        }
    }
    return pr;
}

int nCr(int n, int r){
    double sum = 1;
    for(int i = 1; i <= r; i++){
        sum = sum * (n - r + i) / i;
    }
    return sum;
}

int xorFromOne(int n){
    if(n % 4 == 0){
        return n;
    }else if(n % 4 == 1){
        return 1;
    }else if(n % 4 == 2){
        return n + 1;
    }else if(n % 4 == 3){
        return 0;
    }
}

stack<int> stk;
void dfs_topo(int src, vector<vector<int>> &adj, vector<bool> &vis){
    vis[src] = true;
    
    for(auto &k: adj[src]){
        if(!vis[k]){
            dfs_topo(k, adj, vis);
        }
    }
    
    stk.push(src);
}

vector<int> topoSortDFS(int V, vector<vector<int>> &adj){
    vector<int> in(V, 0);
    vector<bool> vis(V, false);
    
    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs_topo(i, adj, vis);
        }
    }
    
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

priority_queue<int> pq;
int dfs(vector<vector<int>> &adj, int p, int d, int src){
    // pq.push(d);
    // cout<<d<<" "<<src+1<<endl;
    int n = 0;
    for(int k: adj[src]){
        // going to the sub tree
        if(k != p){
            n += dfs(adj, src, d+1, k) + 1;
        }
    }
    // cout<<src+1<<" "<<d<<" "<<n<<" "<<(d-n)<<endl;
    pq.push(d - n);
    return n;
}

int check_digit_sum(int x){
    int s = 0;
    while(x){
        s += x % 10;
        x /= 10;
    }
    return s;
}

vector<int> RightRotate(vector<int> a, int n, int k){
    k = k % n;
    vector<int> na;
    for(int i = 0; i < n; i++){
       if(i < k){    
            na.push_back(a[n+i-k]);
       }
       else{
            na.push_back(a[i - k]);
       }
    }
    return na;
}

vector<int> topoSort(int V, vector<vector<int>> adj) 
{
    vector<int> in(V, 0);
    for(int i=0; i<V; i++){
        for(auto &k: adj[i]){
            in[k]++;
        }
    }
    
    queue<int> q;
    for(int i=0; i<V; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto &k: adj[node]){
            in[k]--;
            if(in[k] == 0)
                q.push(k);
        }
    }
    
    return ans;
}

bool isPrime(int n){
    if (n <= 3)
        return n > 1;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

bool isPowerOfTwo(int n){
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

bool hasCycle(int src, vector<vector<int>> &adj, 
    vector<bool> &vis){
    vis[src] = true;
    bool res = true;
    // if(adj[src].size() != 2) res = false;
    for(int k: adj[src]){
        if(!vis[k]){
            res &= hasCycle(k, adj, vis);
        }
    }
    return res;
}

int findPar(int u, vector<int> &parent){
    if(u == parent[u]){
        return u;
    }
    return parent[u] = findPar(parent[u], parent);
}

void doUnion(int u, int v, vector<int> &parent, vector<int> &rank){
    int p1 = findPar(u, parent);
    int p2 = findPar(v, parent);
    if(rank[p1] == rank[p2]){
        parent[p2] = p1;
        rank[p1]++;
    }else if(rank[p1] > rank[p2]){
        parent[p2] = p1;
    }else if(rank[p1] < rank[p2]){
        parent[p1] = p2;
    }
}

int spf[MAXN];
void sieve(){
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
 
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++){
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void bin(int n){
    if (n > 1)
        bin(n / 2);
    cout << n % 2;
}

bool comp_pair(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first > b.first;
}

int get_left(int n){
    for(int i=31; i>=0; i--){
        if((1 << i) & n){
            return i;
        }
    }
    return -1;
}

vector<int> getPFA(vector<int> &a){
    int n = a.size();
    vector<int> pfa(n+1); pfa[0] = 0;
    for(int i=1; i<=n; i++){
        pfa[i] = pfa[i-1] + a[i-1];
    }
    return pfa;
}

int cupper_bound(vector<int> &a, int x){
    int n = a.size();
    int l = 0, r = n-1, ans = -1;
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] == x){
            ans = mid;
        }
        if(a[mid] > x){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}

int clower_bound(vector<int> &a, int x){
    int n = a.size();
    int l = 0, r = n-1, ans = -1;
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] == x){
            ans = mid;
        }
        if(a[mid] < x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return ans;
}

int poww(int a, int b){
    int res = 1;
    while (b) {
        if (b % 2)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res % MOD;
}

int log_a_to_base_b(int a, int b){
    return log2(a) / log2(b);
}

int sumn(int n){
    return n*(n+1)/2;
}

int prefix_count[bitscnt][MAXN];
void findPrefixCount(vector<int> &arr, int n){
    for (int i = 0; i < bitscnt; i++) {
        prefix_count[i][0] = ((arr[0] >> i) & 1);
        for (int j = 1; j < n; j++) {
            prefix_count[i][j] = ((arr[j] >> i) & 1);
            prefix_count[i][j] += prefix_count[i][j - 1];
        }
    }
}
 
int rangeAnd(int l, int r){
    int ans = 0;
    if(l > r){
        return 0;
    }
    for (int i = 0; i < bitscnt; i++) {
        int x;
        if (l == 0)
            x = prefix_count[i][r];
        else
            x = prefix_count[i][r]
                - prefix_count[i][l - 1];
        if (x == r - l + 1)
            ans = (ans | (1 << i));
    }
 
    return ans;
}

int findR(int rl, int n, int k){
    int l = rl, r = n-1, ans = -1;
    if(l > r){
        return 0;
    }
    while(l <= r){
        int mid = (l + r)/2;
        if(rangeAnd(rl, mid) >= k){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    // cout<<rangeAnd(rl, ans)<<endl;
    if(ans != -1){
        return ans + 1;
    }
    return ans;
}

void solve(){
    // Write code here
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int qr;
    cin>>qr;
    int rl, k;
    // int ttt = __builtin_popcount(MOD);
    // cout<<ttt<<endl;
    findPrefixCount(a, n);
    for(int i=0; i<qr; i++){
        cin>>rl>>k;
        int x = findR(rl-1, n, k);
        cout<<x<<" ";
    }
    cout<<endl;

}

int32_t main() {
    #ifdef ONLINEJUDGE
        // clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin.tie(0);
    ll _ = 1;
    cin>>_;
    while(_--){
        // sieve();
        solve();
    }
    return 0;
}







#include <bits/stdc++.h>
using namespace std;
using ll=long long;

signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ll tes;cin>>tes;
    while(tes--)
    {
        string s;ll ind;cin>>s>>ind;
        ll n=s.length();
        set<ll> st;
        set<ll> posspeak;
        for(ll i=0;i<n-1;i++)
        {
            if(s[i]>s[i+1])
            {
                posspeak.insert(i);
            }
            st.insert(i);
        }
        posspeak.insert(n-1);st.insert(n-1);
        ind--;
        while(ind>=0)
        {
            ll e=st.size();
            if(ind<e)
            {
                // cout<<"HI\n";
                while(ind--)
                    st.erase(st.begin());
                cout<<s[(*st.begin())];break;
            }
            ind-=e;
            auto it=posspeak.begin();
            ll index=(*it);
            auto it1=st.lower_bound(index),it2=st.upper_bound(index);
            ll l=-1,r=n,r1=n;
            if(it1!=st.begin())
            {
                it1--;l=(*it1);
            }
            if(it2!=st.end())
            {
                r=(*it2);
                it2++;
                if(it2!=st.end())
                    r1=(*it2);
            }
            posspeak.erase(index);st.erase(index);
            if(l==-1)
                ;
            else if(l!=-1 && r==n)
                posspeak.insert(l);
            else if(s[l]>s[r])
                posspeak.insert(l);
        }
    }
} 

--------------------------------------------------------------------------


#include <bits/stdc++.h>
// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
// template<typename T>
// using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

// Macros
#define F first
#define S second
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define int long long

// Custom hash map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}

template <typename T>
int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }

// Mathematical functions
int GCD(int a, int b) {
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int GCD_extended(int a, int b, int &x, int &y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

int modpow(ll x, int n, int m = MOD)
{
    ll res = 1;
    while (n > 0) 
    {
        if (n & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}
int modinv(int x, int m = MOD)
{   
    return modpow(x, m - 2, m);
}

mt19937 rng;
int getRandomNumber(int l, int r)
{
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

// void allocateStackMax()
// {
//     rlimit R;
//     getrlimit(RLIMIT_STACK, &R);
//     R.rlim_cur = R.rlim_max;
//     setrlimit(RLIMIT_STACK, &R);
// }

/**
 * SUBSCRIBE TO MY YT CHANNEL
 * CMC https://www.youtube.com/channel/UCt_wvjXhvarpI64wBrYAYQw
 * SHAMELES PLUG :D
 */

// Flags to use: -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
///////////////////////////////////////////////////////////// START CODE HERE /////////////////////////////////////////////////////////////

void preSolve()
{
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    // allocateStackMax();
}

constexpr int N = 2e5;
int cost[N + 1], sum[N + 1], a[N + 1];
vector<int> adj[N + 1];
int ans = 0;

void preCal(int u = 1, int prev = 0)
{
    sum[u] = a[u];
    for (auto v : adj[u])
    {
        if (v == prev) continue;
        preCal(v, u);
        sum[u] += sum[v];
        cost[u] += sum[v] + cost[v];
    }
}

void dfs(int u = 1, int prev = 0)
{
    ans = max(ans, cost[u]);
    for (auto v : adj[u])
    {
        if (v == prev) continue;
        int newCost = cost[u] - cost[v] - sum[v];
        cost[v] += newCost + sum[u] - sum[v];
        sum[v] = sum[u];
        dfs(v, u);
    }
}

void solve(int tc)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    preCal();
    dfs();

    print(ans);
}

int32_t main()  
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;

    preSolve();
    int tests = 1;
    // cin >> tests;
    for (int tt = 1; tt <= tests; tt++)
        solve(tt);
    return 0;
}