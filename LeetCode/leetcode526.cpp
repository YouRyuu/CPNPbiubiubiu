class Solution {
public:
    int ret = 0;
    int countArrangement(int n) {
        vector<int> visited(n+1);
        dfs(n, visited, 1);
        return ret;
    }

    void dfs(int n, vector<int> &visited, int index)
    {
        if(index > n)
            ++ret;
        for(int i=1; i<=n; ++i)
        {
            if(!visited[i] && (i%index==0 || index%i==0))
            {
                visited[i] = 1;
                dfs(n, visited, index+1);
                visited[i] = 0;
            }
        }
    }
};
