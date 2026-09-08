class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sz = len(nums)
        res = (sz * (sz + 1)) // 2
        for num in nums:
            res -= num
        return res