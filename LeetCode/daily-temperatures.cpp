class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>rt(T.size(),0);
        rt[T.size()-1] = 0;
        for(int i=T.size()-2;i>=0;--i)
        {
            for(int j=i+1;j<T.size();j+=rt[j])
            {
                if (T[i] < T[j]) {
                rt[i] = j - i;
                break;
            } else if (rt[j] == 0) {
                rt[i] = 0;
                break;
            }
            }
        }
        return rt;
    }
};
//https://leetcode-cn.com/problems/daily-temperatures