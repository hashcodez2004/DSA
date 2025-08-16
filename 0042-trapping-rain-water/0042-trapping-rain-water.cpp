class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lmax=0,rmax=0,cap=0,l=0,r=n-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]<lmax)
                cap+=lmax-height[l];
                lmax=max(lmax,height[l]);
                l++;
            }
            else{
                if(height[r]<rmax)
                cap+=rmax-height[r];
                rmax=max(rmax,height[r]);
                r--;
            }
        }
        return cap;
    }
};


//TC: O(N)
//SC: O(1)