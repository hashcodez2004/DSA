class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int n=s.size();
        int len=0;
        int i=0, j=0;
        while(j<n){
            if(mpp.find(s[j])!=mpp.end() && mpp[s[j]]>=i) i=mpp[s[j]]+1;
            mpp[s[j]]=j;
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};