class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        stack = []
        res = 0
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "0":
                    continue
                res += 1
                stack.append([i, j])
                grid[i][j] = "0"
                while len(stack) > 0:
                    x, y = stack.pop()
                    for k in range(4):
                        nx = x + dx[k]
                        ny = y + dy[k]
                        if nx < 0 or ny < 0 or nx >= len(grid) or ny >= len(grid[0]) or grid[nx][ny] == "0":
                            continue
                        stack.append([nx, ny])
                        grid[nx][ny] = "0"
        return res


                