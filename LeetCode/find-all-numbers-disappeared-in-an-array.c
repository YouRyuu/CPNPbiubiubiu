int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
        int i;
    for(i=0;i<numsSize;i++)
    {
        int temp = (nums[i]>0?nums[i]:-nums[i])-1;
        if(nums[temp]>0) nums[temp] = -nums[temp];
    }
    *returnSize = 0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>0) nums[(*returnSize)++] = i+1;
    }
    return nums;
}