#include<bits/stdc++.h>
using namespace std;

class Solution{
	private:

	int targetSum(const vector<int>& nums, int target){
		int n=nums.size();
		vector<vector<int>> dp(n,vector<int>(target+1,0));
		for(int i=0;i<n;i++) dp[i][0]=1;
		if(nums[0] <= target) dp[0][nums[0]] = 1;
		for(int i=1;i<n;i++){
			for(int j=1;j<target+1;j++){
				int notTake = dp[i-1][j];
				int take = false;
				if(nums[i]<=j) take = dp[i-1][j-nums[i]];
				dp[i][j] = take||notTake;
			}
		}
		
		for(int i=target;i>=0;i--) if(dp[n-1][i]) return i;
	}

	public:

	int minSubsetSumDifference(vector<int>& nums)
	{
		// Write your code here.
		int sum = accumulate(nums.begin(),nums.end(), 0);
        int sum1=sum/2;
        int ans = targetSum(nums,sum1);
        return abs(sum-2*ans);
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

		Solution ob;
		int s = ob.minSubsetSumDifference(nums);
		cout << s << endl;
	}
	return 0;
}


/*
                 Time Complexity- O(n x target)
                 Space Complexity- O(n x target)
 */