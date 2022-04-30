class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if(len<3)
            return false;
        int first = nums[0], second = INT_MAX;
        for(int i=1; i<len; ++i)
        {
            int num = nums[i];
            if(num > second)
                return true;
            else if(num < first)
                first = num;
            else if(num > first)
                second = num;
        }
        return false;
    }
};
