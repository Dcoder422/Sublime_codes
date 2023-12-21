// time complexity O((n+m)log(n+m))
// system sort of c++ takes O(nlogn) time
// elements in the array can be same
// sort function puts same elememts one after the other
int doUnion(int a[], int n, int b[], int m)  {
        int arr[n+m],i,res=m+n;

        for(i=0;i<n;i++){
            arr[i]=a[i];
        }

        for(int j=0;j<m;j++){
            arr[i+j]=b[j];
        }

        sort(arr,arr+(m+n));

        for(int k=1;k<(m+n);k++){
            if(arr[k-1]==arr[k]){
                res--;
            }
        }

        return res;
    }