class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # bin search for k
        l = 1
        r = max(piles)
        while l < r:
            mid = l + (r - l)//2
            # if mid passes then l = mid
            # otherwise r = mid - 1
            time = 0
            for pile in piles:
                time += ((pile - 1) // mid) + 1
            if time <= h:
                r = mid
            else:
                l = mid + 1
        return l
            