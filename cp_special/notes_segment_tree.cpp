//may need a query function
ll n,m,op,val,k,id,idx,r,le,ri,ct;
vi t(4*N,INT_MAX);
void query(ll l,ll  r,ll id){
    if(r<le or l>ri or t[id]>val)return;
    if(l==r){
        ct++,
        t[id]=INT_MAX;
        for(ll i=id/2;l=i;i/=2)
                t[i]=min(t[2*i],t[2*i+1]);
        return;
    }
    ll mid = (l+r)/2;
    query(l,mid,id*2);
    query(mid+1,r,id*2+1);
}


// for cumulative operation
// A*B=B*A

ll n,m,op,val,k,id,idx,r,le,ri;
vector<pii> t(4*N,{0ll,vi(41,0ll)});
 
void combine(pii &a , pii &b , pii &c){
    ll ans=0; 
    rof(i,40,0){
        (c.y)[i]=(b.y)[i]+(a.y)[i];
        if((c.y)[i])ans++;
    }
    c.x=ans;
}
 
 
void solve(){
    in n >> m;
    k=1; 
    while(k<n)k*=2;
    For(i,0,n){
        ll a;
        in a;
        (t[i+k].y)[a]++;
        (t[i+k].x)=1;
    }
    rof(i,k-1,0)combine(t[2*i],t[2*i+1],t[i]);
    while(m--){
        in op >> le >> ri ;
        if(op==1){
            pii rl={0ll,vi(41,0ll)};
            for(ll l=le-1+k,r=ri+k; l<r ; l/=2,r/=2){
                if(l&1)combine(rl,t[l++],rl);
                if(r&1)combine(t[--r],rl,rl);
            }
            out rl.x e;
        }
        else{
            t[le-1+k].y=vi(41,0ll);
            (t[le-1+k].y)[ri]++;
            for(ll l=(le-1+k)/2;l;l/=2)
                combine(t[2*l],t[2*l+1],t[l]);
        }
    }
    
}


// for non cumulative operation(ex, matrix multiplication , assignment)
// A*B!=B*A

if(op==1){
    pii rl={0ll,vi(41,0ll)},rr={0ll,vi(41,0ll)};
    for(ll l=le-1+k,r=ri+k; l<r ; l/=2,r/=2){
        if(l&1)combine(rl,t[l++],rl);
        if(r&1)combine(t[--r],rr,rr);
    }
    combine(rl,rr,rl);
    out rl.x e;
}

// may require a temp variable
vi resl={1,0,0,1},tmpl={1,0,0,1},resr={1,0,0,1},tmpr={1,0,0,1};
for(ll l=k+le-1,rii=ri+k;l<rii;l/=2,rii/=2){
    if(l&1)combine(tmpl,t[l++],resl);
    tmpl=resl;
    if(rii&1)combine(t[--rii],tmpr,resr);
    tmpr=resr;
}
combine(tmpl,tmpr,resl);



// // // // //   MASS OPERATION (opeations done on segments)   // // // // //


// Quries-> 
// . add to the segment from l to r−1 the number v,
// . find the current value of element i


void solve(){
    in n >> m;
    k=1; 
    while(k<n)k*=2;
    while(m--){
        in op  ;
        if(op==1){
            in le >> ri >> val;
            for(ll l=le+k,r=ri+k;l<r;l/=2,r/=2){
                if(l&1)t[l++]+=val;
                if(r&1)t[--r]+=val;
            }
        }
        else{
            in val;
            val+=k; ans=0;
            while(val){
                ans+=t[val];
                val/=2;
            }
            out ans e;
        }
    }
    
}



// // // // //   MASS OPERATION (opeations done on segments)   // // // // //

// // // // //   LAZY PROPAGATION (for non cumulative operations)  // // // // //



ll n,m,op,val,k,id,le,ri;
const ll NO_OPERATION=LLONG_MAX;
vi t(4*N,NO_OPERATION);

void combine(ll a,ll b,ll &c){
    if(b==NO_OPERATION){
        c=a;return;
    }
    c=b;
}

void propagate(ll id){
    combine(t[id*2],t[id],t[id*2]);
    combine(t[id*2+1],t[id],t[id*2+1]);
    // out t[id*2] o t[id*2+1] o id e;
    t[id]=NO_OPERATION;
}

void modify(ll l=0,ll r=k-1,ll id=1){
    if(r<le or l>ri)return;
    if(l>=le and r<=ri){
        combine(t[id],val,t[id]);
        // out id o t[id] e;
        return;
    }
    if(l!=r)propagate(id);
    ll mid = (l+r)/2;
    modify(l,mid,id*2);
    modify(mid+1,r,id*2+1);
}

void solve(){
    in n >> m;
    k=1; 
    while(k<n)k*=2;
    For(i,0,n)t[i+k]=0;
    while(m--){
        in op  ;
        if(op==1){
            in le >> ri >> val;
            ri--;
            modify();
        }
        else{
            in le;
            ri=le;
            val=NO_OPERATION;
            modify();
            out t[le+k] e;
        }
    }
    
}


// // // // //  Segment Tree, part 2 » Step 2 // 2 operations /// /// / /// / / / // 

ll n,m,op,lx,rx,v,ans,k; 
vi ops(4*N,0),val(4*N,0);
ll NEUTRAL=0;

void combine1(ll a,ll b , ll &c){
    c=(a|b);
}

