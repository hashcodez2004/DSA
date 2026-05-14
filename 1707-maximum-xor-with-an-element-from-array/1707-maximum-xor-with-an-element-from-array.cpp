class Trie {
private:
    struct Node {
        Node *links[2]={nullptr};
        bool containsKey(int bit){
            return links[bit]!=nullptr;
        }
        void put(int bit,Node *node) {
            links[bit]=node;
        }
        Node *get(int bit) {
            return links[bit];
        }
    };

    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int n) {
        Node *node=root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXOR(int num) {
        Node* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int> ans(m);

        vector<pair<int,pair<int,int>>> offlineQueries;
        for(int i=0;i<m;i++){
            offlineQueries.push_back({queries[i][1],{queries[i][0],i}});
        }
        
        sort(offlineQueries.begin(),offlineQueries.end());
        sort(nums.begin(),nums.end());

        Trie t;
        int i=0;
        for(auto it: offlineQueries){
            int xi=it.second.first;
            int mi=it.first;
            int idx=it.second.second;

            while(i<n && nums[i]<=mi){
                t.insert(nums[i]);
                i++;
            }

            int res=-1;
            if(i!=0) res=t.getMaxXOR(xi);
            ans[idx]=res; 
        }
        return ans;
    }
};