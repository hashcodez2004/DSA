class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
        int p = s.size();
        int q = t.size();
        if(q > p) return {};

        vector<int> v1(26, 0), v2(26, 0);

        // build initial window
        for(int i = 0; i < q; i++){
            v1[t[i] - 'a']++;
            v2[s[i] - 'a']++;
        }
        
        vector<int> res;
        int i = 0, j = q - 1;
        while(j < p){
            if(v1 == v2) res.push_back(i);
            j++;
            if(j < p) v2[s[j] - 'a']++;   // add next char
            v2[s[i] - 'a']--;             // remove left char
            i++;
        }
        return res;
    }
};