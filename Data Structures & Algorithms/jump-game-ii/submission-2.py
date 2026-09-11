class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [-1] * len(nums)
        dp[0] = 0
        for i in range(len(nums)):
            if dp[i] == -1:
                continue
            for j in range(nums[i] + 1):
                if i + j >= len(nums):
                    continue
                if dp[i + j] == -1:
                    dp[i + j] = dp[i] + 1
                else:
                    dp[i + j] = min(dp[i + j], dp[i] + 1)
        return dp[len(nums) - 1]