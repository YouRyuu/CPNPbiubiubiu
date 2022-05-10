class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;
    vector<int> visited;
    void bt(vector<int> &nums, int index)
    {
        if(index==nums.size())
        {
            ret.push_back(v);
            return;
        }
        for(int i=0; i<nums.size(); ++i)
        {
            if(visited[i] || (i>0 && nums[i]==nums[i-1] && !visited[i-1]))
                continue;
            if(!visited[i])
            {
                visited[i] = 1;
                v.push_back(nums[i]);
                bt(nums, index+1);
                v.pop_back();
                visited[i] = 0;
            }
        }
        
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited.resize(nums.size());
        sort(nums.begin(), nums.end());
        bt(nums, 0);
        return ret;
    }
};
