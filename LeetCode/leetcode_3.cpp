class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        x1x2...xm...xz
        设序列xp...xq中有一个字母xn与xq+1重复，记录下此时的长度len,下次计算的时候只需从xn+1开始即可,然后返回最大的len
        */
        if(s.size()<2)
            return s.size();
        int maxlen = 0;
        int currlen=0;      //记录当前不重复的串长度
        int dis;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i+1;j<s.size();j++)
            {
                dis=i;
                while(dis!=j)
                {
                    if(s[dis]!=s[j])
                    {
                        ++dis;
                    }
                    else
                    {
                        maxlen=maxlen>(j-i)?maxlen:(j-i);
                        i=dis+1;
                        ++dis;
                    }
                }
            if(j==s.size()-1)
            {
            /*不加这个if在处理“abcd“时会发生错误，输出0，但是这几行代码是我蒙出来的，没有推算为什么*/
                maxlen=maxlen>(j-i+1)?maxlen:(j-i+1);
            }
            }
            return maxlen;
        }
        return maxlen;
    }
};
