class Solution {
  public:
    void pushLeft(Node* root, stack<Node*>& st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
  
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        stack<Node*> st1,st2;
        pushLeft(root1,st1);
        pushLeft(root2,st2);
        
        vector<int> ans;
        while(!st1.empty() || !st2.empty()){
            if(st1.empty()){
                Node* curr = st2.top();
                st2.pop();
                ans.push_back(curr->data);
                pushLeft(curr->right, st2);
            }

            else if(st2.empty()){
                Node* curr = st1.top();
                st1.pop();
                ans.push_back(curr->data);
                pushLeft(curr->right, st1);
            }

            else if(st1.top()->data < st2.top()->data){
                Node* curr = st1.top();
                st1.pop();
                ans.push_back(curr->data);
                pushLeft(curr->right, st1);
            }

            else{
                Node* curr = st2.top();
                st2.pop();
                ans.push_back(curr->data);
                pushLeft(curr->right, st2);
            }
        }
        return ans;
    }
};