class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int len = s.size();
        int i=0, j=0;
        while(i<len && j<len)
        {
            char c = s[j];
            if(c!=' ')
            {
                ++j;
            }
            else
            {
                reverse(s.begin()+i, s.begin()+j);
                j+=1;
                i=j;                
            }
        }
        reverse(s.begin()+i, s.begin()+j);
    }
};
