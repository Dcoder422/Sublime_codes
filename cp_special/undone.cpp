//1.// https://codeforces.com/contest/1426/problem/D


#include<bits/stdc++.h>
using namespace std;
// void printV(vector<int> v){
// 	for(auto i : v)
// cout << i << endl;
// cout << endl;
// }

int main(){
	int n,a;
	cin >> n;
	vector<int> v(n+1,0);
	v[0]=0;
	for(int i=1;i<n+1;i++){
		cin >> a;
		v[i]=a+v[i-1];
	}	
	for(auto i : v)
	cout << i << endl;	
	auto it = find(v.begin(), v.end(),0);
	int count =0;
	// cout << (it != v.end()) << endl ;
	v.erase(it);
	// cout << endl;
	it = find(v.begin(), v.end(),0);
	while(it != v.end()){
		count ++;
		v.erase(it);
		it = find(v.begin(), v.end(),0);
	}
	// printV(v);
	auto x = v.begin();
	for(int i=0;i<v.size();i++){
		// cout << i << " " << endl << "size :" << v.size() << endl  ;
		auto it = find(++x, v.end(),v[i]);
		if(it!=v.end()){
			count ++;
		    v.erase(it);
		}
		// printV(v);
	}
	cout << endl;
	cout << count ;


}

//2.

//https://www.spoj.com/problems/OPMODULO/

#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned int l,r,t_l,t_r,n,n1;
	cin >> l >> r;
	if(l>2 && r>1){
		n = (l-1)/4;
		n1 = r/4;
		cout << 2*(n1-n)*(n1-n) + 2*(n1-n) ;
	}

	if(r==1)
		cout << 1;
	else{	
			n = r/4;
			if(l==1)
			cout << 2*n*(n+1) + 3;
			if(l==2)
				cout << 2*n*(n+1)+ 2;
			}
		


}




// https://www.hackerrank.com/challenges/recursive-digit-sum/problem

//selection sort







// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<int> v(n);
//         for(int i=0;i<n;i++){
//         	cin >> v[i];
//         }
//         // for(auto i : v)cout << i << " ";cout << endl;
//         sort(v.begin(),v.end());
//         // for(auto i : v)cout << i << " ";cout << endl;
//         if((count(v.begin(), v.end(), v[0])>1 )||( count(v.begin(), v.end(), v[n-1])>1))
//         	cout << 2*(v[n-1]-v[0]) << endl;
//         else cout << max((v[n-1]-v[0]+v[n-1]-v[1]),(v[n-1]-v[0]+v[n-2]-v[0])) << endl;
 //    }   
 // }















//http://codeforces.com/problemset/problem/834/B 

// #import<bits/stdc++.h>
// using namespace std;
// int i,j,k,m,n,p,t=1,a[27],b[27];
// string s;
// main(){
// 	for(cin>>n>>k>>s;j<n;j++)
// 		{
// 			if(!a[s[j]-64])
// 				a[s[j]-64]=j+1;
// 			b[s[j]-64]=j+1;
// 		}
// 		for(;i<n;i++)
// 			{
// 				for(j=0;j++<26;p-=b[j]==i)
// 					m=max(m,p+=a[j]==i);
// 			}
// 			cout<<(m>k?"YES":"NO");
// 		}


// ladder 2B perfect number
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,k;cin >> n;
//     int m=19,b=2;
//     vector<int> v={1,10,21,31,32,41,42,43,51,52,53,54,61,62,63,64,65,71,72,73,74,75,76,81,82,83,84,85,86,87,91,92,93,94,95,96,97,98};
//     if(n==1)cout << m << endl;
//     else{
//     for(int i=2;i<=n;){
//     	 k= m + (b-1)*9 ;
//     	int o=b%100;b++;
//     	auto it =find(v.begin(),v.end(),o);
//     	if(it==v.end()){i++;cout << k << endl;}    	
//     }cout << k << endl;}
// }



//https://codeforces.com/contest/1462/problem/D

#include<bits/stdc++.h>
using namespace std;
set<vector<int>> ans;
vector<int> a={3,6,1,2,6,2};
void sol(vector<int> &a,int & i){
	if(count(a.begin(),a.end(),a[0])==a.size()){
		ans.insert(a);
		return ;
	}
	for(auto i : a)cout << i << " ";cout << endl;
	auto it = min_element(a.begin(),a.end());
	int m=*it;
	if(it!=a.begin()){
		*(it-1)=*(it-1)+*it;
		a.erase(it);
		for(auto i : a)cout << i << " ";cout << endl;
		sol(a,i);
		cout<< *(--it)  ;
		a.push_back(m);
		for(auto i : a)cout << i << " ";cout << endl;
	}
	if(it!=(--a.end())){
		*(it+1)=*(it+1)+*it;
		a.erase(it);
		for(auto i : a)cout << i << " ";cout << endl;
		sol(a,i);
		a.push_back(m);
		for(auto i : a)cout << i << " ";cout << endl;
	}
}
      	
int main(){
	// vector<int> my={1,1,1};
	int r=0;
	sol(a,r);
	for(auto i : ans){
		for(auto j: i)cout << j << " ";
			cout << endl;
	}
}

