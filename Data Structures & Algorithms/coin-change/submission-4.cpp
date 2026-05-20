class Solution {
public:
    int coinChange(vector<int>& coins, long long amount) {
        long long dp[amount+1];
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;
        }
        for(int i = 0; i < amount; i++)
        {
            if(dp[i] == INT_MAX) continue;
            for(auto coin : coins)
            {
                if(i + coin > amount) continue;
                dp[i + coin] = min(dp[i + coin], dp[i] + 1);
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
