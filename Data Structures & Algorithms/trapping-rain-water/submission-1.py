class Solution:
    def trap(self, height: List[int]) -> int:
        # at each point we want to find the highest to the left and highest to the right (inclusive)
        # then we subtract the value of every height we come across
        mh = []
        cmax = 0
        for h in height:
            cmax = max(h, cmax)
            mh.append(cmax)
        cmax = 0
        res = 0
        for i in range(len(height) - 1, -1, -1):
            cmax = max(height[i], cmax)
            res += min(mh[i], cmax)
            res -= height[i]
        return res