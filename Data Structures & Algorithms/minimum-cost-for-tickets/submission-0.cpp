class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[n+1];
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            dp[i] = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            // 1 covers next day only
            // 7 covers next day + 6 days
            // 30 covers next day + 29 days
            // 1 case
            int j = i + 1;
            dp[j] = min(dp[j], dp[i] + costs[0]);
            while(j <= n && days[j-1] - days[i] < 7)
            {
                dp[j] = min(dp[j], dp[i] + costs[1]);
                j++;
            }
            j = i + 1;
            while(j <= n && days[j-1] - days[i] < 30)
            {
                dp[j] = min(dp[j], dp[i] + costs[2]);
                j++;
            }
        }
        return dp[n];
    }
};