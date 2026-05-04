class Trie{
private:
    struct Node{
        Node *links[26] = {nullptr};
        bool flag = false;
        bool containsKey(char ch){
            return links[ch - 'a'] != nullptr;
        }
        void put(char ch, Node *node){
            links[ch - 'a'] = node;
        }
        Node *get(char ch){
            return links[ch - 'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
    };
    
    Node *root;
    
public:
    Trie(){
        root = new Node;
    }
    
    void insert(string &word) {
        Node *node = root;
        for(char ch : word){
            if(!node->containsKey(ch)) node->put(ch,new Node());
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool checkAllPrefix(string &word){
        Node *node = root;
        for(char ch : word){
            if(!node->containsKey(ch)) return false;
            node = node->get(ch);
            if(!node->isEnd()) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie t;
        
        for(string &s : words){
            t.insert(s);
        }
        
        string ans = "";
        for(string &s : words){
            if(t.checkAllPrefix(s)){
                if(s.length() > ans.length() || 
                  (s.length() == ans.length() && s < ans)){
                    ans = s;
                }
            }
        }
        
        return ans;
    }
};


/*
Time Complexity: O(N * L), Where N is the number of words and L is the average length of each word
SC: Can't be predicted with certainity
*/