class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mSize = 0;
        stack<pair<int, int>> bfs;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                int cSize = 0;
                if(grid[i][j] == 1)
                    bfs.push(make_pair(i, j));
                while(!bfs.empty())
                {
                    auto [ x, y ] = bfs.top();
                    bfs.pop();
                    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
                        continue;
                    cSize++;
                    grid[x][y] = 0;
                    bfs.push(make_pair(x+1, y));
                    bfs.push(make_pair(x-1, y));
                    bfs.push(make_pair(x, y+1));
                    bfs.push(make_pair(x, y-1));
                }
                mSize = max(mSize, cSize);
            }
        }
        return mSize;
    }
};
