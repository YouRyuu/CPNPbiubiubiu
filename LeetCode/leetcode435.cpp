class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if(a[0]<b[0])   return true;
        else if(a[0]==b[0]) return a[1]<b[1];
        return false;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int len = intervals.size();
        vector<int> dp(len);
        int preEnd = intervals[0][1];
        dp[0] = 0;
        for(int i=1; i<len; ++i)
        {
            if(intervals[i][0] >= preEnd)
            {
                dp[i] = dp[i-1];
                preEnd = intervals[i][1];
            }
            else
            {
                preEnd = min(preEnd, intervals[i][1]);
                dp[i] = dp[i-1] + 1;
            }
        }
        return dp[len-1];
    }
};
