class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        //WILL ONLY CHECK FOR NEXT NUMBERS IF AND ONLY IF THAT NUMBER IS THE STARTING OF THE SEQUENCE
        int n=nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++) st.insert(nums[i]);
        
        int ans=0;
        for(auto it: st){
            //If starting number of the sequence
            if(st.find(it-1)==st.end()){
                int cnt=0;
                while(st.find(it)!=st.end()){
                    cnt++;
                    it++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};


/*
TC: O(N) => storing into set + O(2N) => in total inner while will run for N and outer while is already N
SC: O(N) => set
*/