void calcncr()
{
  for(int i = 0; i <= 1000; i++)
  {
    ncr[i][0] = 1;
  }
  for(int i = 1; i <= 1000; i++)
  {
    for(int j = 1; j <= 1000; j++)
    {
      ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%MOD;
    }
  }
}



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