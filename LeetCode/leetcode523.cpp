class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;      //余数：下标
        int pre = 0;
        m[0] = -1;
        for(int i=0; i<nums.size(); ++i)
        {
            pre = pre + nums[i];
            if(m.count(pre%k)!=0)
            {
                int index = m[pre%k];
                if(i-index>=2)
                    return true;
            }
            else
                m[pre%k] = i;
        }
        return false;
    }
};
