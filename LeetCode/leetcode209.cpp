class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int L = 0, R = 0;
        int ret = INT_MAX;
        while(L<=R && R<len)
        {
            sum += nums[R];
            if(sum < target)
            {
                ++R;
            }
            else
            {
                while(sum - nums[L] >= target)
                {
                    sum = sum - nums[L];
                    ++L;
                }
                ++R;
                ret = min(ret, R-L);
            }
        }
        return sum>=target?ret:0;
    }
};
