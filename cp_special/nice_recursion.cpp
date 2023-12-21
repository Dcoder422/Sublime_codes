#include<bits/stdc++.h>
using namespace std;
 vector<int> ans;
int arr[26][10002];
void sll(int l,int r,int k,string s){
	if(l>r)return;
	int c=0;
	// cout << l << " " << r << endl;
	for(int i=0;i<26;i++){
		if(((arr[i][r]-arr[i][l-1])<k) && ((arr[i][r]-arr[i][l-1])!=0)){
			// cout << (char)(i+97) << endl;
			auto it = find((s.begin()+l-1),s.end(),(char)(97+i));
			int m = it - s.begin();
			// cout << m << endl;
			sll(l,m,k,s);
			sll(m+2,r,k,s);break;
	}
	else c++;
		}
		if(c==26)
			ans.push_back(r-l+1);
}
int longestSubstring(string s, int k) {
        for(int i=0;i<s.size();i++){
        	for(int j=0;j<26;j++){
        		if((char)(j+97)==s[i])
        			arr[j][i+1]=arr[j][i]+1;
        		else arr[j][i+1]=arr[j][i];
        		// cout << arr[j][i+1] << " ";
        	}
        		// cout << endl;
        }
    ans.push_back(0);
        sll(1,s.size(),k,s);
        int fi = *max_element(ans.begin(),ans.end());
        return fi;
    }
int main(){
    string s="ababbc";
    int h = longestSubstring(s,2);

    cout << h << endl; 
    // for(auto i : ans)cout << i << endl;  
 }
