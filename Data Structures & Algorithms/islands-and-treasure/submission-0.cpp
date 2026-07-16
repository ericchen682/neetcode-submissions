class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> bfs;
        // val, x, y
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                    for(int k = 0; k < 4; k++)
                        bfs.push({1, { i + dx[k], j + dy[k] } });
            }
        }

        while(!bfs.empty())
        {
            auto [ val, coords ] = bfs.front();
            bfs.pop();
            auto [ x, y ] = coords;
            if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= val)
                continue;
            grid[x][y] = val;
            for(int i = 0; i < 4; i++)
            {
                bfs.push({val + 1, {x + dx[i], y + dy[i]}});
            }
        }
        return;
    }
};
