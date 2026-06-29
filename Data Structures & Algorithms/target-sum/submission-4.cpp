    class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            int sum = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
            }
            sum *= 2;
            // can either add or subtract each, thus *= 2;
            int dp[nums.size()+1][sum+1];
            for(int i = 0; i <= nums.size(); i++)
            {
                for(int j = 0; j <= sum; j++)
                {
                    dp[i][j] = 0;
                }
            }
            int zero = sum/2;
            dp[0][zero] = 1;
            for(int i = 1; i <= nums.size(); i++)
            {
                for(int j = 0; j <= sum; j++)
                {
                    if(j - nums[i-1] >= 0)
                        dp[i][j] += dp[i-1][j-nums[i-1]];
                    if(j + nums[i-1] <= sum)
                        dp[i][j] += dp[i-1][j+nums[i-1]];
                }
            }
            if(target + zero > sum)
                return 0;
            return dp[nums.size()][target + zero];
        }
    };
