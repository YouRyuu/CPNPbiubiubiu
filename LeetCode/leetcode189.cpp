class Solution {
public:
    void reverse(vector<int>& nums, int left, int right)
    {
        while(left < right)
        {
            swap(nums[left], nums[right]);
            ++left;
            --right;
        }
    }

    void rotate(vector<int>& nums, int k) {
        // int len = nums.size();
        // vector<int> rt(len);
        // for(int i=0; i<len; ++i)
        // {
        //     rt[(i+k)%len] = nums[i];
        // }
        // nums.assign(rt.begin(), rt.end());
        int len = nums.size();
        k = k % len;
        reverse(nums, 0, len-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, len-1);
    }
};
