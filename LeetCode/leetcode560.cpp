class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int pre = 0;
        int count = 0;
        m[0] = 1;
        for(auto item : nums)
        {
            pre += item;
            if(m.count(pre-k)!=0)
                count += m[pre-k];
            ++m[pre];
        }
        return count;
    }
};
