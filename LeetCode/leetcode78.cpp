class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;

    void dfs(int index, vector<int> &nums)
    {
        if(index==nums.size())
        {
            ret.push_back(v);
            return;
        }
        v.push_back(nums[index]);
        dfs(index+1, nums);
        v.pop_back();
        dfs(index+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ret;
    }
};
