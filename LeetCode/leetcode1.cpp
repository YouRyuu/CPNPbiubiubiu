class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int len = nums.size();
        for(int i=0; i<len; ++i)
        {
            auto item = m.find(target-nums[i]);
            if(item!=m.end())
            {
                return {i, item->second};
            }
            m[nums[i]] = i;
        }        
        return {};
    }
};
