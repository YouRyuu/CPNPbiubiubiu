class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxValue=0;
        for(auto &num:nums)
        {
            if(num>maxValue)
                maxValue=num;
        }
        vector<int> dp(maxValue+1,0);
        for(auto &num:nums)
        {
            dp[num]+=num;
        }
        int first=dp[0], second=dp[1], third;
        for(int i=2;i<dp.size();++i)
        {
            third = max(first+dp[i], second);
            first=second, second = third;
        }
        return third;
    }
};
