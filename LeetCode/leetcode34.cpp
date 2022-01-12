class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r = size-1;
        if(size==0) return {-1, -1};
        if(size==1)
        {
            if(nums[0]==target) return {0,0};
            else return {-1,-1};
        }
        while(l<=r)
        {
            if(nums[l]!=target)
            {
                ++l;
            }
            if(nums[r]!=target)
            {
                --r;
            }
            if(nums[l]==target && nums[r]==target)
                return {l, r};
        }
        return {-1, -1};

    }
};
