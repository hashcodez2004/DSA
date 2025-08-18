class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=intervals[0][0];
        int j=intervals[0][1];
        vector<vector<int>> ans;
        for(int t=1;t<n;t++){
            int curri=intervals[t][0];
            int currj=intervals[t][1];
            if(curri<=j) j=max(j,currj);
            else{
                ans.push_back({i,j});
                i=curri;
                j=currj;
            }
        }
        ans.push_back({i,j});
        return ans;
    }
};