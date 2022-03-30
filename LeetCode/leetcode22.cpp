class Solution {
public:

    void dfs(vector<string> &ret, const string &cur, int left, int right)
    {
        if(left==0 && right==0)
        {
            ret.push_back(cur);
            return;
        }
        if(left > right)    return;
        if(left>0)
            dfs(ret, cur+'(', left-1, right);
        if(right>0)
            dfs(ret, cur+')', left, right-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string curr="";
        dfs(ret, curr, n, n);
        return ret;
    }
};
