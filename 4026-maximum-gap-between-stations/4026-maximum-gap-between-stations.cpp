class Solution {
public:
    int maximumGap(string skill, string station) {
        int m=skill.size();
        int n=station.size();

        vector<int> starting(m);
        int i=0, j=0;
        while(i<m && j<n){
            if(skill[i]==station[j]){
                starting[i]=j;
                i++;
                j++;
            }
            else j++;
        }

        vector<int> ending(m);
        i=m-1, j=n-1;
        while(i>=0 && j>=0){
            if(skill[i]==station[j]){
                ending[i]=j;
                i--;
                j--;
            }
            else j--;
        }

        int ans=0;
        for(int i=0;i<m-1;i++){
            ans=max(ans, abs(starting[i]-ending[i+1]));
        }

        return ans;
    }
};