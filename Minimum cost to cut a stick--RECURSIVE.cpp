#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, vector<int>& cuts){
        if(i>j) return 0;

        int mini = 1e9;
        for(int ind=i; ind<=j; ind++){
            int cost = (cuts[j+1]-cuts[i-1]) + helper(i,ind-1,cuts) + helper(ind+1,j,cuts);
            mini = min(mini,cost);
        }
        return mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return helper(1,cuts.size()-2,cuts);
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
        int s = ob.minCost(n,nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: exponential
Space Complexity: O(c)
*/