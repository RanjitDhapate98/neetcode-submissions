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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr){
             ListNode* nexti=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nexti;
        }
        fast=head;
        while(fast!=prev && fast->next !=prev ){
            ListNode* n1=fast->next;
            ListNode* n2=prev->next;
            fast->next=prev;
            prev->next=n1;
            fast=n1;
            prev=n2;
        }
 
    }
};
