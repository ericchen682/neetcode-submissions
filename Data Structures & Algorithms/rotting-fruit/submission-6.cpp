class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs out from each rotten fruit cell
        int mt = 0;
        priority_queue<pair<int, pair<int, int>>> bfs;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                    bfs.push({0, {i, j}});
                    grid[i][j] = 1;
                }
            }
        }

        while(!bfs.empty())
        {
            auto [ time, coord ] = bfs.top();
            bfs.pop();
            auto [ x, y ] = coord;
            if(x >= grid.size() || x < 0 || y >= grid[x].size() || y < 0 || grid[x][y] != 1)
                continue;
            mt = min(mt, time);
            cout << x << ' ' << y << '\n';
            grid[x][y] = 2;
            time--;
            bfs.push({time, {x + 1, y}});
            bfs.push({time, {x - 1, y}});
            bfs.push({time, {x, y + 1}});
            bfs.push({time, {x, y - 1}});
        }
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        mt = mt*-1;
        return mt;
    }
};
