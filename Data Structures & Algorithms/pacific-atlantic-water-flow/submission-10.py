class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # determine whether or not a point can reach pacific
        # determine whether or not a point can reach atlantic
        # then return both
        # we want to run dfs along border
        atl = [[False] * len(heights[0]) for _ in range(len(heights))]
        pac = [[False] * len(heights[0]) for _ in range(len(heights))]
        res = []
        coords = []
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in range(len(heights)):
            coords.append([i, 0])
            pac[i][0] = True
            while len(coords) > 0:
                x, y = coords.pop()
                for j in range(4):
                    nx = x + dx[j]
                    ny = y + dy[j]
                    if nx < 0 or ny < 0 or nx >= len(heights) or ny >= len(heights[0]) or pac[nx][ny] is True or heights[nx][ny] < heights[x][y]:
                        continue
                    pac[nx][ny] = True
                    coords.append([nx, ny])
            coords.append([i, len(heights[0]) - 1])
            atl[i][len(heights[0]) - 1] = True
            while len(coords) > 0:
                x, y = coords.pop()
                for j in range(4):
                    nx = x + dx[j]
                    ny = y + dy[j]
                    if nx < 0 or ny < 0 or nx >= len(heights) or ny >= len(heights[0]) or atl[nx][ny] is True or heights[nx][ny] < heights[x][y]:
                        continue
                    atl[nx][ny] = True
                    coords.append([nx, ny])
        for i in range(len(heights[0])):
            coords.append([0, i])
            pac[0][i] = True
            while len(coords) > 0:
                x, y = coords.pop()
                for j in range(4):
                    nx = x + dx[j]
                    ny = y + dy[j]
                    if nx < 0 or ny < 0 or nx >= len(heights) or ny >= len(heights[0]) or pac[nx][ny] is True or heights[nx][ny] < heights[x][y]:
                        continue
                    pac[nx][ny] = True
                    coords.append([nx, ny])
            coords.append([len(heights) - 1, i])
            atl[len(heights) - 1][i] = True
            while len(coords) > 0:
                x, y = coords.pop()
                for j in range(4):
                    nx = x + dx[j]
                    ny = y + dy[j]
                    if nx < 0 or ny < 0 or nx >= len(heights) or ny >= len(heights[0]) or atl[nx][ny] is True or heights[nx][ny] < heights[x][y]:
                        continue
                    atl[nx][ny] = True
                    coords.append([nx, ny])
        for i in range(len(heights)):
            for j in range(len(heights[0])):
                if pac[i][j] is True and atl[i][j] is True:
                    res.append([i, j])
        return res
