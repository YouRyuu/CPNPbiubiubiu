class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        auto end=s.end(), start=s.begin();
        while((--end)!=start)
        {
            if(*end==' ' && count==0) //最后几个是空格，跳过
                continue;
            if(*end==' ' && count!=0)  //“   xxx”
                return count;
            if(*end!=' ')
            {
                count++;
            }
        }
        if(*end!=' ') count++;
       return count; 
    }
};
