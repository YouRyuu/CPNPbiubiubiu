class Solution {
public:
    int reverseBits(int num) {
        int maxlen = 0;
        int ins = 0;
        int cur = 0;
        for(int i=0; i<32; ++i)
        {
            if(num & 1<<i)
            {
               ++cur;
               ++ins ;
            }
            else
            {
                
                 ins = cur + 1;
                 cur = 0;
            }
            maxlen = max(maxlen, ins);
        }
        return maxlen;
    }
};
