class Solution {
public:
    string minWindow(string s, string t) {
        int p = s.size();
        int q = t.size();

        vector<int> v(123, 0);
        for(int i = 0; i < q; i++) v[t[i]]++;

        int i = 0, j = 0, cnt = 0;
        int minLen = INT_MAX, start = 0;

        while(j < p){
            v[s[j]]--;
            if(v[s[j]] >= 0) cnt++;

            // when window is valid
            while(cnt == q){
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    start = i;
                }

                v[s[i]]++;
                if(v[s[i]] > 0) cnt--;
                i++;
            }
            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
