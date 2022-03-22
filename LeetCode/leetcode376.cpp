class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len<2) return len;
        int diff = nums[1] - nums[0];
        int ret = diff==0?1:2;
        for(int i=2; i<len; ++i)
        {
            int nowdiff = nums[i] - nums[i-1];
            if(diff<=0 && nowdiff>0 || diff>=0 && nowdiff<0)
            {
                ++ret;
                diff = nowdiff;
            }
        }
        return ret;
    }
};
