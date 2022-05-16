class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        int L=0,R=0;
        while(L<=R && R<len)
        {
            if((nums[L]==nums[R]) && (R-L>1))
            {
                int start = R;
                while(start <len && nums[start]==nums[R])
                    ++start;
                count = start-R;
                for(int i=R; i<len && start<len; ++i, ++start)
                    nums[i] = nums[start];
                L = R;
                len -= count;
            }
            else if(nums[L]==nums[R])
                ++R;
            else
                ++L;
        }
        return len;
    }
};
