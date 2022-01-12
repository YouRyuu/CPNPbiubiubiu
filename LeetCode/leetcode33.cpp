class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r = size-1;
        int mid;
        while(l<=r)
        {
            mid = (r+l)/2;
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid])
            {
                //左半边有序
                if(nums[l]<=target && nums[mid]>=target)
                {
                    r = mid-1;
                }
                else
                    l = mid+1;
            }
            else
            {
                //右半边有序
                if(nums[mid]<=target && nums[r]>=target)
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return -1;
    }
};
