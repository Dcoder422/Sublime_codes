//https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE


#include<bits/stdc++.h>
using namespace std;
int main(){
	
    int t;
    cin >> t;
    map<int,multiset<string>> m;
    string s;
    int ma;
    while(t--){
    	cin >> s >> ma;
    	m[-ma].insert(s);
}
	for( auto i : m){
		for( auto j : (i.second))
			cout << j << " " << -i.first << endl ;

	}
 }

 //or 

//  #include<bits/stdc++.h>
// using namespace std;
// bool cmp(pair<string,int> a,pair<string,int> b){
//     if(a.second !=b.second)
//     return a.second > b.second;
//     else
//     return a.first < b.first;

// }
// int main(){
    
//     int t;
//     cin >> t;
//     vector<pair<string,int>> m;
//     string s;
//     int ma;

//     while(t--){
//         cin >> s >> ma;
//         auto p = make_pair(s,ma);
//         m.push_back(p);
// }
//     sort(m.begin(),m.end(),cmp);
//     for( auto i : m){
//             cout << i.first << " " << i.second << endl ;

//     }
//  }