class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxValue=INT_MIN, imax=1, imin=1;
        for(auto x:nums)
        {
            if(x<0)
            {
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            imax = max(imax*x,x);
            imin = min(imin*x,x);
            maxValue = max(imax, maxValue);
        }
        return maxValue;

    }
};
