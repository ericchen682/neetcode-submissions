class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // perform bfs
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        stack<pair<int, int>> bfs;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '0' || vis[i][j])
                    continue;
                res++;
                bfs.push({i, j});
                while(!bfs.empty())
                {
                    auto [ x, y ] = bfs.top();
                    bfs.pop();
                    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || vis[x][y])
                        continue;
                    vis[x][y] = true;
                    for(int k = 0; k < 4; k++)
                    {
                        bfs.push({x + dx[k], y + dy[k]});
                    }
                }
            }
        }
        return res;
    }
};
