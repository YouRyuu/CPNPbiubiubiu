class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size<2) return size;
        int left = 0, right = left + 1;
        while(right<size)
        {
            if(nums[right]==nums[left])
            {
                ++right;
                continue;
            }
            nums[++left] = nums[right];
        }
        return left+1;

    }
};
