class Solution {
public:
    vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
    bool ret = false;
    void dfs(vector<vector<char>>& board, string &word, int k, int i, int j)
    {
        if(i>=0 && i<board.size() && j>=0 && j<board[0].size())
        {
            if(board[i][j]==word[k])
            {
                if(k==word.size()-1)
                    ret = true;
                char temp = board[i][j];
                board[i][j] = '0';
                for(int p=0; p<4; ++p)
                {
                    dfs(board, word, k+1, i+dir[p][0], j+dir[p][1]);
                }
                board[i][j] = temp;
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
         int m = board.size();
         int n = board[0].size();
         for(int i=0; i<m; ++i)
         {
             for(int j=0; j<n; ++j)
             {
                 dfs(board, word, 0, i, j);
                 if(ret==true)
                    return ret;
             }
         }
         return ret;
    }
};
