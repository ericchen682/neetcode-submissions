class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(len(s)):
            if dp[i] == True:
                for j in range(i + 1, len(s) + 1, 1):
                    if dp[j] == False and s[i:j] in wordSet:
                        dp[j] = True
        return dp[len(s)]


