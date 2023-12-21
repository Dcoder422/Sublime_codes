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

