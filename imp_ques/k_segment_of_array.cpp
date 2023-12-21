// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B


#include <bits/stdc++.h>
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define pob pop_back()
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define countB(x) __builtin_popcount(x)
#define countBl(x) __builtin_popcountll(x)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define prio priority_queue
#define inf 1e9
#define M 1000000007
#define N 200100
#define out cout << 
#define in cin >>
#define vill vector<long long>
#define partition_point pp
#define eps 1e-7
ll arr[N];
int n,k;
bool pred(ll p){
    ll ct=0,sum=0;
    For(i,0,n){
        sum+=arr[i];
        if(sum>p){
            ct++;
            sum=arr[i];
            if(arr[i]>p)return false;
        }
    }
    return ct<k;
}
void solve(){
    in n >> k;
    For(i,0,n)in arr[i];
    ll lo= -1,hi= 1,mid;
    while(!pred(hi)){
        lo=hi;
        hi*=2;
    }
    while(hi-lo>1){
        mid=(hi+lo)/2;
        if(pred(mid)) hi = mid;
            else lo = mid+1;
    }
    if(pred(lo))out lo;
    else out hi;
}

int main(){
    solve();
}
