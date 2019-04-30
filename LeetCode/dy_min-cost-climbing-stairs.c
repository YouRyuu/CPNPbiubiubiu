int minCostClimbingStairs(int* cost, int costSize) {
    int sum[costSize+1];
    sum[0] = 0;
    sum[1] = 0;
    for(int i=2;i<costSize+1;i++)
    {
        sum[i] = (sum[i-1]+cost[i-1])<(sum[i-2]+cost[i-2])?(sum[i-1]+cost[i-1]):(sum[i-2]+cost[i-2]);
    }
    return sum[costSize];
}