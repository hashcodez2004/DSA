class Solution {
public:
//                            Priority Queue

    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {

        vector<int> dis(V, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dis[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){

            int currDis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated entries
            if(currDis > dis[node]){
                continue;
            }

            for(auto &it : adj[node]){

                int neighbourNode = it.first;
                int edgeWeight = it.second;

                int newDis = currDis + edgeWeight;

                if(newDis < dis[neighbourNode]){

                    dis[neighbourNode] = newDis;

                    pq.push({newDis, neighbourNode});
                }
            }
        }

        return dis;
    }


//                                         Set

    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src){

        vector<int> dis(V, INT_MAX);

        set<pair<int,int>> st;

        dis[src] = 0;

        st.insert({0, src});

        while(!st.empty()){

            auto it = *st.begin();

            st.erase(st.begin());

            int currDis = it.first;
            int node = it.second;

            for(auto &edge : adj[node]){

                int neighbour = edge.first;
                int wt = edge.second;

                if(currDis + wt < dis[neighbour]){

                    if(dis[neighbour] != INT_MAX){

                        st.erase({dis[neighbour], neighbour});
                    }

                    dis[neighbour] = currDis + wt;

                    st.insert({dis[neighbour], neighbour});
                }
            }
        }

        return dis;
    }
};



/*
Difference between Priority Queue and Set in Dijkstra

Priority Queue Approach:
- A node can be inserted multiple times with different distances.
- Old (larger) distances are not removed.
- While popping, ignore outdated entries using:

      if(currDis > dis[node]) continue;

- Simpler and faster in practice.
- Most commonly used in Competitive Programming and Interviews.

Example:
Initially:
    (10, 2)

Better path found:
    (3, 2)

Priority Queue:
    (3, 2)
    (10, 2)

The old entry (10, 2) remains.
It is ignored later by the stale entry check.


Set Approach:
- Only one entry of each node is kept.
- Before inserting the new distance,
  erase the old one.

      st.erase({dis[node], node});
      st.insert({newDis, node});

- No duplicate entries exist.
- Slightly slower due to erase operation.
- Demonstrates the "decrease-key" idea.

Example:
Initially:
    (10, 2)

Better path found:
    erase(10, 2)
    insert(3, 2)

Set:
    (3, 2)


Summary:

Priority Queue:
- Duplicate entries ✔
- Needs stale entry check ✔
- Faster in practice ✔
- Preferred implementation ✔

Set:
- No duplicate entries ✔
- No stale entry check needed ✔
- Supports decrease-key using erase + insert ✔
- Slightly slower ✔
*/