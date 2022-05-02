class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;

    void bt(vector<int> &candidates, int index, int sum, int target)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            ret.push_back(v);
            return;
        }
        for(int i=index; i<candidates.size(); ++i)
        {
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            v.push_back(candidates[i]);
            bt(candidates, i+1, sum+candidates[i], target);
            v.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        bt(candidates, 0, 0, target);
        return ret;
    }
};
