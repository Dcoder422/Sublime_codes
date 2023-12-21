#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>> final;
     void sub(vector<int>& nums,vector<int>& my,int i){
     	if(i==nums.size()){
     		final.push_back(my);
     		return;
}
     	my.push_back(nums[i]);
     	sub(nums,my,i+1);
     	my.pop_back();
     	sub(nums,my,i+1);
     	}
     	void printv(vector<int> v){
     		for(int a : v)
     			cout << a << " ";
     		cout << endl;
     	}
int main(){
	vector<int> my;
	vector<int> u={1,2,3};
	sub(u,my,0);
	for(vector<int> vy : final){
		printv(vy);
	}
	cout<<"end";
}