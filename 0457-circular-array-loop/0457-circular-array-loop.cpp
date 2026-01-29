class Solution {
private:
    int findNextIndex(vector<int>& nums, int idx){
        int n=nums.size();
        if(nums[idx]>0) return (nums[idx]+idx)%n;
        int mod=abs(nums[idx])%n;
        return (idx+n-mod)%n;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            st.insert(i);
            bool isPos=nums[i]>0;
            int currIdx=i;

            while(true){
                int nextIdx=findNextIndex(nums,currIdx);
                if(isPos){
                    if(nums[nextIdx]<0) break;
                    else{
                        if(st.find(nextIdx)!=st.end()){
                            if(currIdx!=nextIdx) return true;
                            else break;
                        }
                    }
                }
                else{
                    if(nums[nextIdx]>0) break;
                    else{
                        if(st.find(nextIdx)!=st.end()){
                            if(currIdx!=nextIdx) return true;
                            else break;
                        }
                    }
                }
                st.insert(nextIdx);
                currIdx=nextIdx;
            }
        }
        return false;
    }
};