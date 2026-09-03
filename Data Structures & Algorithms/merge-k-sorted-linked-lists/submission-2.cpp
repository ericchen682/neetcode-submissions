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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // maintain pq of front of all lists
        ListNode* res = new ListNode();
        ListNode* curr = res;
        int n = lists.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; ++i)
        {
            if(lists[i])
            {
                pq.push({ lists[i]->val, i });
            }
        }
        if(pq.empty())
            return nullptr;
        while(!pq.empty())
        {
            int i = pq.top().second;
            pq.pop();
            curr->next = lists[i];
            curr = curr->next;
            lists[i] = lists[i]->next;
            if(lists[i])
            {
                pq.push({ lists[i]->val, i });
            }
        }
        return res->next;
    }
};
