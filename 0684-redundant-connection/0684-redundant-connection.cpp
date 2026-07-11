class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);
        vector<int> degree(n + 1, 0);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        vector<bool> removed(n + 1, false);

        for (int i = 1; i <= n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            removed[node] = true;

            for (int nxt : adj[node]) {
                if (removed[nxt]) continue;

                degree[nxt]--;
                if (degree[nxt] == 1)
                    q.push(nxt);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (!removed[u] && !removed[v])
                return edges[i];
        }

        return {};
    }
};

/*
---------------------------------- Redundant Connection ----------------------------------

Intuition:
----------
A tree has no cycle. If we add one extra edge to a tree, exactly one cycle is formed.

Instead of finding the cycle directly, we remove all nodes that can never be part of a cycle.

Observation:
------------
1. Any node having degree = 1 is a leaf node.
2. A leaf node can never be part of a cycle.
3. Removing a leaf may create new leaf nodes.
4. Keep removing leaf nodes until no leaf remains.
5. The only nodes left are the nodes belonging to the unique cycle.

Finally, traverse the edges from the end of the input.
The first edge whose both endpoints are still present (i.e., not removed)
is the answer because the problem asks for the edge appearing last.

------------------------------------------------------------------------------
Algorithm:
----------
1. Build adjacency list and degree array.
2. Push all leaf nodes (degree = 1) into a queue.
3. Repeatedly:
      - Remove the leaf.
      - Decrease the degree of its neighbours.
      - If any neighbour becomes a leaf, push it into the queue.
4. After pruning finishes, only cycle nodes remain.
5. Traverse the original edge list from the end.
6. Return the first edge whose both endpoints are not removed.

Key Idea:
---------
Instead of detecting the cycle,
eliminate everything that is definitely NOT part of the cycle.
Whatever survives must belong to the unique cycle.
*/