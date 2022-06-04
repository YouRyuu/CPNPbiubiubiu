class Solution {
public:

    vector<vector<int>> ret;
    vector<int> v;

    void bt(int n, int m)
    {
        if(v.size())
        {
            ret.push_back(v);
            v.pop_back();
        }
        for(int i=m; i*i<=n; ++i)
        {
            if(n%i==0)
            {
                v.push_back(i);
                v.push_back(n/i);
                bt(n/i, i);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        bt(n, 2);
        return ret;
    }
};
