class Solution {
public:
    int numWays(int n, int k) {
        if(n==1)    return k;
        int a = k, b = k*k;
        for(int i=2; i<n; ++i)
        {
            int c = (a+b)*(k-1);
            a = b;
            b = c;
        }
        return b;
    }
};
