class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        int m=arr.size();
        int n=arr[0].size();
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;

        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(arr[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){
                ans.push_back(arr[i][right]);
            }
            right--;

            if(top<=bottom) //to check that top is under bottom and we have a row to print and also right<=left is checked inside for loop but top and bottom not checked...therefore check them explicitely
            for(int i=right;i>=left;i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;

            
            if(left<=right) //top<=bottom is checked inside for loop but left and right not checked...therefore check them explicitely
            for(int i=bottom;i>=top;i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
        return ans;
    }
};