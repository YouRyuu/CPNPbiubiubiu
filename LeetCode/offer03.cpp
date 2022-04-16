class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // map<int, int> count;
        // int len = nums.size();
        // for(int i=0; i<len; ++i)
        // {
        //     if(count.count(nums[i])==0)
        //         count[nums[i]] = 1;
        //     else
        //         return nums[i];
        // }
        // return 0;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i=1; i<len; ++i)
        {
            if(nums[i]==nums[i-1])
                return nums[i];
        }
        return 0;
    }
};
