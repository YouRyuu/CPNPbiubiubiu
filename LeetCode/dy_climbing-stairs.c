int climbStairs(int n) {
    if(n==1) return 1;
    int result[n+1];
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;
    for(int i=3;i<=n;i++)
    {
        result[i] = result[i-1] + result[i-2];
    }
    return result[n];
}