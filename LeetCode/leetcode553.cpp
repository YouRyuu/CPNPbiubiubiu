class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return to_string(nums[0]);
        if(len == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        string ret = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for(int i=2; i<len; ++i)
        {
            ret += "/";
            ret += to_string(nums[i]);
        }
        ret += ")";
        return ret;
    }
};
