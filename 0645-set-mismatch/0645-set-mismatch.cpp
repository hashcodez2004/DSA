using ll = long long;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        ll Sn=1LL*(n)*(n+1)/2;
        ll S2n=1LL*(n)*(n+1)*(2*n+1)/6;
        ll Sni=0;
        ll S2ni=0;
        for(int i=0;i<n;i++){
            Sni+=nums[i];
            S2ni+=nums[i]*nums[i];
        }
        //Now we know that Difference between Total sum is Sn-Sni and Sum of Squares is S2n-S2ni
        ll diffSum=Sn-Sni;
        ll diffSumOfSquares=S2n-S2ni;
        int repeating, missing;
        repeating = (diffSumOfSquares - (diffSum*diffSum)) / (2*diffSum);
        missing = repeating + diffSum;
        return {repeating,missing};
    }
};