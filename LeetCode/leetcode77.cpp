class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;

    void bt(int cur, int n, int k)
    {
        if(v.size()==k)
        {
            ret.push_back(v);
            return;
        }
        for(int i=cur; i<=n; ++i)
        {
            v.push_back(i);
            bt(i+1, n, k);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        bt(1,n,k);
        return ret;
    }
};
