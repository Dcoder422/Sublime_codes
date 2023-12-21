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