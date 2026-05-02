class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int len=0;
        int i=0, j=0, maxii=0;
        vector<int> cnt(26,0);
        while(j<n){
            cnt[s[j]-'A']++;
            maxii=max(maxii, cnt[s[j]-'A']);
            //Shrink until
            while((j-i+1)-maxii>k){
                cnt[s[i]-'A']--;
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};