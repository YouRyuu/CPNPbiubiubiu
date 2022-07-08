class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int L=0, R=len-1;
        vector<int> v;
        while(L<=R)
        {
            if(L==R)
            {
                v.push_back(nums[L]);
                break;
            }
            v.push_back(nums[L]);
            v.push_back(nums[R]);
            ++L;
            --R;
        }
        nums.swap(v);
    }
};