void combine2(ll a,ll b, ll &c){
    if(a==-1)c=b; 
    else if(b==-1)c=a;
    else c=(a&b);
}

void do_ops(ll l=0,ll r=k-1,ll id=1){
    if(l>rx or r<lx)return;
    if(l>=lx and r<=rx){
        combine1(ops[id],v,ops[id]);
        combine1(val[id],v,val[id]);
        return;
    }
    int mid = (l+r)/2; 
    do_ops(l,mid,id*2);
    do_ops(mid+1,r,id*2+1);
    combine2(val[id*2],val[id*2+1],val[id]);
    combine1(val[id],ops[id],val[id]);
}

ll calc_val(ll l=0,ll r=k-1,ll id=1){
    if(l>rx or r<lx)return -1;
    if(l>=lx and r<=rx){
        return val[id];
    }
    int mid = (l+r)/2; 
    ll ans;
    combine2(calc_val(l,mid,id*2),calc_val(mid+1,r,id*2+1),ans); 
    combine1(ans,ops[id],ans);
    return ans;
}

void solve(){
    in n >> m; 
    k=1; while (k<n)k*=2;
    // For(i,0,n)val[i+k]=1;
    // rof(i,k-1,0)combine2(val[2*i],val[2*i+1],val[i]);
    while(m--){
        in op;
        if(op==1){
            in lx >> rx >> v;
            rx--;
            do_ops();
        }
        else{
            in lx >> rx;
            rx--;
            out calc_val() e;
        }
    }
}


/// for ques involving len use-> r-l+1 
// for sum of segments
combine1(ans,ops[id]*(min(r,rx)-max(l,lx)+1),ans);

////////////////////////////// lazy with 2 operations ////////////////////

ll n,m,op,lx,rx,v,ans,k; 
ll NEUTRAL=LLONG_MAX,NO_OPERATION=LLONG_MAX-1;
vi ops(4*N,0),val(4*N,NEUTRAL);

void combine1(ll a,ll b , ll &c){
    if(b==NO_OPERATION)return;
    c=b;
}

void combine2(ll a,ll b, ll &c){
    c=min(a,b);
}

void propagate(ll id){
    combine1(ops[2*id],ops[id],ops[2*id]);
    combine1(ops[2*id+1],ops[id],ops[2*id+1]);
    combine1(ops[2*id],ops[id],val[2*id]);
    combine1(ops[2*id+1],ops[id],val[2*id+1]);
    ops[id]=NO_OPERATION;
}

void do_ops(ll l=0,ll r=k-1,ll id=1){
    if(l>rx or r<lx)return;
    if(l>=lx and r<=rx){
        combine1(ops[id],v,ops[id]);
        combine1(val[id],v,val[id]);
        return;
    }
    propagate(id);
    int mid = (l+r)/2; 
    do_ops(l,mid,id*2);
    do_ops(mid+1,r,id*2+1);
    combine2(val[id*2],val[id*2+1],val[id]);
}

ll calc_val(ll l=0,ll r=k-1,ll id=1){
    if(l>rx or r<lx)return NEUTRAL;
    if(l>=lx and r<=rx){
        return val[id];
    }
    propagate(id);
    int mid = (l+r)/2; 
    ll ans;
    combine2(calc_val(l,mid,id*2),calc_val(mid+1,r,id*2+1),ans); 
    return ans;
}

void solve(){
    in n >> m; 
    k=1; while (k<n)k*=2;
    For(i,0,n)val[i+k]=0;
    rof(i,k-1,0)combine2(val[2*i],val[2*i+1],val[i]);
    while(m--){
        in op;
        if(op==1){
            in lx >> rx >> v;
            rx--;
            do_ops();
        }
        else{
            in lx >> rx;
            rx--;
            out calc_val() e;
        }
    }
}


/////////////////////////////// 

  ///////////////////////                 better way all in one func


const ll INF = 1e18L + 5;

// add to the prefix
// give the min of everything

struct S {
    ll small, lazy;
    void merge(const S& a, const S& b) {
        small = min(a.small, b.small);
        assert(lazy == 0);
    }
    void add(ll x) {
        small += x;
        lazy += x;
    }
};
vector<S> tree;

const int TYPE_ADD = 1, TYPE_MIN = 2;
void rec(int id, int low, int high, int q_low, int q_high, int type, ll& x) {
    if(high < q_low || q_high < low) {
        return;
    }
    if(q_low <= low && high <= q_high) {
        if(type == TYPE_ADD) {
            tree[id].add(x);
        }
        else if(type == TYPE_MIN) {
            x = min(x, tree[id].small);
        }
        else {
            assert(false);
        }
        return;
    }
    for(int b : {2 * id, 2 * id + 1}) {
        tree[b].add(tree[id].lazy);
    }
    tree[id].lazy = 0;
    
    int last_left = (low + high) / 2;
    rec(2 * id, low, last_left, q_low, q_high, type, x);
    rec(2 * id + 1, last_left + 1, high, q_low, q_high, type, x);
    
    tree[id].merge(tree[2*id], tree[2*id+1]);
}
        

int main() {
    int n;    
    int base = 1;
    while(base <= n + 1) {
        base *= 2;
    }
    tree.resize(2 * base, {INF, 0});
    
    ll whatever = 0 - INF;
    rec(1, 0, base - 1, 0, 0, TYPE_ADD, whatever);
    ll best = INF;
    rec(1, 0, base - 1, 0, base - 1, TYPE_MIN, best);
}