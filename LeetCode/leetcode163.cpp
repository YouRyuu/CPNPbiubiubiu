class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        string v;
        nums.insert(nums.begin(), lower-1);
        nums.push_back(upper+1);
        int len = nums.size();
        for(int i=0; i<len-1; ++i)
        {
            if(nums[i]+1!=nums[i+1])
            {
                if(nums[i]+2==nums[i+1])
                {
                    v = to_string(nums[i]+1);
                }
                else
                {
                    v = to_string(nums[i]+1);
                    v += "->";
                    v += to_string(nums[i+1]-1);

                }
                    ret.push_back(v);
                    v.clear();
            }
        }
        return ret;
    }
};
