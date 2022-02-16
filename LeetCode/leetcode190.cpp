class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int wox = 31;
        for(;n>0 && wox>=0;)
        {
            int val = n & 1;
            ret |= val << wox;
            --wox;
            n>>=1;
        }
        return ret;
        
    }
};
