class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n=nums.size();
        int cnt=0;
        long long prod=1;
        int i=0;
        for(int j=0;j<n;j++){
            prod=prod*nums[j];
            //shrink
            while(prod >= k) prod /= nums[i++];
            cnt += (j - i + 1);
        }
        return cnt;
    }
};