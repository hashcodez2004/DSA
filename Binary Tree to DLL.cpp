class Solution {
  private:
    Node* prev = NULL;
    Node* head = NULL;
    
    void ConvertToDLL(Node* root) {
        if(root == NULL) return;
    
        ConvertToDLL(root->left);
    
        if(prev == NULL) head=root;
        else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        ConvertToDLL(root->right);
    }
    
  public:
    Node* bToDLL(Node* root) {
        // code here
        ConvertToDLL(root);
        return head;
    }
};



/*
FOLLOW-UP QUESTION ------can you do the same for preorder and postorder?

YES-----

              Preorder
    void ConvertToDLL(Node* root) {
        if (root == NULL) return;

        if (prev == NULL)
            head = root;
        else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        ConvertToDLL(root->left);
        ConvertToDLL(root->right);
    }

             Postorder
    void ConvertToDLL(Node* root) {
        if (root == NULL) return;

        ConvertToDLL(root->left);
        ConvertToDLL(root->right);

        if (prev == NULL)
            head = root;
        else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
    }         
*/