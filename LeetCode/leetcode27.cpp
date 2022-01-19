class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int left = 0, right = 0;
        while(right<size && left<size)
        {
            if(nums[left]!=val)
            {
                ++left;
                continue;
            }
           for(right=left+1;right<size;++right)
           {
               if(nums[right]!=val)
               {
                   int temp = nums[left];
                   nums[left] = nums[right];
                   nums[right] = temp;
                   ++left;
                   break;
               }
           }
        }
        return left;

    }
};
