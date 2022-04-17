class Solution {
public:
    int numWays(int n) {
        if(n<2) return 1;
        int p = 0, q = 1, r = p+q;
        for(int i=2; i<=n; ++i)
        {
            p = q;
            q = r;
            r = (p+q)%1000000007;
        }
        return r;
    }
};
