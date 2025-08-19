class Solution {
public:
    //     Optimal Approach
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long prefix = 1;
        long long suffix = 1;
        long long maxii = INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;

            prefix*=nums[i];
            suffix*=nums[n-1-i];

            maxii = max({maxii,prefix,suffix});
        }
        return maxii;
    }
};