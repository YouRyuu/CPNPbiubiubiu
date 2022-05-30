class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ret;
        int len = security.size();
        vector<int> left(len,0);
        vector<int> right(len, 0);
        for(int i=1; i<len; ++i)
        {
            if(security[i]<=security[i-1])
                left[i] = left[i-1] + 1;
            if(security[len-i-1]<=security[len-i])
                right[len-i-1] = right[len-i]+1;
        }
        for(int i=time; i<len-time; ++i)
        {
            if(left[i]>=time && right[i]>=time)
                ret.push_back(i);
        }
        return ret;
    }
};

