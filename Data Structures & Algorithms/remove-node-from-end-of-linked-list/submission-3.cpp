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
        ListNode* temp = head;
        int sz = 0;
        while(temp)
        {
            ++sz;
            temp = temp->next;
        }
        sz -= n;
        temp = head;
        if(sz == 0)
            return head->next;
        for(int i = 1; i < sz; ++i)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
