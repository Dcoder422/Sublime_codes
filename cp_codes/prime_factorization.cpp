void all_divisors(ll a,vi &factors){
       
        For(i,1,a+1){
         if(i*i>=a){
                if(i*i==a)
             factors.pb(i);
             break;
         }
         if(a%i==0){
             factors.pb(i);
             factors.pb(a/i);
         }
     }
 
 }




 vi all_prime_factors(ll a){
       vi factors;
        For(i,2,a+1){
         if(i*i>a){
             factors.pb(a);
             break;
         }
         while(a%i==0){
             factors.pb(i);
             a/=i;
         }
     }
     
     return factors;
 }




for (long long i=2; i<=b; i++) {
    if (1LL * i * i > b) i = b;
    int cnt = 0;
    while (b % i == 0) {b /= i; cnt++;}
} 