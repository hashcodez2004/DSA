class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n);
        int i=0;
        int j=1;
        for(int k=0;k<n;k++){
            if(nums[k]>0){
                a[i]=nums[k];
                i+=2;
            }
            else{
                a[j]=nums[k];
                j+=2;
            }
        }
        return a;
    }
};