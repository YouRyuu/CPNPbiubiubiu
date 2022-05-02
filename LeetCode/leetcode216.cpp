class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;
    void bt(vector<int> &nums, int index, int sum, int count, int k, int target)
    {
        if(count > k)
            return;
        if(count==k && sum==target)
        {
            ret.push_back(v);
            return;
        }
        for(int i=index; i<nums.size(); ++i)
        {
            v.push_back(nums[i]);
            bt(nums, i+1, sum+nums[i], count+1, k, target);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums{1,2,3,4,5,6,7,8,9};
        bt(nums, 0, 0, 0, k, n);
        return ret;
    }
};
