class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        int len = s.size();
        for(int i=0; i<len; ++i)
        {
            if(s[i]!=' ')
                ret+=s[i];
            else
                ret+="%20";
        }
        return ret;
    }
};
