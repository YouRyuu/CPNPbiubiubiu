//碰个巧ac了,其实这是错误的......qaq
#define max(a,b) ((a)>(b)?(a):(b))

bool stoneGame(int* piles, int pilesSize){
    int *dp = (int *)malloc(sizeof(int)*(pilesSize/2+1));
    int sum=0;
    for(int i=0;i<pilesSize;i++)
        sum+=piles[i];
    int index = 0;
    dp[0] = 0;
    while(index!=pilesSize/2)
    {
        dp[index+1] = dp[index] + max(piles[index], piles[pilesSize-1-index]);
        index++;
    }
    return dp[index]>sum-dp[index]?true:false;
}



https://leetcode-cn.com/problems/stone-game/
数学角度分析,直接return true
