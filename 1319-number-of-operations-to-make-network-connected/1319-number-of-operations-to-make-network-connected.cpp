class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i <= n; i++){
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
        if(ulp_m == ulp_n) return;
        if(size[ulp_m]>=size[ulp_n]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;

        DisjointSet dsu(n);
        for(auto &it: connections){
            int u=it[0];
            int v=it[1];

            dsu.unionBySize(u,v);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(dsu.findUPar(i)==i) cnt++;
        }

        return cnt-1;
    }
};