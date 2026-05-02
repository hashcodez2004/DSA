class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum = 0;
        int len=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                int currLen=j-i+1;
                len=min(len,currLen);
                sum-=nums[i++];
            }
            j++;
        }
        if(len==INT_MAX) return 0;
        return len;
    }
};