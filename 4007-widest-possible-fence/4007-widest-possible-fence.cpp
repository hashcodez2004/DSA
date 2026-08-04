class Solution {
public:
    int maximumWidth(vector<int>& planks) {

        //store every element's frequency count
        unordered_map<long long,int> freq;
        for(int x : planks) freq[x]++;

        //made this so that can easily iterate over unique pairs using indexes => not possible in case of map
        vector<pair<long long,int>> values;
        for(auto it : freq) values.push_back(it); //already existing pairs entered into vector

        //to store final answers
        unordered_map<long long,int> possible;

        // Existing planks
        for(auto it : values) possible[it.first] += it.second;

        int n = values.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long sum = values[i].first + values[j].first;
                if(i==j) possible[sum] += values[i].second/2;
                else possible[sum] += min(values[i].second,values[j].second);
            }
        }

        int ans = 1;
        for(auto it : possible) ans = max(ans,it.second);

        return ans;
    }
};