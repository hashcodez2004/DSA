class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        // finding right end => traversing left to right
        int end=-1;
        int maxii=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<maxii) end=i;
            else maxii=nums[i];
        }

        // finding left end => traversing right to left
        int start=-1;
        int minii=nums[n-1];
        for(int i=n-1;i>=0;i--){
            if(nums[i]>minii) start=i;
            else minii=nums[i];
        }

        if(start==-1 && end==-1) return 0;
        return end-start+1;
    }
};