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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp=head;
        while(n>0 && temp){
            temp=temp->next;
            n--;
        }
        ListNode* slow=head;
         if(!temp){
        return head->next;
      }
        while(temp->next){
            slow=slow->next;
            temp=temp->next;
        }
     
        slow->next=slow->next->next;
    
        
        return head;
    }
};
