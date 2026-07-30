class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        // Min Heap -> {edgeWeight, node}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> vis(V, 0);

        pq.push({0, 0});

        int mstWeight = 0;

        while (!pq.empty()) {

            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;

            vis[node] = 1;
            mstWeight += wt;

            for (auto &it : adj[node]) {

                int adjNode = it[0];
                int edgeWt = it[1];

                if (!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return mstWeight;
    }
};


/*
========================
    PRIM'S ALGORITHM
========================

Purpose:
- Finds Minimum Spanning Tree (MST).

Prerequisites:
- Undirected graph
- Weighted graph
- Connected graph (otherwise Minimum Spanning Forest)

Properties:
- Greedy Algorithm
- Works with negative edge weights.
- Cycles may exist in the input graph.
- MST contains exactly (V - 1) edges.

Implementation Notes:
- Use Min Heap {edgeWeight, node}.
- Use Visited Array.
- Lazy Deletion: Ignore already visited nodes.

If asked to PRINT the MST:
- Maintain parent[].
- Whenever a better edge is chosen for a node,
  store parent[child] = currentNode.
- MST edges are: (parent[i], i).

Complexity:
Time  : O(E log E)   // ≈ O(E log V)
Space : O(E)
*/