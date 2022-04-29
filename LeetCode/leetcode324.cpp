class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        int len = nums.size();
        int left = (len-1)/2;
        int right = len-1;
        for(int i=0; i<len-1; i+=2)
        {
            v.push_back(nums[left]);
            v.push_back(nums[right]);
            --left;
            --right;
        }
        if(len%2!=0)
            v.push_back(nums[left]);
        nums.assign(v.begin(), v.end());
    }
};
