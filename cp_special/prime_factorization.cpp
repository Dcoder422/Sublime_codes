 vi all_factors(ll a){
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


 