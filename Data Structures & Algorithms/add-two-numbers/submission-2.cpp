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
        ListNode* res = new ListNode();
        ListNode* curr = res;
        ListNode* next = res;
        bool carry = false;
        int val = 0;
        while(l1 != nullptr || l2 != nullptr || carry)
        {
            curr = next;
            val = 0;
            if(l1 != nullptr)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr)
            {
                val += l2->val;
                l2 = l2->next;
            }
            if(carry)
                val++;
            if(val >= 10)
                carry = true;
            else
                carry = false;
            val %= 10;
            curr->val = val;
            next = new ListNode();
            curr->next = next;
        }
        curr->next = nullptr;
        return res;
    }
};
