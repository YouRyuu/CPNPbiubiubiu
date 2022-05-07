class Solution {
public:
    string convert(string s, int numRows) {
         string ret;
         int len = s.size();
         if(numRows==1)
            return s;
         int row = numRows;
         int col = (len / (2*row-2)) + 1;
         vector<vector<char>> v(row, vector<char>(0));
         for(int index=0; index<col; ++index)
         {
            for(int i=0; i<row; ++i)
            {
                int j = index*(2*row-2) + i;
                if(j<len)
                    v[i].push_back(s[j]);
                else
                    break;
            }
            for(int i=0; i<row-2; ++i)
            {
                int j=index*(2*row-2) + row+i;
                if(j<len)
                    v[row-2-i].push_back(s[j]);
                else
                    break;
            }
         }
        for(int i=0; i<row; ++i)
        {
            for(auto c : v[i])
                ret.push_back(c);
        }
        return ret;
    }
};
class Solution {
public:
    string convert(string s, int numRows) {
         string ret;
         int len = s.size();
         if(numRows==1)
            return s;
         int row = numRows;
         int col = 2*row-2;
         vector<vector<char>> v(row, vector<char>(0));
         for(int i=0, x=0; i<len; ++i)
         {
             v[x].push_back(s[i]);
             if(i%col < row-1)
                ++x;
            else
                --x;
         }
        for(int i=0; i<row; ++i)
        {
            for(auto c : v[i])
                ret.push_back(c);
        }
        return ret;
    }
};
