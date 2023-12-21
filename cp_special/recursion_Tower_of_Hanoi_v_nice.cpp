void my(int n, int A, int C, int B){
        if(n==0)return;
        my(n-1,A,B,C);
        cout << "move disk " << n <<" from rod "<<A<<" to rod "<<C << endl;
        my(n-1,B,C,A);
        
    }

    // O(2^n-1)
    // calculation n explanation pic in phone