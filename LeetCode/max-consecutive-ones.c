int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0;
    int res = 0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==1)
        {
            count++;
        }
        else if(nums[i]==0)
        {
            res = count>res?count:res;
            count = 0;
            if((numsSize-i-1)<res)
                return res;
        }
    }
    return count>res?count:res;
}