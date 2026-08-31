class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        // base case is 1, 2, 3 stones left (take them all)
        // do dp in reverse
        // let dp[i] be the score diff when the ith and onwards stones are left

        int n = stoneValue.size();
        int dp[n];
        for(int i = 0; i < n; i++)
        {
            dp[i] = INT_MIN;
        }
        int j;
        for(int i = n-1; i >= 0; i--)
        {
            if(n - i <= 3)
            {
                dp[i] = 0;
                for(j = i; j < n; j++)
                {
                    dp[i] += stoneValue[j];
                }
            }
            // then we have the option of taking 1 2 or 3 stones
            int stonesTaken = 0;
            for(j = 0; j < 3; j++)
            {
                // take 1 stone if j = 0
                if(i + j >= n - 1) continue;
                stonesTaken += stoneValue[i+j];
                dp[i] = max(dp[i], stonesTaken - dp[i+j+1]);
            }
        }

        if(dp[0] == 0)
            return "Tie";
        if(dp[0] > 0)
            return "Alice";
        return "Bob";
    }
};