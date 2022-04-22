class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = 0;
        int a=0, b=0;
        for(int num:nums)
        {
            n ^= num;
        }
        int temp = 1;
        while((n & temp) == 0)
            temp <<= 1;
        for(int num : nums)
        {
            if(temp & num)
                a ^= num;
            else
                b ^= num;
        }
        return {a, b};
    }
};
