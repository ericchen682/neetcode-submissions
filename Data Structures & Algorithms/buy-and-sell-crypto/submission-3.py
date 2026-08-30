class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # keep track of min price we've seen so far
        # keep track of current res value
        res = 0
        cmin = prices[0]
        for price in prices:
            res = max(res, price - cmin)
            cmin = min(cmin, price)
        return res