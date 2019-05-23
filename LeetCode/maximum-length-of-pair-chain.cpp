class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b)
    {
        //if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int dp = 1, temp = pairs[0][1];
        for(int i=1;i<pairs.size();++i)
        {
            if(pairs[i][0]>temp)
            {
                temp = pairs[i][1];
                dp++;
            }
        }
        return dp;
    }
};