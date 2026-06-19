class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // we want to flood fill every O from the edges

        // 3 passes - mark all as .
        // then mark all edges as O
        // then mark all . as X

        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = '.';
            }
        }

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == '.')
            {
                board[i][0] = 'O';
                q.push({i, 0});
            }
            if(board[i][n-1] == '.')
            {
                board[i][n-1] = 'O';
                q.push({i, n-1});
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == '.')
            {
                board[0][i] = 'O';
                q.push({0, i});
            }
            if(board[m-1][i] == '.')
            {
                board[m-1][i] = 'O';
                q.push({m-1, i});
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int nx, ny;
        while(!q.empty())
        {
            auto [ x, y ] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];

                if
                (
                    nx < 0 || nx >= m || ny < 0 || ny >= n
                    || board[nx][ny] != '.'
                )
                    continue;
                board[nx][ny] = 'O';
                q.push({nx, ny});
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == '.')
                    board[i][j] = 'X';
            }
        }

        return;
    }
};
