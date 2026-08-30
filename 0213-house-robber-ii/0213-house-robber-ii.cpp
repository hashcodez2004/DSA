class Solution {
private:
    int houseRobber(int start, int end, vector<int>& nums) {
        int prev = nums[start];
        int prev2 = 0;

        for(int idx = start + 1; idx <= end; idx++) {

            // Take
            int take = nums[idx];
            if(idx > start + 1)
                take += prev2;

            // Not Take
            int notTake = prev;

            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        // Exclude last house
        int first = houseRobber(0, n - 2, nums);

        // Exclude first house
        int second = houseRobber(1, n - 1, nums);

        return max(first, second);
    }
};