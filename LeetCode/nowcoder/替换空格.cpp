class Solution {
public:
	void replaceSpace(char *str,int length) {
        int strlength=0, newlength=0, blacklength=0;
        for(int i=0;str[i]!='\0';i++)
        {
            strlength++;
            if(str[i]==' ')
                blacklength++;
        }
        newlength = strlength + 2*blacklength;
        while(strlength>=0)
        {
            if(str[strlength]==' ')
            {
                str[newlength--] = '0';
                str[newlength--] = '2';
                str[newlength--] = '%';
            }
            else
                str[newlength--] = str[strlength];
            strlength--;
        }
	}
};
//https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking