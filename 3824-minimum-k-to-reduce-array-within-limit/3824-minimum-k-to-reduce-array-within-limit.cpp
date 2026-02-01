class Solution {
private:
    long long operations(vector<int>& nums, int  k){
        int n=nums.size();
        long long steps=0;
        for(int i=0;i<n;i++){
            steps += (nums[i]+k-1) / k;
        }
        return steps;
    }

    int maxEle(vector<int>& nums){
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    
public:
    int minimumK(vector<int>& nums) {
        int n=nums.size();
        int low=1, high=max(maxEle(nums),n);
        int res;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long ops=operations(nums,mid);
            long long square=(long long)mid*mid;
            if(ops<=square){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};