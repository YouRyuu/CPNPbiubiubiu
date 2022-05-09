class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int L = 0, R = len-1;
        while(L<R)
        {
            int mid = (L + R)/2;
            if(nums[mid] < nums[R])
                R = mid;
            else
                L = mid+1;
        }
        return nums[L];
    }
};
