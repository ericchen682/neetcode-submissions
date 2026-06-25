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
    int listLength(ListNode* head) {
        if(head == nullptr)
            return 0;
        return 1 + listLength(head->next);
    }

    ListNode* reverseBackHalf(ListNode* head, int n)
    {
        for(int i = 0; i < (n - 1)/2; i++)
        {
            head = head->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head->next;
        ListNode* next;
        head->next = nullptr;
        while(curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // steps:
        // find length
        // find tail
        // reverse back half
        int n = listLength(head);
        if(n <= 2) return;
        ListNode* tail = reverseBackHalf(head, n);
        ListNode* res = head;
        ListNode* headNext = head->next;
        ListNode* tailNext = tail->next;
        // if head isn't nullptr
        // then head->next is equal to tail
        // then head = headNext
        // if tail isn't nullptr
        // then tail->next is equal to headNext
        // then tail = tailNext

        // set headNext = head->next
        // set tailNext = tail->next
        while(tail != nullptr)
        {
            ListNode* headNext = head->next;
            ListNode* tailNext = tail->next;
            head->next = tail;
            tail->next = headNext;
            head = headNext;
            tail = tailNext;
        }
        head = res;
    }
};
