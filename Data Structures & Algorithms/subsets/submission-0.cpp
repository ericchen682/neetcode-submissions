class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, vector<int> curr, int ind)
    {
        if(ind >= nums.size())
        {
            res.push_back(curr);
            return;
        }
        int num = 0;
        for(int i = ind; i < nums.size(); i++)
        {
            if(nums[ind] == nums[i])
                num++;
        }
        for(int i = 0; i < num; i++)
        {
            solve(nums, curr, ind + num);
            curr.push_back(nums[ind]);
        }
        solve(nums, curr, ind + num);
        for(int i = 0; i < num; i++)
        {
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // all possible subsets
        // backtracking
        solve(nums, {}, 0);
        return res;
    }
};
