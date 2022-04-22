class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        if(len<1)   return s;
        string ret;
        int right = len-1, start = 0, end = right, left;
        while(start<len && end>=0)
        {
            
            if(s[end]!=' ' && s[start]!=' ')
                break;
            if(s[end]==' ')
                --end;
            if(s[start]==' ')
                ++start;
        }
        if(start>=len || end < 0) return "";
        right = end;
        left = right-1;
        while(right>=0)
        {
            if(s[right]==' ')
            {
                --right;
                left = right;
                continue;
            }
            if(left < start || s[left]==' ')
            {
                if(right!=end)
                {
                    ret.append(" ");
                }
                ret.append(s, left+1, right-left);
                right = left-1;
                left = right;
            }
            else
            {
                --left;
            }
        }
        return ret;
    }
};
