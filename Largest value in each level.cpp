class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        if(root==NULL) return {};
        queue<Node*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            int maxi=INT_MIN;
            
            while(len--){
                Node* node=q.front();
                q.pop();
                maxi=max(maxi,node->data);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            
            v.push_back(maxi);
        }
        
        return v;
    }
};