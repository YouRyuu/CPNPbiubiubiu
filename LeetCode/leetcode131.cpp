class Solution {
public:
        vector<vector<string>> ret;
        vector<vector<int>> dp;
        vector<string> ans;

    void dfs(string &s, int i)
    {
        if(i==s.size())
        {
            ret.push_back(ans);
            return;
        }
        for(int j=i; j<s.size(); ++j)
        {
            if(dp[i][j])
            {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j+1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, 1));
        for(int i=n-1; i>=0; --i)
        {
            for(int j=i+1; j<n; ++j)
            {
                dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
            }
        }
        dfs(s, 0);
        return ret;
    }
};
