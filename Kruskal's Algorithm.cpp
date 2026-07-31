class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        DisjointSet ds(V);

        // {u, v, wt} -> {wt, {u, v}}
        vector<pair<int, pair<int, int>>> temp;

        for (auto &it : edges)
            temp.push_back({it[2], {it[0], it[1]}});

        // Heap Construction (Heapify) : O(E)
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq(temp.begin(), temp.end());

        int edgeCnt = V - 1;
        int mstWeight = 0;

        while (edgeCnt && !pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int wt = curr.first;
            int u = curr.second.first;
            int v = curr.second.second;

            if (ds.findUPar(u) == ds.findUPar(v))
                continue;

            ds.unionBySize(u, v);

            mstWeight += wt;
            edgeCnt--;
        }

        return mstWeight;
    }
};

/*
====================== Complexity ======================

Current Approach (Heapify + Priority Queue)

1. Convert edges into {wt,{u,v}} vector : O(E)
2. Heap Construction (Heapify)          : O(E)
3. Pop Operations                       : O(K log E)
4. DSU Operations                       : O(K * α(V))

where,
K = Number of popped edges
V = Number of vertices
E = Number of edges

Worst Case:
O(E log E)

Space Complexity:
Priority Queue : O(E)
DSU            : O(V)

Overall:
O(E + V)

--------------------------------------------------------

Previous Approach (Repeated push())

1. E push() operations into PQ : O(E log E)
2. Pop Operations              : O(K log E)
3. DSU Operations              : O(K * α(V))

Worst Case:
O(E log E)

Space Complexity:
O(E + V)

--------------------------------------------------------

Observation

• Both approaches have the same worst-case complexity.

• Heapify builds the initial priority queue in O(E),
  whereas repeated insertion takes O(E log E).

• Since Kruskal stops after selecting V-1 edges,
  only K edges are popped (K ≤ E), allowing early termination.

========================================================
*/
