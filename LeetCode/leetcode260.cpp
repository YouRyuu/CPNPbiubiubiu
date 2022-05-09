class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorn=0;
        for(int num:nums)
            xorn ^= num;
        int v = (xorn==INT_MIN?xorn:(xorn & -(xorn)));
        int v1=0, v2=0;
        for(int num:nums)
        {
            if(num & v)
                v1 ^= num;
            else
                v2 ^= num;
        }
        return {v1,v2};
    }
};

