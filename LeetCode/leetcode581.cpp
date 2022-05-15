class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int ret, L=-1, R=-1;
        for(int i=0; i<len; ++i)
        {
            for(int j=i+1; j<len; ++j)
            {
                if(nums[i] > nums[j])
                {
                    L = i;
                    break;
                }
            }
            if(L==i)
                break;
        }
        for(int i=len-1; i>=0; --i)
        {
            for(int j=i-1; j>=0; --j)
            {
                if(nums[i] < nums[j])
                {
                    R = i;
                    break;
                }
            }
            if(R==i)
                break;
        }
        if(L==-1 || R==-1)
            return 0;
        return R-L+1;
    }
};
