class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxii = INT_MIN;
        int sum = 0;

        int start = 0, end = 0, s = 0;  // track indices

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum > maxii) {
                maxii = sum;
                start = s;
                end = i;
            }

            if (sum < 0) {
                sum = 0;
                s = i + 1; // next element might be a new start
            }
        }

        vector<int> ans;
        for (int i = start; i <= end; i++) ans.push_back(nums[i]);

        return ans;
    }
};
