class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        r = intervals[0][0]
        res = 0
        for interval in intervals:
            if r > interval[0]:
                res += 1
                r = min(interval[1], r)
            else:
                r = max(interval[1], r)
        return res