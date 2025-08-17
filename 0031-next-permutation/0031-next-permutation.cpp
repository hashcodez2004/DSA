class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find the first decreasing index from the right
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }

        // Step 2: If no such index, reverse whole array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the rightmost element greater than nums[idx]
        for (int j = n-1; j > idx; j--) {
            if (nums[j] > nums[idx]) {
                swap(nums[idx], nums[j]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
