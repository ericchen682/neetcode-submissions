class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(target+1, vector<vector<int>>({}));
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= target)
                dp[nums[i]].push_back({nums[i]});
        }
        for(int i = 1; i < target; i++)
        {
            for(auto comb : dp[i])
            {
                for(int j = 0; j < nums.size(); j++)
                {
                    if (nums[j] < comb.back()) continue;
                    comb.push_back(nums[j]);
                    if(i + nums[j] <= target)
                        dp[i + nums[j]].push_back(comb);
                    comb.pop_back();
                }
            }
        }
        return dp[target];
    }
};
