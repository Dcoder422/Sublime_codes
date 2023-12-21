// number theory :

ll poww(ll a,ll b){
    ll ans =1;
    while(b){
        if(b&1)ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}







long long binExpRecur(int a,int b){
	if(b==0)return 1LL;
	long long ans = binExpRecur(a,b/2);
	if(b&1)return ((ans*ans)%M*a)%M;
	return (ans*ans)%M;
}

int binExpIter(int a,int b){
    int ans =1;
    while(b){
        if(b&1)ans=(ans*1LL*a)%M;
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return ans;
} //O(logb)

// case 1:

//if a is v.large , a>10^9 , then calculations can also
//not be performed in long long 
// so if a<10^18 then can use a%M else 
// ex. a=2^1024;
// then do a = binExpo(2,1024,M);

// case 2:

// if 10^9 <M < 10^18
// we do binary multiplication

int binExpIter(int a,int b){
    int ans =1;
    while(b){
        if(b&1)ans=binMultiply(ans,a);
        a=binMultiply(a,a);
        b>>=1;
    }
    return ans;
} //O(log^2(N))
long long binMultiply(long long a,long long b,long long m){
    long long ans =0;
    while(b){
        if(b&1)ans=(ans+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return ans;
}

// case 3:
// for b<10^18 just change type of argument to long long
// int binExpIter(int a,long long b){
// b>10^18 ex. b=64^32...using ETF(euler totient function)
// for ex calculate (50^(64^32))%M 
// do binEXp(50,binExp(64,32,M-1),M)(if M is prime)
// https://www.youtube.com/watch?v=GApcdkIe9WM&list=PLauivoElc3giVROwL-6g9hO-LlSen_NaV&index=13

// in cp copy


// x^(a*b)=(x^a)^b
// x^(a*b)%m = (x^a)*(x^a)....(x^a)%m= (x^a % m)^b %m
