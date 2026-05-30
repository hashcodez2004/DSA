/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>> > pq;
        for(int i=0;i<lists.size();i++) 
        if(lists[i])
        pq.push({lists[i]->val, lists[i]});

        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        while(!pq.empty()){
            pair<int,ListNode*> x = pq.top();
            temp->next = x.second;
            pq.pop();
            if(x.second->next) pq.push({x.second->next->val, x.second->next});
            temp=temp->next;
        }
        return dNode->next;
    }
};