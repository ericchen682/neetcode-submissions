class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<pair<int, int>> q;
        // max monotonic stack
        for(int i = 0; i < k; i++)
        {
            while(!q.empty() && nums[i] >= q.back().first)
            {
                q.pop_back();
            }
            q.push_back(make_pair(nums[i], i));
        }
        res.push_back(q.front().first);
        for(int i = k; i < nums.size(); i++)
        {
            if(q.front().second == i-k) q.pop_front();
            while(!q.empty() && nums[i] >= q.back().first)
            {
                q.pop_back();
            }
            q.push_back(make_pair(nums[i],i));
            res.push_back(q.front().first);
        }
        return res;
    }
};
