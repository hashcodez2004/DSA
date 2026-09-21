class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i=0;i<n;i++) target+=nums[i];

        if(target%2 == 1) return false;

        vector<int> prev(target/2 + 1, 0);
        prev[0] = 1;
        if(nums[0] <= target/2) prev[nums[0]] = 1;

        for(int idx=1; idx<n; idx++){

            vector<int> curr(target/2 + 1, 0);
            for(int tar=0; tar<=target/2; tar++){

                bool take = false;
                if(nums[idx]<=tar) take = prev[tar-nums[idx]];

                bool notTake = prev[tar];

                curr[tar] = take || notTake;
            }

            prev = curr;
        }

        return prev[target/2];
    }
};