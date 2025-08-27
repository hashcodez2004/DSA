/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void addLeftBoundary(Node* root, vector<int>& res){
        Node* curr = root->left;
        while(curr!=NULL){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    
    void addRightBoundary(Node* root, vector<int>& res){
        Node* curr = root->right;
        vector<int> temp;
        while(curr!=NULL){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        for(int i=temp.size()-1;i>=0;i--) res.push_back(temp[i]);
    }
    
    void addLeaves
    (Node* root, vector<int>& res){
        if(isLeaf(root)) res.push_back(root->data);
        if(root->left) addLeaves(root->left,res);
        if(root->right) addLeaves(root->right,res);
    }
    
    bool isLeaf(Node* root){
        return (root->left==NULL && root->right==NULL);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(root==NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        
        return res;
    }
};
