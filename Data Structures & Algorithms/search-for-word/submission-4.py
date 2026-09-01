class Solution:
    def helper(self, board: List[List[str]], vis: List[List[bool]], word: str, ind: int, x: int, y: int) -> bool:
        if board[x][y] != word[ind]:
            return False
        vis[x][y] = True
        ind = ind + 1
        if ind == len(word):
            return True
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= len(board) or ny >= len(board[0]) or vis[nx][ny] is True:
                continue
            if self.helper(board, vis, word, ind, nx, ny) is True:
                return True
        vis[x][y] = False
        return False

    def exist(self, board: List[List[str]], word: str) -> bool:
        vis = [[False] * len(board[0]) for i in range(len(board[0]))]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.helper(board, vis, word, 0, i, j) is True:
                    return True
        return False