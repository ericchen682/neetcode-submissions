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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = nullptr;
        ListNode* curr = nullptr;
        while(list1 != nullptr || list2 != nullptr)
        {
            if(list1 == nullptr)
            {
                if(curr == nullptr)
                    root = list2;
                else
                    curr->next = list2;
                return root;
            }

            if(list2 == nullptr)
            {
                if(curr == nullptr)
                    root = list1;
                else
                    curr->next = list1;
                return root;
            }

            if(list1->val < list2->val)
            {
                if(curr == nullptr)
                {
                    curr = list1;
                    root = list1;
                    list1 = list1->next;
                }
                else
                {
                    curr->next = list1;
                    curr = list1;
                    list1 = list1->next;
                }
            }
            else
            {
                if(curr == nullptr)
                {
                    curr = list2;
                    root = list2;
                    list2 = list2->next;
                }
                else
                {
                    curr->next = list2;
                    curr = list2;
                    list2 = list2->next;
                }
            }
        }
        return root;
    }
};
