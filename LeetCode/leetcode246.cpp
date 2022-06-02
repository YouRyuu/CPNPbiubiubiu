class Solution {
public:

    bool is01689(char c)
    {
        if(c!='0' && c!='1' && c!='6' && c!='8' && c!='9')
            return false;
        return true;
    }

    bool is018(char c)
    {
        if(c!='0' && c!='1' && c!='8')
            return false;
        return true;
    }

    bool isStrobogrammatic(string num) {
        int len = num.size();
        int l = 0, r = len-1;
        while(l<=r)
        {
            if(!is01689(num[l]) || !is01689(num[r]))
                return false;
            if(num[l]==num[r])  //01698
            {
                if(is018(num[l]))   //018
                {
                    ++l;
                    --r;
                }
                else
                    return false;
            }
            else if((num[l]=='6' && num[r]=='9') || (num[l] = '9' && num[r] == '6'))        //69
            {
                ++l;
                --r;
            }
            else
                return false;
        }
        return true;
    }
};
