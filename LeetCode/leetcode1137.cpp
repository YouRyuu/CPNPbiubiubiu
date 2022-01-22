class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        int ret[n+1];
        ret[0] = 0, ret[1] = 1, ret[2] = 1;
        int i=3;
        while(i<=n)
        {
            ret[i] = ret[i-1] + ret[i-2] + ret[i-3];
            ++i;
        }
        return ret[n];  
    }
};
