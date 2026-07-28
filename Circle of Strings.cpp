class Solution {
  public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node]=1;
        for(auto &it: adj[node]){
            if(!vis[it]) dfs(it,vis,adj);
        }
    }
  
    bool isCircle(vector<string> &arr) {
        // code here
        vector<vector<int>> adj(26);
        vector<int> indegree(26,0), outdegree(26,0);
        int node=-1; //first node having outdegree > 0
        for(auto &it: arr){
            int size=it.size();
            adj[it[0]-'a'].push_back(it[size-1]-'a');
            
            indegree[it[size-1]-'a']++;
            outdegree[it[0]-'a']++;
            
            if(node==-1) node=it[0]-'a';
        }
        
        if(node==-1) return true;
        
        //check whether part of single connected component
        //start from first node having outdegree > 0
        vector<bool> vis(26,0);
        dfs(node,vis,adj);
        
        for(int i=0;i<26;i++){
            if(!vis[i] && (indegree[i]>0 || outdegree[i]>0)) return false;
            else if(indegree[i]!=outdegree[i]) return false;
        }
        
        return true;
    }
};

/*
============================= INTUITION =============================

Instead of considering every STRING as a node, consider every CHARACTER
('a' to 'z') as a node and every string as a DIRECTED EDGE from its first
character to its last character.

Example:
"for"  =>  f ----> r

Now the problem simply becomes:
"Can we traverse every edge exactly once and return back to the starting
vertex?"

This is exactly the Euler Circuit problem in a directed graph.

Conditions:
1. indegree == outdegree for every vertex.
2. All vertices having non-zero degree should belong to a single connected
   component (checked by DFS).


=========================== EDGE CASES ===========================

1. BIGGEST INSIGHT:
   Characters are the NODES.
   Strings are the EDGES.
   (Treating strings as nodes leads to backtracking/permutations.)  => will lead to exponential TC (N!)

2. Single character strings ("a") are VALID.
   They represent a self-loop (a -> a).

3. Self-loops increase both indegree and outdegree by 1.
   Degree balance remains unchanged, but the edge MUST be included.

4. Parallel edges are completely valid.
   Example:
   "ab", "ab", "ba", "ba"
   Both "ab" strings represent different edges.

5. Never start DFS from vertex 0.
   Start from the first vertex having an outgoing edge.

6. Ignore isolated characters.
   Vertices having indegree = outdegree = 0 don't participate in the answer.

7. Even if every vertex satisfies indegree == outdegree,
   disconnected components still make the answer FALSE.

   Example:
   {"ab","ba","c"}    => This testcase was not even in the gfg testcases

   Here:
   a <-> b
   c -> c

   Degrees are balanced, but there are two disconnected components.

8. A character may appear only as a starting character,
   only as an ending character,
   or as both.
   Degree equality automatically handles all such cases.

9. There are only 26 vertices.
   Hence DFS and degree checking are effectively O(1).
   Overall complexity is O(N), where N = number of strings.

10. REVISION TRIGGER:
    Whenever you see:
    "Use every string exactly once"

    Immediately think:
    "Every string is an EDGE."
    ==> Euler Path / Euler Circuit.
*/