//递推公式:dp[i] = max(dp[i-2]+nums[i], dp[i-1])
int rob(int* nums, int numsSize){
    if(numsSize==1) return nums[0];
    if(numsSize<1) return 0;
    int dp = nums[0];
    int res = nums[0]>nums[1]?nums[0]:nums[1];
    for(int i=2;i<numsSize;i++)
    {
        int temp = res;
        res = dp+nums[i]>res?dp+nums[i]:res;
        dp = temp;
    }
    return res;
}

