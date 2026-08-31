class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # want to go right, then down, then left, then up
        res = []
        dy = [1, 0, -1, 0]
        dx = [0, 1, 0, -1]
        n = len(matrix)
        m = len(matrix[0])
        x, y = 0, 0
        i = 0
        while matrix[x][y] != 101:
            res.append(matrix[x][y])
            matrix[x][y] = 101
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m or matrix[nx][ny] == 101:
                i = (i + 1) % 4
                nx = x + dx[i]
                ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m or matrix[nx][ny] == 101:
                return res
            x = nx
            y = ny
        return res