class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //先找出最大的索引 k 满足 nums[k] < nums[k+1]，如果不存在，就翻转整个数组；
        //再找出另一个最大索引 l 满足 nums[l] > nums[k]；
        //交换 nums[l] 和 nums[k]；
        //最后翻转 nums[k+1:]。
        int len = nums.size();
        int findex = -1, sindex = -1;
        for(int i=len-2; i>=0; --i)
        {
            if(nums[i]<nums[i+1])
            {
                findex = i;
                break;
            }
        }
        if(findex==-1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=len-1; i>=0; --i)
        {
            if(nums[i]>nums[findex])
            {
                sindex = i;
                break;
            }
        }
        int temp = nums[findex];
        nums[findex] = nums[sindex];
        nums[sindex] = temp;
        reverse(nums.begin()+findex+1, nums.end());
    }
};
