class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return nums;
        int left = 0, right = size-1;
        while(left < right)
        {
            if(nums[left]%2!=0)
            {
                ++left;
            }
            else if(nums[right]%2==0)
            {
                --right;
            }
            else
            {
                int temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                ++left;
                --right;
            }
        }
        return nums;
    }
};
