ll n;
ll bit[N];

ll query(ll i){
    ll ans=0;
    for(;i>0;i-=(i&-i))
        ans+=bit[i];
    return ans;
}

void inc(ll i,ll val){
    for(;i<n+1;i+=(i&-i))
        bit[i]+=val;
}

void solve(){
    
    in n;    
    
    


    
    For(i,1,n+1)bit[i]=0;
}

// void update(int idx , int val){
//     while(idx < N){
//         bit[idx] = max(bit[idx] , val);
//         idx += idx & -idx;
//     }
// }

// query() returns max from index 1 to idx

// int query(int idx){
//     int res = 0;
//     while(idx > 0){
//         res = max(res , bit[idx]);
//         idx -= idx & -idx;
//     }
//     return res;
// }


struct Fenwick{
    vector<ll> t;
    Fenwick(int n){t.resize(n+1);}
    void upd(int i, ll v){        
        for(++i; i<t.size(); i+=i&(-i))
            t[i] += v;
    }    
    auto get(int i){
        ll res=0;
        for(++i; i>0; i-=i&(-i))
            res += t[i];
        return res;
    }
    auto get(int l, int r){
        return get(r-1) - (l ? get(l-1) : 0);
    }     
};

Fenwick up(m), down(m);