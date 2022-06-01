class Solution {
public:
    int minJump(vector<int>& jump) {
        int len = jump.size();
        vector<int> dp(len);
        for(int i=len-1; i>=0; --i)
        {
            if(jump[i] + i>=len)
                dp[i] = 1;
            else
                dp[i] = dp[i+jump[i]] + 1;
            for(int j = i+1; j<len && dp[j]>=dp[i]+1; ++j)
                dp[j] = dp[i] + 1;
        }
        return dp[0];
    }
};
