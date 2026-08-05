class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int n){
        if(parent[n]==n) return n;
        return parent[n]=findUPar(parent[n]);
    }

    void unionBySize(int m, int n){
        int ulp_m=findUPar(m);
        int ulp_n=findUPar(n);
        if(ulp_m==ulp_n) return;
        else if(size[ulp_m]>=size[ulp_n]){
            parent[ulp_n]=ulp_m;
            size[ulp_m]+=size[ulp_n];
        }
        else{
            parent[ulp_m]=ulp_n;
            size[ulp_n]+=size[ulp_m];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();

        DisjointSet dsu(n);

        unordered_map<string,int> mpp; // {emailId,idx}
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()) mpp.insert({accounts[i][j],i});
                else dsu.unionBySize(i,mpp[accounts[i][j]]);
            }
        }

        vector<vector<string>> ans(n);
        for(auto &it: mpp){
            string node=it.first;
            int idx=dsu.findUPar(it.second);
            ans[idx].push_back(node);
        }

        vector<vector<string>> finalAns;
        for(int i=0;i<n;i++){
            if(ans[i].size()==0) continue;
            sort(ans[i].begin(),ans[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &it: ans[i]) temp.push_back(it);
            
            finalAns.push_back(temp);
        }

        return finalAns;
    }
};