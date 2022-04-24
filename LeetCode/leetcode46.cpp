class Solution {
public:
    vector<vector<int>> ret;
    vector<int> v;
    void bt(vector<int> &nums, int start, int len, int visited[])
    {
        if(v.size()==len)
        {
            ret.push_back(v);
            return;
        }
        for(int i=0; i<nums.size(); ++i)
        {
            if(!visited[i])
            {
                visited[i] = 1;
                v.push_back(nums[i]);
                bt(nums, start+1, len, visited);
                v.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        int visited[len];
        memset(visited, 0, sizeof(visited));
        bt(nums, 0, len, visited);
        return ret;
    }
};
