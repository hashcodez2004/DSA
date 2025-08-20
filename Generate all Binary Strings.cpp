// User function Template for C++

class Solution {
  private:
    void helper(int idx, int num, vector<string>& ans, string s){
        if(idx==num){
            if(s.size()==num) ans.push_back(s);
            return;
        }
        //taking 0
        s+='0';
        helper(idx+1,num,ans,s);
        //taking 1
        if(idx==0 || s[s.size()-2]=='0'){
            s.pop_back();
            s+='1';
            helper(idx+1,num,ans,s);
        }
    }
    
  public:
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        helper(0,num,ans,"");
        return ans;
    }
};


/*
TC: O(2^N)
SC: O(N)
*/