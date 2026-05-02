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
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;

            bool isPos = nums[i] > 0;
            int slow = i;
            int fast = i;

            while(true){
                // move slow once
                int slowNext = findNextIndex(nums, slow);
                if(slowNext == slow) break;                 // self-loop
                if(isPos && nums[slowNext] < 0) break;     // direction change
                if(!isPos && nums[slowNext] > 0) break;

                // move fast once
                int fastNext = findNextIndex(nums, fast);
                if(fastNext == fast) break;
                if(isPos && nums[fastNext] < 0) break;
                if(!isPos && nums[fastNext] > 0) break;

                // move fast second time
                int fastNext2 = findNextIndex(nums, fastNext);
                if(fastNext2 == fastNext) break;
                if(isPos && nums[fastNext2] < 0) break;
                if(!isPos && nums[fastNext2] > 0) break;

                slow = slowNext;
                fast = fastNext2;

                if(slow == fast) return true;
            }

            //ab tkk koi cycle nhi mila => so is path me vha tkk k nodes jha
            //loop break me gyi hogi unhe 0 mark krdo
            // mark visited path
            int curr = i;
            if(isPos){
                while(nums[curr] > 0){
                    int next = findNextIndex(nums, curr);
                    nums[curr] = 0;
                    curr = next;
                }
            }
            else{
                while(nums[curr] < 0){
                    int next = findNextIndex(nums, curr);
                    nums[curr] = 0;
                    curr = next;
                }
            }
        }
        return false;
    }
};