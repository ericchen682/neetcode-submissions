class Solution {
public:
    int m, n, len;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string& word, int ind, int x, int y)
    {
        if(ind == len)
            return true;
        
        if(x < 0 || x >= m || y < 0 || y >= n || vis[x][y])
            return false;
        
        if(board[x][y] != word[ind])
            return false;
        
        vis[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            if(dfs(board, vis, word, ind + 1, x + dx[i], y + dy[i]))
                return true;
        }
        vis[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // start a dfs from each node
        // track whether or not each node has been visited before
        m = board.size();
        n = board[0].size();
        len = word.size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dfs(board, vis, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
