class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # run bfs on grid
        stack = []
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                cnt = 0
                if grid[i][j] == 0:
                    continue
                stack.append((i, j))
                while len(stack) > 0:
                    x, y = stack[-1]
                    stack.pop()
                    grid[x][y] = 0
                    cnt = cnt + 1
                    for k in range(4):
                        nx = x + dx[k]
                        ny = y + dy[k]
                        if nx < 0 or nx >= len(grid) or ny < 0 or ny >= len(grid[0]):
                            continue
                        if grid[nx][ny] == 0:
                            continue
                        stack.append((nx, ny))
                        grid[nx][ny] = 0
                res = max(res, cnt)
        return res