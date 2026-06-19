class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // evaluate if a node can reach pacific and atlantic
        // evaluate if each node can reach pacific, and then if each node can reach
        // the atlantic
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        // run dfs

        // what cells can each location reach? 
        // can these cells reach pacific? can they reach atlantic?

        // run a pacific check, then an atlantic check, then a general check
        // run a dfs from each pacific location first to populate pacific
        // do same for atlantic

        // we want to process in reverse order of height, min height processed first
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i = 0; i < m; i++)
        {
            pq.push({-1*heights[i][0], {i, 0}});
            pac[i][0] = true;
        }
        
        for(int i = 1; i < n; i++)
        {
            pq.push({-1*heights[0][i], {0, i}});
            pac[0][i] = true;
        }

        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };
        int nx, ny;
        while(!pq.empty())
        {
            auto [ height, coords ] = pq.top();
            auto [ x, y ] = coords;
            pq.pop();
            for(int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];
                if(
                    nx < 0 || nx >= m || ny < 0 || ny >= n 
                    || heights[nx][ny] < heights[x][y] 
                    || pac[nx][ny]
                )
                    continue;
                pq.push({ -1*heights[nx][ny], { nx, ny } });
                pac[nx][ny] = true;
            }
        }

        for(int i = 0; i < m; i++)
        {
            pq.push({-1*heights[i][n-1], {i, n-1}});
            atl[i][n-1] = true;
        }
        
        for(int i = 0; i < n-1; i++)
        {
            pq.push({-1*heights[m-1][i], {m-1, i}});
            atl[m-1][i] = true;
        }

        while(!pq.empty())
        {
            auto [ height, coords ] = pq.top();
            auto [ x, y ] = coords;
            pq.pop();
            for(int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];
                if(
                    nx < 0 || nx >= m || ny < 0 || ny >= n 
                    || heights[nx][ny] < heights[x][y] 
                    || atl[nx][ny]
                )
                    continue;
                pq.push({ -1*heights[nx][ny], { nx, ny } });
                atl[nx][ny] = true;
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});
                    
        return res;
    }
};
