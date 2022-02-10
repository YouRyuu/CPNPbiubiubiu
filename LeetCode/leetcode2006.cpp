class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int size = nums.size();
        int count = 0;
        unordered_map<int, int> tmp;
        for(int i=0;i<size;++i)
        {
            count += (tmp.count(nums[i] - k) ? tmp[nums[i] - k] : 0);
            count += (tmp.count(nums[i] + k) ? tmp[nums[i] + k] : 0);
            ++tmp[nums[i]];
        }
        return count;

    }
};
