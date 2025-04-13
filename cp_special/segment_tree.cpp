
vi combine( vi &a, vi &b){
    //...
    vi ans(4);
     
    return ans;
}


//O(logn)
ll query(int node=1, int st=0 , int en=n-1){
    if(st>r || en<l) return 0;
    if(st>=l && en<=r) return tree[node];

    int mid=(st+en)/2;

    return query(2*node,st,mid)+query(2*node+1,mid+1,en);
}

// tree top is at 1
void solve(){
    in n >> m;
    k=1;
    while(k<n)k*=2;
    For(i,0,n) in l,t[i+k]={}; 
    rof(i,k-1,0) t[i]=combine(t[2*i],t[2*i+1]);
    while(m--){
        in op >> l >> r;
        if(op==1){
            t[l+k]={};
            for(int i=(l+k)/2; i>0; i/=2) t[i] = combine(t[2*i], t[2*i+1]);
        }
        else{
            vi res={}; //.. r is excluded acc to code
            // so take r grater as r+1 if in ques querry it is included
            
            for(l=l+k, r=r+k; l<r; l/=2, r/=2) {
                if(l % 2) res = combine(res, t[l++]);
                if(r % 2) res = combine(res, t[--r]);
            }
            out ;

            // for top-down
            
            // r=1;
            // while(r<k){
            //     out r o l e;
            //     if(t[2*r]>=l)r*=2;
            //     else l-=t[2*r],r=2*r+1;
            // }
            // out r-k e;

            // or

            // ll l=0,r=k-1,id=1;val++;
            // while(l<r){
            //     if(t[2*id]<val)l=(l+r)/2+1,val-=t[2*id],id=2*id+1;
            //     else r=(l+r)/2,id*=2;
            // }
        }
    }
}



// better

ll n,m,op,id,v,k;
vector<vi> t(4*N,vi (4,0));
void combine( vi &a, vi &b,vi &ans){
    ans[0]=max({a[0],b[0],a[1]+b[2]});
    ans[1]=max(b[1],b[3]+a[1]);
    ans[2]=max(a[2],a[3]+b[2]);
    ans[3]=a[3]+b[3]; 
}

void solve(){
    in n >> m;
    k=1;
    while(k<n)k*=2;
    For(i,0,n) in v,op=max(0LL,v),t[i+k]={op,op,op,v}; 
    rof(i,k-1,0)combine(t[2*i],t[2*i+1],t[i]);
    out t[1][0] e;
    while(m--){
        in id >> v; 
        op=max(0LL,v),t[id+k]={op,op,op,v};
        for(int i=(id+k)/2; i>0; i/=2)combine(t[2*i], t[2*i+1],t[i]);
        out t[1][0] e;
    }
}



// standard



ll n,m,tree[4*N],a[N],l,r,idx,val,ty;

//O(4*N)
void build( int node=1 , int st=0 , int en=n-1){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);

    tree[node]=tree[2*node]+tree[2*node+1];
}

//O(logn)
ll query(int node=1, int st=0 , int en=n-1){
    if(st>r || en<l) return 0;
    if(st>=l && en<=r) return tree[node];

    int mid=(st+en)/2;

    return query(2*node,st,mid)+query(2*node+1,mid+1,en);
}

//O(logn)
void update(int node=1,int st=0,int en=n-1){
    if(st==en){
        a[st]=val;
        tree[node]=val;
        return;
    }

    int mid = (st+en)/2;
    if(idx<=mid) update(2*node,st,mid);
    else update(2*node+1,mid+1,en);
    tree[node]=tree[2*node]+tree[2*node+1];
}

void solve(){
    in n >> m;
    inv(a,n)
    build();
    while(m--){
        in ty ;
        if(ty==1) in idx >> val,update();
        else in l >> r,r--, out query() e;
    }
}










// tree node
struct Node{
    int lo;
    int hi;
    bool inc = false;
};
 
const int maxN = 200030;
Node t[4*maxN];


