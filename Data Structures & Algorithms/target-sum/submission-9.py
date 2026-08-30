class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # either add or subtract to target
        total = 0
        for num in nums:
            total += num
        if abs(target) > total:
            return 0
        # we want to find sum = target
        # therefore we have target + (total - target) // 2
        # therefore we have (total + target) // 2
        # if total + target is odd?
        if (total + target) % 2 == 1:
            return 0
        s = (total + target) // 2
        dp = [0] * (s + 1)
        dp[0] = 1
        for num in nums:
            for i in range(s - num, -1, -1):
                dp[i + num] += dp[i]
        return dp[s]