// GCD convolution

https://codeforces.com/blog/entry/121618
1884D-Counting Rhyme


To do this, we will create dpg
 - the number of pairs in the array with gcd
 equal to g
. For this, we will need an array of counts - cntx
, the number of occurrences of the number x
 in the array. To calculate dpg
, we need to know how many numbers are divisible by g
, specifically the sum s=cntg+cnt2g+…+cntkg
, where kg≤n
. Therefore, the number of pairs with gcd
 equal to g
 is s⋅(s−1)2
. However, not all of them have gcd
 equal to g
, it can be equal to a number that is a multiple of g
. Therefore, dpg=s⋅(s−1)2−dp2g−…−dpkg
. This dynamic programming can be calculated in O(nlogn)
 time.


void solve(){
    ll n,a;
    in n;
    ll ct[n+1],dp[n+1];
    For(i,0,n) in a,ct[a]++;
    rof(i,n,0){
        ll s=0;
        for(int j=i;j<=n;j+=i)s+=ct[j];
        dp[i]=s*(s-1)/2;
        for(int j=i*2;j<=n;j++)dp[i]-=dp[j];   
    }
}

dp[i]- no. of pairs in array with gcd i



