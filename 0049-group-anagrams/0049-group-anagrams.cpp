class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp;
        for(auto &word : strs) {
            vector<int> freq(26, 0);
            for(auto ch : word) {
                freq[ch - 'a']++;
            }

            mpp[freq].push_back(word);
        }

        vector<vector<string>> ans;
        for(auto &it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};