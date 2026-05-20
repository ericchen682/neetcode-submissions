class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // use dp, store the lcs
        int l1 = text1.size();
        int l2 = text2.size();
        int dp[l1+1][l2+1];
        dp[0][0] = 0;

        for(int i = 1; i <= l1; i++)
        {
            dp[i][0] = 0;
        }

        for(int j = 1; j <= l2; j++)
        {
            dp[0][j] = 0;
        }

        for(int i = 1; i <= l1; i++)
        {
            for(int j = 1; j <= l2; j++)
            {
                dp[i][j] = 0;
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
                dp[i][j] = max(dp[i][j-1], dp[i][j]);
            }
        }
        return dp[l1][l2];
    }
};
