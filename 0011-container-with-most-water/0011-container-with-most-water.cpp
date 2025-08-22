class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxx=0;
        while(i<j){
            int curr=(j-i)*min(height[i],height[j]);
            maxx=max(maxx,curr);
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return maxx;
    }
};