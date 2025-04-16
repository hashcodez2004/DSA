#include<bits/stdc++.h>
using namespace std;

class Solution{
	private:

	bool helper(int idx, int target, const vector<int>& nums, vector<vector<int>>& dp){
		if(target==0) return dp[idx][target] = 1;
		if(idx==0) return dp[idx][target] = (nums[idx]==target);

		if(dp[idx][target]!=-1) return dp[idx][target];

		bool notTake = helper(idx-1,target,nums,dp);
		bool take = false;
		if(nums[idx]<=target) take = helper(idx-1,target-nums[idx],nums,dp);

		return dp[idx][target] = take||notTake;
	}


	public:

	bool targetSum(const vector<int>& nums, int target){
		vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
		return helper(nums.size()-1, target, nums, dp);
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> nums(n);
		for(int i=0;i<n;i++) cin>>nums[i];
		int target;
		cin>>target;

		Solution ob;
		bool s = ob.targetSum(nums,target);
		cout << (s ? "True" : "False") << endl;
	}
	return 0;
}



/*
                Time Complexity- O(n x target)
                Space Complexity- O(n x target) + O(n)
*/