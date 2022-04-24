class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int cols[9][9];
        int sub[3][3][9];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(sub, 0, sizeof(sub));
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j]!='.')
                {
                    int v = board[i][j] - '0' - 1;
                    rows[i][v] += 1;
                    cols[j][v] += 1;
                    sub[i/3][j/3][v] += 1;
                    if(rows[i][v]>1 || cols[j][v]>1 || sub[i/3][j/3][v]>1)
                        return false;
                }
            }
        }
        return true;
    }
};
