class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;

    void dfs(vector<int> &nums, int index)
    {
        ret.push_back(v);
        if(index>=nums.size())
            return;
        for(int i=index; i<nums.size(); ++i)
        {
            if(i>index && nums[i]==nums[i-1])
                continue;
            v.push_back(nums[i]);
            dfs(nums, i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ret;
    }
};
