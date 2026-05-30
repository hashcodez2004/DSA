class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int k = mat.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
                            greater<pair<int,pair<int,int>>>> pq; // {val, {row,col}}
        
        for(int i=0;i<k;i++) pq.push({mat[i][0],{i,0}});
        
        vector<int> ans;
        while(!pq.empty()){
            int val=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            ans.push_back(val);
            
            if(col+1 != mat[row].size()) pq.push({mat[row][col+1],{row,col+1}});
        }
        
        return ans;
    }
};

/*
TC: O(N log K)
SC: O(K)

N = total number of elements across all arrays
K = number of arrays
*/