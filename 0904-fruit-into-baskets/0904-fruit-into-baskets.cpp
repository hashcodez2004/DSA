class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int n=fruits.size();
        int i=0;
        int j=0;
        int maxx=1;
        while(j<n){
            mpp[fruits[j]]++;
            if(mpp.size()<=2) maxx=max(maxx, j-i+1);
            while(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0) mpp.erase(fruits[i]);
                i++;
                if(mpp.size()==2) maxx=max(maxx, j-i+1);
            }
            j++;
        }
        return maxx;
    }
};