class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // int len = nums.size();
        // int maxValue = INT_MIN;
        // int curr = 0;
        // for(int i=0; i<len; ++i)
        // {
        //     for(int j=0; j<len; ++j)
        //     {
        //         curr += j * nums[(len - i + j)%len];  
        //     }
        //     if(curr>maxValue)
        //         maxValue = curr;
        //     curr = 0;
        // }
        // return maxValue;
        int len = nums.size();
        vector<int> dp(len);
        int sum = 0;
        int init = 0;
        for(int i=0; i<len; ++i)
        {
            sum += nums[i];
            init += i*nums[i];
        }
        dp[0] = init;
        for(int i=1; i<len; ++i)
        {
            dp[i] = dp[i-1] + sum - len * nums[len-i]; 
        }
        return *max_element(dp.begin(), dp.end());
    }
};
