class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dy[4] = {1, 0, -1, 0};
        int dx[4] = {0, 1, 0, -1};
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int tSize = m * n;
        int x = 0, y = 0;
        int i = 0;
        for(int ind = 0; ind < tSize; ind++)
        {
            res.push_back(matrix[x][y]);
            matrix[x][y] = 101;
            x += dx[i];
            y += dy[i];
            if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == 101)
            {
                x -= dx[i];
                y -= dy[i];
                i++;
                i%=4;
                x += dx[i];
                y += dy[i];
            }
        }
        return res;
    }
};
