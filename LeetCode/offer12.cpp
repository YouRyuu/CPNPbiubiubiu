class Solution {
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); ++i)
        {
            for(int j=0; j<board[0].size(); ++j)
            {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int i, int j, int index)
    {
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0 || board[i][j]!=word[index])
            return false;
        if(index==word.size()-1)    return true;
        board[i][j] = '/';
        for(int k=0; k<4; ++k)
        {
            if(dfs(board, word, i+dir[k][0], j+dir[k][1], index+1))
                return true;;
        }
        board[i][j] = word[index];
        return false;
    }
};
