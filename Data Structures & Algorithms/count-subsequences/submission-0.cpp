class Solution {
public:
    int numDistinct(string s, string t) {
        // dp -- what ind of s are we on, what ind of t are we on
        int sl = s.size(), tl = t.size();
        long long dp[sl+1][tl+1];
        for(int i = 0; i <= sl; i++)
        {
            for(int j = 0; j <= tl; j++)
            {
                dp[i][j] = 0;
            }
        }
        for(int i = 0; i <= sl; i++)
        {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= sl; i++)
        {
            for(int j = 1; j <= tl; j++)
            {
                dp[i][j] += dp[i-1][j];
                if(s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[sl][tl];
    }
};
