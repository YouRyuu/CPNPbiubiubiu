class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int len = nums.size();
        if(len<3)
            return ret;
        sort(nums.begin(), nums.end());
        int prev0=10e6, prev1=10e6;
        for(int i=0; i<len; ++i)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int v = -nums[i];
            int L = i+1, R = len-1;
            while(L<R)
            {
                int sum = nums[L] + nums[R];
                if(sum == v)
                {
                    if(nums[i]==prev0 && nums[L]==prev1)
                    {
                        ++L;--R;continue;
                    }
                    ret.push_back({nums[i], nums[L], nums[R]});
                    prev0 = nums[i]; prev1 = nums[L];
                    ++L;--R;
                }
                else if(sum > v)
                    --R;
                else
                    ++L;
            }
        }
        return ret;
    }
};
