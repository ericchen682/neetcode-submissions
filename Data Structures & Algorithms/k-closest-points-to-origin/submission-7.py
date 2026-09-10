import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # k closest points maintain priority queue
        pq = []
        for point in points:
            heapq.heappush(pq, (-(point[0]*point[0] + point[1]*point[1]), point))
            if len(pq) > k:
                heapq.heappop(pq)
        res = []
        for i in range(k):
            res.append(pq[i][1])
        return res