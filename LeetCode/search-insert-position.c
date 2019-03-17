int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = (left + right)/2;
    while(left<right)
    {
        if(nums[mid]<target)
        {
            left = mid + 1;
            mid = (left + right)/2;
        }
        else if(nums[mid]>target)
        {
            right = mid - 1;
            mid = (left + right)/2;
        }
        else return mid;
    }k
    if(nums[left]<target) return left+1;
    else if(nums[left]>target) return left;
    else return left;
}