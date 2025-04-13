ll sq(ll a){
    return a*a;
}

struct P{
    ll x,y;

    void read(){
        cin >> x >> y;
    }

    P operator - (const P & b) const{
        return P{x-b.x,y-b.y};
    }

    void operator -=(const P &b){
        x-=b.x;
        y-=b.y;
    }

    ll operator *(const P&b) const{  // it gives 2*area made by the triangle having the vectors as its two sides
        return x*b.y-b.x*y;
    }

    bool operator <(const P &b) const{   // for set,map etc
       // return y < b.y; // this will give wrong answer
        // because set doesnt have same values so it
        // will not insert points with same y
        // so better consider entire co-ordinate
        return make_pair(y,x)<make_pair(b.y,b.x);
    }

    ll dist2(const P &a) const{
        return sq(a.x-x)+sq(a.y-y);
    }

};