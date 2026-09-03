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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // stored in reverse order
        // sum the 2 numbers
        ListNode* res = new ListNode();
        ListNode* curr = res;
        int sum {};
        bool carry {false};
        while (l1 || l2)
        {
            sum = 0;
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if(carry)
                sum += 1;
            if(sum/10 == 1)
                carry = true;
            else
                carry = false;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        if (carry)
            curr->next = new ListNode(1);
        return res->next;
    }
};
