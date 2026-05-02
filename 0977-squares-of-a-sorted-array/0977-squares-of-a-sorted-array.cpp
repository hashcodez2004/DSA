class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0, right = n - 1;
        int idx = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[idx--] = nums[left] * nums[left];
                left++;
            } else {
                result[idx--] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};