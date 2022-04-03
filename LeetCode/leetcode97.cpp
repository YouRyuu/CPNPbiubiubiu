class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len3!=len1+len2) return false;
        //vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        //dp[0][0] = 1;
        vector<int> dp(len2+1, 0);
        dp[0] = 1;
        for(int i=0; i<=len1; ++i)
        {
            for(int j=0; j<=len2; ++j)
            {
                if(i>0)
                {
                    dp[j] &= s1[i-1]==s3[i+j-1];
                }
                if(j>0)
                {
                    dp[j] |= (dp[j-1] && s2[j-1]==s3[i+j-1]);
                }
            }
        }
        return dp[len2];
    }
};
