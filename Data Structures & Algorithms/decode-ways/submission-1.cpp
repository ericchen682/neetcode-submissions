class Solution {
public:
    int numDecodings(string s) {
        // each is either one or two
        int n = s.size();
        int dp[n+1];
        dp[0] = 1;
        if(s[0] != '0')
            dp[1] = 1;
        else
            dp[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            // calculate 1 char
            if(s[i-1] != '0')
                dp[i] = dp[i-1];
            else
                dp[i] = 0;
            
            if(stoi(s.substr(i-2, 2)) <= 26 && s[i-2] != '0')
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
