#define MAX(a,b) (a)>(b)?(a):(b)

/**
  *dp[i] = max(nums[i]+dp[i-1], nums[i])
  */
int maxSubArray(int* nums, int numsSize){
    int res = nums[0];
    int dp = nums[0];
    for(int i=1;i<numsSize;i++)
    {
        dp = MAX(nums[i], dp+nums[i]);
        res = MAX(dp, res);
    }
    return res;
}
