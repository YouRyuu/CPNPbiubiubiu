class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ret = nums[0] + nums[len-1] + nums[len -2];
        for(int i=0; i<len; ++i)
        {   
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j = i+1, k = len -1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==target)
                    return sum;
                else if(sum < target)
                {
                    ret = abs(sum - target)<abs(ret-target)?sum:ret;
                    ++j;
                }
                else
                {
                    ret = abs(sum - target)<abs(ret-target)?sum:ret;
                    --k;
                }
            }
        }
        return ret;
    }
};
