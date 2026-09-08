class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        res = []
        l = intervals[0][0]
        r = intervals[0][1]
        for i in range(len(intervals)):
            if intervals[i][0] > r:
                res.append([l, r])
                l = intervals[i][0]
                r = intervals[i][1]
            else:
                r = max(r, intervals[i][1])
        res.append([l, r])
        return res