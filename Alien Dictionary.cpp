class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();

        vector<int> degree(26, -1);

        // Mark all characters present in the dictionary
        for(auto &word : words){
            for(char ch : word){
                if(degree[ch - 'a'] == -1) degree[ch - 'a'] = 0;
            }
        }

        set<pair<char,char>> s; //so that no duplicate pairs exist

        // Build edges
        for(int i = 0; i < n - 1; i++){
            int j = 0;
            int len = min(words[i].size(), words[i+1].size());

            while(j < len && words[i][j] == words[i+1][j]) j++;
            
            // Invalid dictionary
            if(j == len && words[i].size() > words[i+1].size()) return "";

            if(j < len) s.insert({words[i][j], words[i+1][j]});
        }

        vector<vector<int>> adj(26);

        // Build graph
        for(auto &it : s){
            int u = it.first - 'a';
            int v = it.second - 'a';

            adj[u].push_back(v);
            degree[v]++;
        }

        queue<int> q;

        int V = 0;  //no of nodes
        for(int i = 0; i < 26; i++){
            if(degree[i] != -1) V++;
            if(degree[i] == 0) q.push(i);
        }

        string ans="";
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node + 'a');

            for(auto &it : adj[node]){
                degree[it]--;
                if(degree[it] == 0) q.push(it);
            }
        }

        if(ans.size() == V) return ans;
        return "";
    }
};

/*
Approach:
1. Mark all characters present in the dictionary.
2. Compare every pair of adjacent words.
3. Find the first mismatching character:
      word1[j] -> word2[j]
   and create a directed edge.
4. If one word is a prefix of another but appears later
   (e.g. "abcd" before "ab"), the dictionary is invalid.
5. Perform Topological Sort (Kahn's Algorithm).
6. If all existing characters are processed,
   return the ordering.
   Otherwise, a cycle exists, so return "".

TC: O(N * L + V + E)
    N = Number of words
    L = Average length of a word
    V = Number of unique characters (<=26)
    E = Number of precedence relations

SC: O(V + E)
    - Adjacency List : O(V + E)
    - Indegree Array : O(V)
    - Queue          : O(V)
    - Set            : O(E)
*/