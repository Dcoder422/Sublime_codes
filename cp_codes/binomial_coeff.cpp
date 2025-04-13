int my_inv(int a) {
    return my_pow(a, mod - 2);
}


int my_pow(int a, int b) {
    int r = 1;
    while(b) {
        if(b % 2) {
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int mul(int a, int b) {
    return (ll) a * b % mod;
}

// O(nlogn)

fac[0] = inv_fac[0] = 1;
    for(int i = 1; i < nax; ++i) {
        fac[i] = mul(fac[i-1], i);
        inv_fac[i] = my_inv(fac[i]);
    }




    // OR //

// O(n)


ll iv[N],f1[N],f2[N];

iv[1]=1;
for(int i=2;i<N;i++){
    iv[i]=M-M/i*iv[M%i]%M;   
}
f1[0]=f2[0]=1;

for(int i=1;i<N;i++){
    f1[i]=f1[i-1]*i%M;
    f2[i]=f2[i-1]*iv[i]%M;
}

