class Solution {
public:
    vector<vector<int>> res;
    void solve(int ind, vector<int> curr, vector<int>& nums)
    {
        if(ind >= nums.size())
        {
            res.push_back(curr);
            return;
        }
        // make decision of how many to include
        int cnt = 0;
        while((cnt + ind) < nums.size() && nums[cnt + ind] == nums[ind])
            cnt++;
        for(int i = 0; i < cnt; i++)
        {
            solve(ind + cnt, curr, nums);
            curr.push_back(nums[ind]);
        }
        solve(ind + cnt, curr, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for each we want to either make decision of 0->n
        // once we make decision, we jump to i+nth index
        solve(0, {}, nums);
        return res;
    }
};
