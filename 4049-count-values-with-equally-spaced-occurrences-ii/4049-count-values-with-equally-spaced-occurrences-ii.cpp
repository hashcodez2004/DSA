class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mpp;

        int cnt = 0;
        for(int i=0; i<n; i++) {

            if(mpp[nums[i]].size() == 0) mpp[nums[i]] = {0, -1, -1, 0};

            if(mpp[nums[i]][3] == 1) continue;

            int &freq=mpp[nums[i]][0];
            int &prev=mpp[nums[i]][1];
            int &gap=mpp[nums[i]][2];
            int &flag=mpp[nums[i]][3];

            freq++;

            if(freq == 1) prev = i;
            else if(freq == 2){
                gap = i - prev;
                prev = i;
            }
            else{
                int currGap = i - prev;
                if(currGap != gap) flag = 1;
                else prev = i;
            }
        }

        for(auto &it : mpp)
            if(it.second[0] >= 3 && it.second[3] == 0) cnt++;

        return cnt;
    }
};