//https://codeforces.com/problemset/problem/1462/D
// ****although it is done without recursion but in luv course it was under recursion  
//** so doing it with recursion is undone


//https://www.spoj.com/problems/PIE/
// worong answer

#include<bits/stdc++.h>
using namespace std;
const long double eps = 1e-6;
const long double pi =  3.14159265358979323846264338327950;
const int N=1e4+2;
 vector<int> v(N);
bool pie(long double mid ,int n, int f){
	for(int i=0;i<n;i++){
        f-=floor(1.0*v[i]*v[i]/(mid*mid));
		if(f<=0)break;
	}
	return f<=0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
         int n,f; cin>> n >> f;
         for(int i=0;i<n;i++){
         	cin >> v[i];
         }
         // long double hi = *max_element(v.begin(),v.end());
         // cout << v[0];
         long double lo=1,hi=1e4,mid;
         while(hi-lo>eps){
         	mid =(lo+hi)/2;
         	if(pie(mid,n,f+1))lo=mid;
         	else hi = mid;
         }
         cout << fixed << setprecision(4) << (pie(hi,n,f+1)?pi*hi*hi:pi*lo*lo) << endl;
    }   
 }


 // luv contest 3 ques Too lazy to name..

// https://www.hackerearth.com/problem/algorithm/too-lazy-to-name-the-question-ii/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    // set<int> x,y;
    vector<int> xx(n),yy(n),xc;
    for(int i=0;i<n;i++){
             cin >> xx[i] >> yy[i];   
         } 
         xc=xx;
         xc.erase(unique(xc.begin(),xc.end()),xc.end());
         for(int i=0;i<xc.size();i++){
             for(int j=i+1;j<xc.size() ;j++){
                 
             }
         }

   }
//a + x <=m-1

//1st codechef contest
//https://www.codechef.com/problems/XORPROD
#include<bits/stdc++.h>
using namespace std;
const int N=998244353;

int main(){
    int t;
    cin >> t;
    while(t--){
         int n;cin >> n;
         vector<long long> v;
         long long x,c1=0;
        
 }
 for(int i=0;i<n ;i++){
             cin >> x;
             if(x==1)c1++;
             else v.push_back(x);
         }
         sort(v.begin(),v.end());
         for(int i=0;i<v.size()-1;i++){
             if((v[i]+1)==v[i+1])
                my.push_back(v[i]);
         }
         long long p=1;
         for(int i=0;i< v.size();i++){
            if((v[v.size()-1-i]%2==1))
                p=(p*v[v.size()-1-i])%N;
            else if(c1>0 ){
                p=(p*(v[v.size()-1-i]+1))%N;c1--;
             }
             else if(c1==0 && my.size()>0 && ){

             }
             else p=(p*v[v.size()-1-i])%N;
         }
         cout << p << endl;
    }  


    ep 72
    

    #include<bits/stdc++.h>
using namespace std;


void dfs(int r,int c,int pr,int pc,int &pch,int &ach,vector<vector<int>>& grid){
        if(pch==1 && ach==1)return;
    int rn=grid.size();
    int cn = grid[0].size();
    if(r<0 || c<0 || r>rn-1 || c>cn-1)return ;
    if(grid[r][c]>grid[pr][pc])return;
     cout << pr << " " << pc << " " << grid[pr][pc]<< endl;
    cout << r << " " << c << " " << grid[r][c]<<  endl << endl;
    if(r==0 || c==0){pch=1;}
    if((r==(rn-1)) || (c==(cn-1))){ach=1;}
    if(ach!=1){
    dfs(r+1,c,r,c,pch,ach,grid);
    dfs(r,c+1,r,c,pch,ach,grid);
    dfs(r-1,c,r,c,pch,ach,grid);
    dfs(r,c-1,r,c,pch,ach,grid);
    }
    if(pch!=1){
    dfs(r-1,c,r,c,pch,ach,grid);
    dfs(r,c-1,r,c,pch,ach,grid);
    dfs(r+1,c,r,c,pch,ach,grid);
    dfs(r,c+1,r,c,pch,ach,grid);
    }
  
}
 vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> &grid =heights;
    vector<vector<int>> ans;
        int rn=grid.size();
    int cn = grid[0].size();
    for(int i=0;i<rn;i++){
        for(int j=0;j<cn;j++){
            vector<int> k;
            int pch=0,ach=0;
            dfs(i,j,i,j,pch,ach,grid);
            if(pch==1 && ach==1){
                k.push_back(i);
                k.push_back(j);
                ans.push_back(k);
        }
            }
    }
    // int pch=0,ach=0,i=1,j=3; vector<int> k;
    //         dfs(i,j,i,j,pch,ach,grid);
    //         if(pch==1 && ach==1){
    //             k.push_back(i);
    //             k.push_back(j);
    //             ans.push_back(k);}

    return ans;
    }


    int main(){
     vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
     // {{1,2,3},{8,9,4},{7,6,5}};
     // {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
       for(auto i: heights){
        for (auto j:i) cout << j << " ";
            cout << endl;
    } 