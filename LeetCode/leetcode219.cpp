class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> ret;
        for(int i=0;i<size;i++)
        {
            int value = nums[i];
            if(ret.count(value) && i-ret[value]<=k)
                return true;
            ret[value] = i;
        }
        return false;
    }
};
