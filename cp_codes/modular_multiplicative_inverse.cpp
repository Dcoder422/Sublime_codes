 // (a/b)%M=(a*bi)%M=(a%M*bi%M)%M
// bi-> modular multiplicative inverse of b

// Modular Multiplicative Inverse of A=binExp(A,M-2,M)
// M-> prime number

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

ll minv(ll a){
    return binExp(a,M-2);
}

// ex . nCr%M , k<n<10^6
// precalculate f[x]<- factorial
// nCr= n! / ((n-r)!*r!)
// int den = (fact[n-r]*1LL*fact[r])%M;
// ans = fact[n]*binExp(den,M-2,M);
// hence nCr%M - O(log(n))



const ll N=2e5+4;
const ll MOD = 1e9+7;
ll fac[N],inv_fac[N];
ll mul(ll a, ll b){
    return (a*b)%MOD;
}
ll my_pow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=mul(ans,a);
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}
ll my_inv(ll a){
    return my_pow(a,MOD-2);
}
ll binomial(ll a,ll b){
    if(a<0 || b<0 || b>a)return 0;
    return mul(fac[a],mul(inv_fac[b],inv_fac[a-b]));
}
void cal_fac(){
    fac[0]=inv_fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=mul(i,fac[i-1]);
        inv_fac[i]=my_inv(fac[i]);
    }
}