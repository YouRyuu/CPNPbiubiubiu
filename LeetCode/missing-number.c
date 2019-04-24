int missingNumber(int* nums, int numsSize) {
    int max = -1;
    int sum = 0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>max)
            max = nums[i];
        sum += nums[i];
    }
    return (numsSize*(numsSize+1)/2-sum);
}


///less space use
//如果数组是完整的,那么这个数组和对应的下标异或就应该是0,反之缺少一个数,那么最后结果肯定就是缺少的这个数
int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int i;
    for(i = 0 ; i < numsSize ; i++){
        n ^= *(nums+i);
        n ^= i;
    }
    return n;
}