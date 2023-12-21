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

// ex . nCr%M , k<n<10^6
// precalculate f[x]<- factorial
// nCr= n! / ((n-r)!*r!)
// int den = (fact[n-r]*1LL*fact[r])%M;
// ans = fact[n]*binExp(den,M-2,M);
// hence nCr%M - O(log(n))


