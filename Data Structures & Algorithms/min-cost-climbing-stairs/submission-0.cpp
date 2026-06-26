class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // cost[i] is the cost of taking a step from the ith floor of a staircase
        // this means that landing on the stair inherently has cost[i]
        // we have final step taking 0 cost
        int n = cost.size();
        cost.push_back(0);
        cost.push_back(0);
        int dp[n+2];
        for(int i = 0; i < n+2; i++)
        {
            dp[i] = INT_MAX;
        }
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 0; i < n; i++)
        {
            dp[i+1] = min(dp[i] + cost[i+1], dp[i+1]);
            dp[i+2] = min(dp[i] + cost[i+2], dp[i+2]);
        }
        return min(dp[n], dp[n+1]);
    }
};
