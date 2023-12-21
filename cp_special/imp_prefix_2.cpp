

//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbXdJcTVZT2JiRURoZ0Z6UzFDNE5qNUtIU2dqd3xBQ3Jtc0trb19wcVhyMk1TZE5DeUR1YVd2aFItc3lvSHFFRGFyLXhCZm9iNlphNWNhcnlwZGpIUWd2SFFwSGVHRGVDdXZEZTJrYlN0dlVWRHdnZDhncmFPTndsM0V5dTdQZlJkb3hDNTd6U2xLN0EwUTNZMS11RQ&q=https%3A%2F%2Fwww.hackerrank.com%2Fchallenges%2Fcrush%2Fproblem&v=4wqDE1zNUwc


#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<long long> v(N,0);
int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        int l,r,d;
        cin >> l >> r >> d;
        v[l]=v[l]+d;
        v[r+1]=v[r+1]-d;
    }
    for(int i=1;i<n+1;i++)
        v[i]=v[i]+v[i-1];
    long long max = *max_element(v.begin(), v.end());
    cout << max << endl;
}

//slight variation -- > may be given array
// already contains some elements 
// then also fist evaluate on zero based array
// then add evaluated array value elementwise to 
// the given array
