class DisjointSet {
private:
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node) {
        if(parent[node]==node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] >= size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
private:
    int MST(vector<vector<int>> &copy, int n) {
        DisjointSet dsu(n);

        int count=0;
        int sum=0;
        for(auto &it: copy) {
            if(count==n-1) break;
            if(dsu.findUPar(it[1]) == dsu.findUPar(it[2])) continue;
            sum+=it[0];
            count++;
            dsu.unionBySize(it[1],it[2]);
        }

        return sum;
    }

    bool isCriticalEdge(int i, int mst, vector<vector<int>> &copy, int n) {
        DisjointSet dsu(n);

        int count=0;
        int sum=0;
        for(auto &it: copy) {
            if(count==n-1) break;
            if(it[3]==i) continue;
            if(dsu.findUPar(it[1]) == dsu.findUPar(it[2])) continue;
            sum+=it[0];
            count++;
            dsu.unionBySize(it[1],it[2]);
        }

        return mst!=sum;
    }

    bool isPseudoCriticalEdge(int i, int mst, vector<vector<int>> &copy, vector<vector<int>>& edges, int n) {
        DisjointSet dsu(n);

        int count=1;
        int sum=edges[i][2];
        dsu.unionBySize(edges[i][0],edges[i][1]);
        for(auto &it: copy) {
            if(count==n-1) break;
            if(it[3]==i) continue;
            if(dsu.findUPar(it[1]) == dsu.findUPar(it[2])) continue;
            sum+=it[0];
            count++;
            dsu.unionBySize(it[1],it[2]);
        }

        return mst==sum;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> copy;
        for(int i=0;i<edges.size();i++) copy.push_back({edges[i][2],edges[i][0],edges[i][1],i});
        sort(copy.begin(), copy.end());

        int mst = MST(copy,n);

        vector<vector<int>> ans(2);

        for(int i=0; i<edges.size(); i++) {
            if(isCriticalEdge(i,mst,copy,n)) {
                ans[0].push_back(i);
            }
            else if(isPseudoCriticalEdge(i,mst,copy,edges,n)) {
                ans[1].push_back(i);
            }
        }

        return ans;
    }
};