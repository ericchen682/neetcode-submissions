class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i] * nums[i+1] * nums[i+2];
        }
        // we can calculate pop left + pop right

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n-i; j++)
            {
                // calculate cost of dp[j][j+i]
                // consider popping jth -> j+ith last
                dp[j][j+i] = max(dp[j][j+i], (dp[j+1][j+i] + nums[j] * nums[j+1] * nums[j+i+2]));
                for(int k = j+1; k < j+i; k++)
                {
                    // pop left first then pop right
                    int curr = nums[j] * nums[k+1] * nums[j+i+2];
                    curr += dp[j][k-1] + dp[k+1][j+i];
                    dp[j][j+i] = max(dp[j][j+i], curr);
                }
                dp[j][j+i] = max(dp[j][j+i], (dp[j][j+i-1] + nums[j] * nums[j+i+1] * nums[j+i+2]));
            }
        }
        return dp[0][n-1];
    }
};
