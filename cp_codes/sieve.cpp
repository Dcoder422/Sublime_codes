Sieve : works well till N=1e+7;
O(N*log(log(N)))

const int N=1e7+10;
vector<bool> pf(N,1);//initialy considering all as prime factor
vector<int> lp(N),hp(N);//can also be done in previous vector , instead if bool save lp - lowest prime hp- highest prime



pf[0]=pf[1]=false;
for(int i=2;i<N;i++){ //i*i<=N for more optimized code
    if(pf[i]==true){
        lp[i]=hp[i]=i;
        for(int j=i*2;j<N;j+=i){pf[j]=false; // j=i*i for optimization
                hp[j]=i;
                if(lp[j]==0)lp[j]=i;}
    }
}

// Prime factorization :
vector<int> v;//all factors
unordered_map<int,int> count;//count of pf
while(num>1){
    int p=hp[num];
    while(num%p==0){
        num/=p;
        v.push_back(p);
        count[p]++;
    }
}  
 // OR //

for(int i=lp[num];i*i<=num;i++){
        while(num%i==0){
            v.push_back(i);
            num/=i;
        }
    }
    if(i>1)v.push_back(i);

  // O(log N)

for ALL divisors:**works for N=1e5+10***

*************** v imp for divisors
https://codeforces.com/blog/entry/14463?#comment-194529 

for contests no. of divisors : ~ N^(1/3)=> cube root of N
    The number is 1344 for integers up to 10^9 and 103680 for integers up to 10^18

   
