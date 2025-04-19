#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int helper(int idx, int target, const vector<int>& nums){
        if(idx==0){
            if(target%nums[0]==0) return target/nums[0];
            else return INT_MAX;
        }

        int notTake = 0 + helper(idx-1,target,nums);
        int take = INT_MAX;
        if(target>=nums[idx]) take = 1 + helper(idx,target-nums[idx],nums);

        return min(take,notTake);
    }

public:

    int minCoins(vector<int>& nums, int k) {
        int ans = helper(nums.size()-1,k,nums);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        Solution ob;
        int s = ob.minCoins(nums, k);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: >> O(2^n) (exponential)
Space Complexity: >> O(n)
*/