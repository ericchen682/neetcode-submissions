class Solution {
public:
    map<int, int> m;
    vector<vector<int>> res;
    int depth;
    void solve(vector<int>& curr)
    {
        if(depth == 0)
        {
            res.push_back(curr);
            return;
        }
        else
        {
            for(auto [key, value] : m)
            {
                if(value == 0) continue;
                m[key]--; depth--;
                curr.push_back(key);
                solve(curr);
                curr.pop_back();
                m[key]++; depth++;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // nonunique perms occur iff there are identical nums
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        vector<int> empty = {};
        depth = nums.size();
        solve(empty);
        return res;
    }
};
