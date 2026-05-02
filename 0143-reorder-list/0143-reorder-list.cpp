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
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(head){
            head=head->next;
            temp->next=prev;
            prev=temp;
            temp=head;
        }
        return prev;
    }

    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast){
            slow=slow->next;
            if(fast->next!=NULL) fast=fast->next->next;
            else fast=NULL;
        }
        return slow;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* mid=middle(head);
        ListNode* head2=reverseList(mid);
        ListNode* head1=head;
        while(head2){
            ListNode* head1_next=head1->next;
            ListNode* head2_next=head2->next;

            head1->next=head2;
            head1=head1_next;
            head2->next=head1;
            head2=head2_next;
        }
        head1->next=head2;
    }
};