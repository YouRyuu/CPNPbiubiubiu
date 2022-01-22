class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int most = 0;
        for(int i=0;i<size;++i)
        {
            if(i<=most)
            {
                most = max(most, i+nums[i]);
            }
            if(most>=(size-1)) return true;
        }
        return false;
        
    }
};
