class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pfx = [0] * (len(nums) + 1)
        sfx = [0] * (len(nums) + 1)
        pfx[0] = 1
        sfx[len(nums)] = 1
        for i in range(len(nums)):
            pfx[i + 1] = pfx[i] * nums[i]
            sfx[len(nums) - i - 1] = sfx[len(nums) - i] * nums[len(nums) - i - 1]
        res = []
        for i in range(len(nums)):
            res.append(pfx[i] * sfx[i + 1])
        return res