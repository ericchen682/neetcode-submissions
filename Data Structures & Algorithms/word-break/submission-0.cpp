class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 1d string dp
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++)
        {
            if(!dp[i])
                continue;
            for(int j = 0; j < wordDict.size(); j++)
            {
                int k = wordDict[j].size();
                if(s.substr(i, k) == wordDict[j])
                    dp[i + k] = true;
            }
        }
        return dp[n];
    }
};
