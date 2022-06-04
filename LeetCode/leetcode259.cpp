class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int left, right;
        int ret = 0;
        for(int i=0; i<len-2; ++i)
        {
            left = i+1;
            right = len-1;
            int curr = 0;
            while(left < right)
            {
                if(nums[left] + nums[right] < target-nums[i])
                {
                    curr += right - left;
                    ++left;
                }
                else
                    --right;
            }
            ret += curr;
        }
        return ret;
    }
};
