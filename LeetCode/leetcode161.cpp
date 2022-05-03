class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if(abs(lens-lent)>1)
            return false;
        if((lens==0 && lent==1) || (lent==0 && lens==1))
            return true;
        bool flag = false;
        if(lens==lent)
        {
            for(int i=0; i<lens; ++i)
            {
                if(s[i]!=t[i])
                {
                    if(flag)
                        return false;
                    else
                        flag = true;
                }
            }
            return flag;
        }
        else
        {
            int i,j;
            for(i=0,j=0; i<lens&&j<lent ; ++i,++j)
            {
                if(s[i]!=t[j])
                {
                    if(flag)
                        return false;
                    else
                    {
                        if(lens < lent)
                        {
                            --i;
                            flag = true;
                        }
                        else
                        {
                            --j;
                            flag = true;
                        }
                    }
                }
            }
            if((i==lens || j==lent) && !flag)
                flag = true;
        }
        return flag;
    }
};
