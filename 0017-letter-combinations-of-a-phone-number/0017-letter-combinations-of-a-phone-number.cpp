class Solution {
private:
    void helper(int idx, string& s, string digits, vector<string>& ans, unordered_map<char,string>& mpp){
        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }

        for(auto it: mpp[digits[idx]]){
            s+=it;
            helper(idx+1,s,digits,ans,mpp);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};

        //mapping numbers to digits
        unordered_map<char,string> mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";

        //recursive function calling
        vector<string> ans;
        string s="";
        helper(0,s,digits,ans,mpp);
        return ans;
    }
};