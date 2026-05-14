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
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie t;
        for(int i=0;i<n;i++) t.insert(nums[i]);
        int maxii=0;
        for(int i=0;i<n;i++) maxii=max(maxii,t.getMaxXOR(nums[i]));
        return maxii;
    }
};