class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
        int n=nums.size();

        if(n==0) return {};
        if(n==1) return {1};

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i<n;i++) pq.push({nums[i],i});

        vector<int> ans(n);
        int rank=0;
        int latestEle=INT_MIN;

        while(!pq.empty()){
            int currEle=pq.top().first;
            int idx=pq.top().second;
            pq.pop();

            if(currEle==latestEle){
                ans[idx]=rank;
                continue;
            }

            latestEle=currEle;
            rank++;
            ans[idx]=rank;
        }

        return ans;
    }
};

/*

TC: O(nlogn) + O(nlogn) ~ O(nlogn)
SC: O(n) => heap construction

*/