class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = l1;
        ListNode* prev = nullptr;

        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;

            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

       
        while (l1) {
            int sum = l1->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;

            prev = l1;
            l1 = l1->next;
        }

       
        if (l2)
            prev->next = l2;

     
        while (l2) {
            int sum = l2->val + carry;
            carry = sum / 10;
            l2->val = sum % 10;

            prev = l2;
            l2 = l2->next;
        }

    
        if (carry)
            prev->next = new ListNode(carry);

        return ans;
    }
};