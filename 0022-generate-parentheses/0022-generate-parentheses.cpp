class Solution {
private:
    void helper(int idx, int openBrackets, string s, int n, vector<string>& ans){
        if(idx==2*n){
            if(openBrackets==0) ans.push_back(s);
            return;
        }
        helper(idx+1,openBrackets+1,s+'(',n,ans);
        if(openBrackets>0) helper(idx+1,openBrackets-1,s+')',n,ans);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0,0,"",n,ans);
        return ans;
    }
};