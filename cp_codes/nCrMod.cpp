
// O(logn)
ll fact[N];


ll binExp(ll a,ll b){
    ll ans =1;
    while(b){
        if(b&1)ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}

ll nCrMod(ll n,ll r){
	if(r==0)
		return 1;
	return (fact[n]*binExp((fact[n-r]*fact[r])%M,M-2))%M;
}

fact[0]=1;
For(i,1,N)fact[i]=(i*fact[i-1])%M;