class Solution {
public:
    bool check(long long initial, vector<int>& monsters, vector<long long>& bonus) {
        long long curr = initial;
        for (int i=0;i<monsters.size();i++) {
            if (curr+bonus[i]<monsters[i]) return false;
            curr-=monsters[i];
            if(curr<0) curr=0;
        }
        return true;
    }

    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        // Difference array for bonuses
        vector<long long> diff(n + 1, 0);
        for(auto &it: boosts) {
            int l = it[0];
            int r = it[1];
            long long v = it[2];

            diff[l]+=v;
            if(r+1<n) diff[r+1]-=v;
        }

        vector<long long> bonus(n);
        bonus[0]=diff[0];
        for(int i=1;i<n;i++) bonus[i]=bonus[i-1]+diff[i];

        long long low=0, high=accumulate(monsters.begin(),monsters.end(),0LL);

        while(low<=high){
            long long mid= low + (high-low)/2;

            if (check(mid,monsters,bonus)) high=mid - 1;
            else low=mid+1;
        }

        return low;
    }
};