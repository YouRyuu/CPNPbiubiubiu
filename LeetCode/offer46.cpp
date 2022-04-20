class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int len = s.size();
        if(len<2)   return 1;
        vector<int> dp(len);
        dp[0] = 1;
        if(s[0]=='1')
            dp[1] = 2;
        else if(s[0]=='2' && s[1]<'6')
            dp[1] = 2;
        else
            dp[1] = 1;
        for(int i=2; i<len; ++i)
        {
            if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<'6'))
                dp[i] = dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[len-1];
    }
};
