class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=0, maxValue = nums[0];
        for(auto&x:nums)
        {
            pre = max(pre+x, x);
            maxValue = max(maxValue, pre);
        }        
        return maxValue;
    }
};
