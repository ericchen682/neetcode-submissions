import heapq

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        pq = []
        heapq.heappush(pq, (grid[0][0], 0, 0))
        grid[0][0] = -1
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        n = len(grid)
        res = 0
        while len(pq) > 0:
            height, x, y = heapq.heappop(pq)
            res = max(height, res)
            if x == (n - 1) and y == (n - 1):
                return res
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx < 0 or ny < 0 or nx >= n or ny >= n or grid[nx][ny] == -1:
                    continue
                heapq.heappush(pq, (grid[nx][ny], nx, ny))
                grid[nx][ny] = -1
        
