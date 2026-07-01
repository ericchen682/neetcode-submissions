class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(auto num : nums)
            target += num;
        if(target%2)
            return false;
        target /= 2;
        int n = nums.size();
        bool dp[n][target+1];
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= target; j++)
                dp[i][j] = false;
        dp[0][0] = true;
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                if(!dp[i-1][j])
                    continue;
                dp[i][j] = true;
                if(nums[i] + j < target)
                    dp[i][nums[i] + j] = true;
                if(nums[i] + j == target)
                    return true;
            }
        }
        return false;
    }
};
