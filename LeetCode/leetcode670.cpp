class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int len = s.size();
        for(int i=0; i<len-1; ++i)
        {
            char maxV = s[i];
            int index = 0;
            for(int j=i+1; j<len; ++j)
            {
                if(s[j] >= maxV)
                {
                    maxV = s[j];
                    index = j;
                }
            }
            if(s[i]!=maxV)
            {
                swap(s[i], s[index]);
                return stoi(s);
            }
        }
        return num;
    }
};
