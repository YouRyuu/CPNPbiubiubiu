class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;
    void dfs(vector<int>& candidates, int index, int sum, int target)
    {   
        if(index==candidates.size() || sum > target)
            return;
        if(sum==target)
        {
            ret.push_back(v);
            return;
        }
        v.push_back(candidates[index]);
        dfs(candidates, index, sum+candidates[index], target);
        v.pop_back();
        dfs(candidates, index+1, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        dfs(candidates, 0, 0, target);
        return ret;
    }
};
