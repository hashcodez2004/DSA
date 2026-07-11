class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);
        vector<int> degree(n + 1, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
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