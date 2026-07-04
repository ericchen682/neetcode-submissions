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
    int listSize(ListNode* head)
    {
        if(head == nullptr)
            return 0;
        return 1 + listSize(head->next);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // determine size of list first
        int sz = listSize(head);
        if(n == sz)
            return head->next;
        sz -= n;
        ListNode* temp = head;
        sz--;
        while(sz != 0)
        {
            temp = temp->next;
            sz--;
        }
        temp->next = temp->next->next;
        return head;
    }
};
