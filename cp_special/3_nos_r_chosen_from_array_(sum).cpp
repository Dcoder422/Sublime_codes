//Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
   {
    sort(arr,arr+n);

    for (int i=0; i<n-2; i++)
    {
        int l=i+1,r=n-1;
        while(l!=r){
        long long sum=arr[i]+arr[l]+arr[r];
        if(sum==0)return true;
        if(sum>0)r--;
        else l++;}
    }

   return false;
}