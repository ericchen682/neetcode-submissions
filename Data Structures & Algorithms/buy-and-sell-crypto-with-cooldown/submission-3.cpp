class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp of some sort
        int n = prices.size();
        int dp[n][3]; // 0 is buying and 1 is selling and 2 is can do neither
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i-1][0];
            if(i >= 2) dp[i][0] = max(dp[i][0], dp[i-2][2]);
            // dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = max(dp[i][0] - prices[i], dp[i-1][1]);
            dp[i][2] = max(dp[i][1] + prices[i], dp[i-1][2]);
        }
        return max(dp[n-1][0], dp[n-1][2]);
        // start in buying state
        // simulate buying a coin, move to selling state
        // simulate selling a coin, move to stuck state
        // move stuck state to buying state 2 coins later
    }
};
