#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int node, vector<int> adj[], vector<int>& vis) {
        queue<int> q;
        vis[node] = 1;
        q.push(node);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto it : adj[curr]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int provinces = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                bfs(i, adj, vis);
                provinces++;
            }
        }
        return provinces;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> isConnected(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> isConnected[i][j];
        Solution ob;
        cout << ob.findCircleNum(isConnected) << endl;
    }
    return 0;
}

/*
Time Complexity: O(N) + O(V + 2E), 
Where O(N) is for the loop over nodes, and O(V + 2E) is for total BFS traversal over the entire undirected graph.

Space Complexity: O(N) for visited array + O(N) for queue → O(N)

*/