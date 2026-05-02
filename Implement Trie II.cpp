#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26] = {nullptr};
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    void increaseEnd(){
        cntEndWith++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void deleteEnd(){
        cntEndWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->cntPrefix;
    }

    void erase(string &word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)) return;
            node = node->get(ch);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};

/*
Insert: TC O(L), SC O(L)
CountWordsEqualTo: TC O(L), SC O(1)
CountWordsStartingWith: TC O(L), SC O(1)
Erase: TC O(L), SC O(1)

Overall SC: O(N)
*/
