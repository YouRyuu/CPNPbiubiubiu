//摩尔投票算法
int majorityElement(int* nums, int numsSize) {
        int count = 1;
    int res = nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]==res)
            count++;
        else
        {
            count--;
            if(count==0)
                res=nums[i+1];
        }
    }
    return res;
}