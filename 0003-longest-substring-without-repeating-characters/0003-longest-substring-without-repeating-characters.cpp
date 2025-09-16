class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) return s.size();
        unordered_map<char, int> mpp;
        int i = 0, j = 0, cnt = 0;  // Initialize j to 0 instead of 1 for correctness
        while (j < s.size()) {
            if (mpp.find(s[j]) != mpp.end()) {
                i = max(i, mpp[s[j]] + 1);
            }
            cnt = max(cnt, j - i + 1);  // Update cnt after adjusting i
            mpp[s[j]] = j;
            j++;
        }
        return cnt;
    }
};
