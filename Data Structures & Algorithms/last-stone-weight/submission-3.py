import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heapq.heapify_max(stones)
        while len(stones) > 1:
            x = stones[0]
            heapq.heappop_max(stones)
            y = stones[0]
            heapq.heappop_max(stones)
            if x == y:
                continue
            heapq.heappush_max(stones, x - y)
        if len(stones) == 0:
            return 0
        return stones[0]