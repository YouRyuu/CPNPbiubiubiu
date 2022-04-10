class Solution {
public:
    int integerReplacement(int n) {
        int ret = 0;
        while(n > 1)
        {
            if((n&1)==0)
            {
                n = n >> 1;
                ret += 1;
            }
            else if( n==3 )
            {
                n = 1;
                ret += 2;
            }
            else if((n&3)==3)
            {
                n = n/2 + 1;
                ret += 2;
            }
            else
            {
                n = n/2;
                ret += 2;
            }
        }
        return ret;
    }
};
