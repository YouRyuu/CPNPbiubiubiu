class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int L = 0, R = len-1;
        while(L<=R)
        {
            int mid = (L + R)/2;
            if(nums[mid]==target)
                return true;
            if(nums[L]==nums[mid] && nums[mid]==nums[R])
            {
                ++L;
                --R;
            }
            else if(nums[L] <= nums[mid])
            {
                if(nums[mid] > target && nums[L]<=target)
                    R = mid - 1;
                else
                    L = mid + 1;
            }
            else
            {
                if(nums[mid] < target && nums[R]>=target)
                    L =mid + 1;
                else
                    R = mid - 1;
            }
        }
        return false;
    }
};
