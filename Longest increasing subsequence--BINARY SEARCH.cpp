#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> v;
            v.push_back(nums[0]);
    
            for(int i=1; i<n; i++){
                if(nums[i]>v.back()) v.push_back(nums[i]);
                else{
                    int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                    v[idx] = nums[i];
                }
            }
    
            return v.size();
        }
    };




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        Solution ob;
        int s = ob.lengthOfLIS(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n*logn)
Space Complexity: O(n)
*/