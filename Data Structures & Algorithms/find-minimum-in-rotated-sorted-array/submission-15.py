class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        if len(nums) == 1:
            return nums[0]
        
        while l < r:
            mid = l + (r - l) // 2
            if nums[l] < nums[mid] and nums[r] < nums[mid]:
                # if both the leftmost and rightmost are less than mid
                # then we must have min on the right
                l = mid + 1
            elif nums[l] < nums[mid] and nums[r] > nums[mid]:
                # if the leftmost is less than mid but the rightmost
                # is greater than mid
                # then the right side cannot contain the min
                r = mid
            elif nums[r] < nums[mid]:
                # leftmost greater than mid
                # rightmost less than mid
                l = mid + 1
            else:
                r = mid
        return nums[l]
                
        # what are cases in which we move left?
        # what are cases in which we move right?

        # if the immediate left of the number is greater
        # then we have found our answer
