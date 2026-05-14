class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check 3x3
        // check rows
        // check cols
        for(int i = 0; i < 9; i++)
        {
            map<char, bool> row;
            map<char, bool> col;
            map<char, bool> square;
            int x = (i%3)*3;
            int y = (i/3)*3;
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;
                if(row[board[i][j]]) return false;
                else row[board[i][j]] = true;
            }
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] == '.') continue;
                if(col[board[j][i]]) return false;
                else col[board[j][i]] = true;
            }
            for(int j = 0; j < 9; j++)
            {
                if(board[x][y] != '.')
                {
                    if(square[board[x][y]]) return false;
                    square[board[x][y]] = true;
                }
                x++;
                if(x == (i%3+1)*3)
                {
                    x = (i%3)*3;
                    y++;
                }
            }
        }
        return true;
    }
};
