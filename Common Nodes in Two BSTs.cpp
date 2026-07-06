class Solution {
  public:
    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> ans;
        stack<Node*> s1, s2;

        while (r1) {
            s1.push(r1);
            r1 = r1->left;
        }

        while (r2) {
            s2.push(r2);
            r2 = r2->left;
        }

        while (!s1.empty() && !s2.empty()) {
            //Both equal
            if (s1.top()->data == s2.top()->data) {
                ans.push_back(s1.top()->data);
                r1 = s1.top()->right;
                s1.pop();
                r2 = s2.top()->right;
                s2.pop();
            }
            //First greater
            else if (s1.top()->data > s2.top()->data) {
                r2 = s2.top()->right;
                s2.pop();
            }
            //Second greater
            else {
                r1 = s1.top()->right;
                s1.pop();
            }
            
            //update the stacks
            while (r1) {
                s1.push(r1);
                r1 = r1->left;
            }
            while (r2) {
                s2.push(r2);
                r2 = r2->left;
            }
        }

        return ans;
    }
};

/*
TC: O(n1 + n2)
SC: O(h1 + h2)
*/