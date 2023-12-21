 vector<vector<int>> final;
    
     void sub(vector<int>& nums,vector<int>& my,int i){
     	if(i==nums.size()){
     		final.push_back(my);
     		return;
      }
      // cout<<i<<endl;
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
       vector<vector<int>> subsets(vector<int>& nums) {
         vector<int> my;
        sub(nums,my,0);
           return final;
    }