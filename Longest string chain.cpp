#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool compare(string& s1, string& s2){
        if(s1.size() != s2.size()+1) return false;

        int first=0, second=0;
        while(first<s1.size()){
            if(second!=s2.size() && s1[first]==s2[second]){
                first++;
                second++;
            }
            else first++;
        }
        return (first==s1.size() && second==s2.size());
    }

public:
    static bool comp(string s1, string s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),comp);
        vector<int> dp(n,1);
        int maxii = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(nums[i],nums[j])) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxii = max(maxii, dp[i]);
        }
        return maxii;
    }
};
    
    
    
    
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        Solution ob;
        int s = ob.longestStrChain(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n*n*m) + O(n*logn) m-->longest string length(WC)
Space Complexity: O(n)
*/