class Solution {
    bool isPalindrome(int i, int j, string& s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    void helper(int idx, string& s, vector<string>& path, vector<vector<string>>& ans){
        if(idx==s.size()) ans.push_back(path);

        for(int i=idx; i<s.size(); i++){
            if(isPalindrome(idx,i,s)){
                path.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0,s,path,ans);
        return ans;
    }
};