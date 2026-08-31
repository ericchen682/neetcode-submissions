class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # we want to track running min and running max
        res = nums[0]
        cmax = 1
        cmin = 1
        for num in nums:
            tmp = cmax * num
            cmax = max(cmax * num, cmin * num, num)
            cmin = min(tmp, num * cmin, num)
            res = max(res, cmax)
        return res
