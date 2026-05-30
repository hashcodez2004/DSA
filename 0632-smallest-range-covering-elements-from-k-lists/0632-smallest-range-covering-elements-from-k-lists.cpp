class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq;  // {val, {row,col}}

        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            pq.push({nums[i][0], {i,0}});
            maxi = max(maxi, nums[i][0]);
        }

        int r1 = pq.top().first;
        int r2 = maxi;

        while(true){
            auto it = pq.top();
            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            int mini = val;

            if(maxi - mini < r2 - r1){
                r1 = mini;
                r2 = maxi;
            }

            if(col + 1 == nums[row].size()) break;

            pq.push({nums[row][col+1], {row,col+1}});
            maxi = max(maxi, nums[row][col+1]);
        }

        return {r1, r2};
    }
};