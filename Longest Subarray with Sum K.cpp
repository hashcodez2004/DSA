class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int len = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mpp.find(sum)==mpp.end()) mpp[sum]=i;
            if(mpp.find(sum-k)!=mpp.end()) len = max(len,i-mpp[sum-k]);
        }
        return len;
    }
};


/*
TC: O(N)
SC: O(N)
*/