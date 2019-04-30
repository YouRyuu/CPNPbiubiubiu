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



///////
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last = 0 
        now = 0
        for i in nums: 
            #其实就是一个奇数和偶数位元素求和，哪个更大么？
            last, now = now, max(last + i, now)
        return now
