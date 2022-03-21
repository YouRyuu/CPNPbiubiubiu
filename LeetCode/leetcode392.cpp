class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.size(), tlen = t.size();
        int i=0, j=0;
        while(i<slen && j<tlen)
        {
            if(s[i]==t[j])
                ++i;
            ++j;
        }
        return i==slen;
    }
};
