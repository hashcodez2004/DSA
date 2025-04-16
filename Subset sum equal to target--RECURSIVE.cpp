#include<bits/stdc++.h>
using namespace std;

class Solution{
	private:

	bool helper(int idx, int target, const vector<int>& nums){
		if(target==0) return true;
		if(idx==0) return (nums[idx]==target);

		bool notTake = helper(idx-1,target,nums);
		bool take = false;
		if(nums[idx]<=target) take = helper(idx-1,target-nums[idx],nums);

		return take||notTake;
	}


	public:

	bool targetSum(const vector<int>& nums, int target){
		return helper(nums.size()-1, target, nums);
	}
};

int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++) cin>>nums[i];
	int target;
	cin>>target;

	Solution ob;
	bool s = ob.targetSum(nums,target);
	cout << (s ? "True" : "False") << endl;

	return 0;
}