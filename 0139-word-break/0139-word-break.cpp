class Solution {
    bool helper(int idx, string& s, unordered_set<string>& dict, vector<int>& dp) {
        if(idx == s.size()) return true;
        if(dp[idx] != -1) return dp[idx];

        string temp = "";
        for(int i = idx; i < s.size(); i++) {
            temp += s[i];
            if(dict.count(temp) && helper(i+1, s, dict, dp)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1); // -1=unvisited
        return helper(0, s, dict, dp);
    }
};