// https://atcoder.jp/contests/dp/tasks/dp_z
// https://www.youtube.com/watch?v=HnZKQJtGeHs

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Line{
    ll m,c; 
    Line(ll a,ll b){
        m=a;c=b;
    }
    ll value(ll x){
        return m*x+c;
    }
    pair<ll,ll> intersect(Line &b){
        // returning numerator and denominator
        return {b.c-c,m-b.m};
    }
};

ll sqr(ll a){
    return a*a;
}

int main(){
    ll n,cost;
    cin >>n >> cost;
    vector<Line> v;
    ll st=0,best;
    for(int i=0;i<n;i++){
        ll h; cin >> h;
        if(!i){
            v.emplace_back(-2*h,sqr(h)); 
            continue;
        }
        while(v.size()-st>1 and v[st].value(h)>v[st+1].value(h))st++; 
        best=v[st].value(h)+sqr(h)+cost;
        Line l(-2*h,best+sqr(h));
        while(v.size()>1){
            auto x = v.end()[-1];
            auto y = v.end()[-2];
            auto px = x.intersect(l);
            auto py = y.intersect(l);
            if(py.first*px.second>px.first*py.second)v.pop_back();
            else break;
        }
        v.emplace_back(l);
    }
    cout << best;
}