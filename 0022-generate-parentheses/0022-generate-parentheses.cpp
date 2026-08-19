class Solution {
private:
    void helper(int open, int close, string curr, int n, vector<string> &ans){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }

        if(open == n){
            helper(open, close + 1, curr + ')', n, ans);
        }
        else {
            helper(open + 1, close, curr + '(', n, ans);

            if(open - close > 0){
                helper(open, close + 1, curr + ')', n, ans);
            }
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0, 0, "", n, ans);
        return ans;
    }
};