class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int m=series1.size();
        int n=series2.size();
        unordered_map<int,int> mpp;

        int start1=series1[0][0] ,end1=series1[m-1][0] ,start2=series2[0][0] ,end2=series2[n-1][0];

        for(auto &it: series1){
            int num1=it[1];
            int num2=-1;

            if(it[0]<=start2) num2=series2[0][1];
            if(it[0]>end2) num2=0;

            if(num2<0){
                //Using binary search to find ceil of it[0] in series2
                int low=0;
                int high=n-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(series2[mid][0]<it[0]) low=mid+1;
                    else{
                        num2=series2[mid][1];
                        high=mid-1;
                    }
                }
            }

            mpp[it[0]]=num1+num2;
        }

        for(auto &it: series2){
            if(mpp.find(it[0])!=mpp.end()) continue;
            
            int num1=it[1];
            int num2=-1;

            if(it[0]<=start1) num2=series1[0][1];
            if(it[0]>end1) num2=0;

            if(num2<0){
                //Using binary search to find ceil of it[0] in series1
                int low=0;
                int high=m-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(series1[mid][0]<it[0]) low=mid+1;
                    else{
                        num2=series1[mid][1];
                        high=mid-1;
                    }
                }
            }

            mpp[it[0]]=num1+num2;
        }
            
        vector<vector<int>> ans;
        for(auto &it: mpp){
            ans.push_back({it.first,it.second});
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};