class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ret;
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            if(ret.count(nums[i]))
                return true;
            ret.emplace(nums[i]);
        }
        return false;

    }
};
